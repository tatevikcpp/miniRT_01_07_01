#include "minirt.h"

static t_bool	sphere_intersect(t_ray *ray, t_sphere *sp, t_hit *hit)
{
	t_vec	*l;
	float	tca;
	float	thc;
	float	d2;
	float	t2;

	l = vec_sub(&ray->or, &sp->center);
	tca = vec_dot_product(l, &ray->dir);
	if (tca < 0)
		return (FALSE);
	d2 = vec_dot_product(l, l) - tca * tca;
	if (d2 > sp->r2)
		return (FALSE);
	thc = sqrt(sp->r2 - d2);
	hit->t = tca - thc;
	t2 = tca + thc;
	if (hit->t < EPSILON && t2 < EPSILON)
		return (FALSE);
	if (hit->t < EPSILON || t2 < hit->t)
		hit->t = t2;
	hit->phit = new_vec(0, 0, 0);
	ray_mult(hit->phit, ray, hit->t); // TODO offff
	hit->nhit = vec_normalize(vec_sub(&sp->center , hit->phit));
	hit->obj_type = id_sphere;
	hit->obj = (void *)sp;
	hit->color = sp->rgb;
	return (TRUE);
}

t_bool	plane_intersect(t_ray *ray, t_plane *pl, t_hit *hit)
{
	float	denom;
	t_vec	*tmp;

	denom = vec_dot_product(&pl->norm , &ray->dir);
	if (denom == 0)
		return (FALSE);
	tmp = vec_sub(&ray->or, &pl->coord);
	hit->t = vec_dot_product(tmp, &pl->norm) / denom;
	if (hit->t < EPSILON)
		return (FALSE);
	hit->phit = new_vec(0, 0, 0);
	ray_mult(hit->phit, ray, hit->t);
	hit->nhit = &pl->norm;
	hit->obj_type = id_plane;
	hit->obj = (void *)pl;
	// if (vec_dot_product(hit->nhit, &ray->dir) > 0) //TODO chgitem ?
	// 	hit->nhit = vec_inv(hit->nhit);
	return (TRUE);
}

t_bool	infinite_cyl_intersect(t_ray *r, t_cylinder *cy, t_hit *hit)
{
	t_quadratic	q;
	t_vec		*u;
	t_vec		*v;


	u = cross_product(&r->dir, &cy->norm);
	v = vec_sub(&cy->center, &r->or);
	v = cross_product(v, &cy->norm);
	q.a = vec_dot_product(u, u);
	q.b = 2 * vec_dot_product(u, v);
	q.c = vec_dot_product(v, v) - cy->rd;
	if (!quadratic_eq_solution(&q) || (q.x2 <= EPSILON && q.x1 <= EPSILON))
		return (FALSE);
	if (q.x1 <= EPSILON || (q.x2 > EPSILON && (q.x2 < q.x1)))
		q.x1 = q.x2;
	hit->t = q.x1;
	ray_mult(hit->phit, r, q.x1);
	v = vec_sub(&cy->center, hit->phit);
	hit->nhit = cross_product(v, &cy->norm);
	hit->nhit = cross_product(hit->nhit, &cy->norm);
	vec_normalize(hit->nhit);
	if (vec_dot_product(hit->nhit, &r->dir))
		hit->nhit = vec_inv(hit->nhit);
	return (TRUE);
}

t_bool	cylinder_intersect(t_ray *r, t_cylinder *cy, t_hit *hit)
{
	t_plane	pl;
	t_hit	tmp_hit;

	hit->t = INFINITY;
	pl.coord = cy->p1;
	pl.norm = cy->norm;
	if (plane_intersect(r, &pl, &tmp_hit)
		&& vec_length(vec_sub(tmp_hit.phit, &cy->p1))
		<= cy->dm * 0.5 && hit->t > tmp_hit.t)
		*hit = tmp_hit;
	pl.coord = cy->p2;
	if (plane_intersect(r, &pl, &tmp_hit)
		&& vec_length(vec_sub(tmp_hit.phit, &cy->p2)) <= cy->dm * 0.5
		&& hit->t > tmp_hit.t)
		*hit = tmp_hit;
	if (infinite_cyl_intersect(r, cy, &tmp_hit)
		&& pow(vec_length(vec_sub(&cy->center, tmp_hit.phit)), 2)
		<= pow(cy->hg * 0.5, 2) + cy->rd
		&& hit->t > tmp_hit.t)
		hit = &tmp_hit;
	return (hit->t < INFINITY && hit->t > EPSILON);
}