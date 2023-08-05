#include "minirt.h"

int	solve_quadratic( t_vec point, float *x0, float *x1)
{
	float	discr;
	float	q;

	discr = point.y * point.y - 4 * point.x * point.z;
	if (discr < 0)
		return (0);
	else if (discr == 0)
	{
		*x0 = -0.5 * point.y / point.x;
		*x1 = -0.5 * point.y / point.x;
	}
	else
	{
		if (point.y > 0)
			q = -0.5 * (point.y + sqrt(discr));
		else
			q = -0.5 * (point.y - sqrt(discr));
		*x0 = q / point.x;
		*x1 = point.z / q;
	}
	if (*x0 > *x1)
		swap(x0, x1);
	return (1);
}

int	sphere_intersect(t_ray *ray,  t_sphere sphere)
{
	float	x0;
	float	x1;
	t_vec	vect;
	
	vect = vec_sub(ray->or, sphere.center);
	if (!solve_quadratic(new_vec(vec_dot_product(ray->dir, ray->dir),
				2 * vec_dot_product(ray->dir, vect),
				vec_dot_product(vect, vect) - sphere.r2), &x0, &x1))
		return (0);
	if ((x0 < 0 && x1 < 0) || (x0 > ray->hit.t && x1 > ray->hit.t))
		return (0);
	else if (x0 <= 0.)
		x0 = x1;
	else if (x1 <= 0.)
		x1 = x0;
	ray->hit.t = min(x0, x1);
	ray->hit.phit = vec_sum(ray->or, vec_num_mul(ray->dir, x1));
	ray->hit.nhit = vec_sub(ray->hit.phit, sphere.center);
	vec_normalize(&ray->hit.nhit);
	ray->hit.phit = vec_sum(ray->hit.phit, vec_num_mul(ray->hit.nhit, EPSILON));
	ray->hit.color = sphere.rgb;
	return (1);
}

t_bool	plane_intersect(t_ray *ray, t_plane *pl, t_hit *hit)
{
	float	denom;
	t_vec 	tmp;
	float 	t;

	denom = vec_dot_product(pl->norm , ray->dir);
	if (fabs(denom) < EPSILON)
		return (FALSE);
	tmp = vec_sub(pl->coord, ray->or);
	t = vec_dot_product(tmp, pl->norm) / denom;
	if (hit->t < EPSILON)
		return (FALSE);
	hit->phit = new_vec(0, 0, 0);
	hit->t = t;
	ray_mult(&hit->phit, ray, hit->t);
	hit->nhit = pl->norm;
	hit->obj_type = id_plane;
	hit->obj = (void *)pl;
	hit->color = pl->rgb;;
	// if (vec_dot_product(hit->nhit, &ray->dir) > 0) //TODO chgitem ?
	// 	hit->nhit = vec_inv(hit->nhit);
	return (TRUE);
}

static t_bool	infinite_cyl_intersect(t_ray *ray, t_cylinder *cy, t_hit *hit)
{
	t_quadratic	q;
	t_vec		u;
	t_vec		v;


	u = cross_product(ray->dir, cy->norm);
	v = vec_sub(cy->center, ray->or);
	v = cross_product(v, cy->norm);
	q.a = vec_dot_product(u, u);
	q.b = 2 * vec_dot_product(u, v);
	q.c = vec_dot_product(v, v) - cy->rd;
	if (!quadratic_eq_solution(&q) || (q.x2 <= EPSILON && q.x1 <= EPSILON))
		return (FALSE);
	if (q.x1 <= EPSILON || (q.x2 > EPSILON && (q.x2 < q.x1)))
		q.x1 = q.x2;
	hit->t = q.x1;
	ray_mult(&hit->phit, ray, q.x1);
	v = vec_sub(cy->center, hit->phit);
	hit->nhit = cross_product(v, cy->norm);
	hit->nhit = cross_product(hit->nhit, cy->norm);
	vec_normalize(&hit->nhit);
	if (vec_dot_product(hit->nhit, ray->dir))
		hit->nhit = vec_inv(hit->nhit);
	return (TRUE);
}

t_bool	cylinder_intersect(t_ray *ray, t_cylinder *cy)
{
	t_plane	pl;
	t_hit	tmp_hit;

	pl.coord = cy->p1;
	pl.norm = cy->norm;
	if (plane_intersect(ray, &pl, &tmp_hit)
		&& vec_length(vec_sub(tmp_hit.phit, cy->p1))
		<= cy->dm * 0.5 && ray->hit.t > tmp_hit.t)
		ray->hit = tmp_hit;
	pl.coord = cy->p2;
	if (plane_intersect(ray, &pl, &tmp_hit)
		&& vec_length(vec_sub(tmp_hit.phit, cy->p2)) <= cy->dm * 0.5
		&& ray->hit.t > tmp_hit.t)
		ray->hit = tmp_hit;
	if (infinite_cyl_intersect(ray, cy, &tmp_hit)
		&& pow(vec_length(vec_sub(cy->center, tmp_hit.phit)), 2)
		<= pow(cy->hg * 0.5, 2) + cy->rd
		&& ray->hit.t > tmp_hit.t)
		ray->hit = tmp_hit;
	return (ray->hit.t < INFINITY && ray->hit.t > EPSILON);
}