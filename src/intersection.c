#include "minirt.h"

t_bool	sphere_intersect(t_ray *ray, t_sphere *sp, t_hit *hit)
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
	hit->phit = ray_mult(hit->phit, ray, hit->t); // TODO offff
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
	//print_vec("-------------in plane_intersect pl->norm-------------", &pl->norm);
	hit->t = vec_dot_product(tmp, &pl->norm) / denom;
	//printf("ok\n");
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


