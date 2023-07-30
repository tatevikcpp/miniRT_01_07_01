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
	// printf("tca = %f\n", tca);
	if (tca < 0)
		return (FALSE);
	d2 = vec_dot_product(l, l) - tca * tca;
	// printf("d2 = %f\n", d2);
	// printf("sp->r2 = %f\n", sp->r2);
	if (d2 > sp->r2)
		return (FALSE);
	thc = sqrt(sp->r2 - d2);
	hit->t = tca - thc;
	t2 = tca + thc;
	if (hit->t < EPSILON && t2 < EPSILON)
		return (FALSE);
	if (hit->t < EPSILON || t2 < hit->t)
		hit->t = t2;
	hit->phit = ray_mult(hit->phit, ray, hit->t); // TODO offff
	hit->nhit = vec_sub(&sp->center , hit->phit);
	// printf("hit->nhit = %p", hit->nhit);
	vec_normalize(hit->nhit);
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
	hit->t = vec_dot_product(tmp, &pl->norm ) / denom;
	if (hit->t < EPSILON)
		return (FALSE);
	ray_mult(hit->phit, ray, hit->t);
	hit->nhit = &pl->norm;
	// if (vec_dot_product(hit->nhit, &ray->dir) > 0) //chgitem ?
	// 	hit->nhit = vec_inv(hit->nhit);
	return (TRUE);
}

// int	intersect(t_ray *ray, t_utils *obj, t_hit *hit)
// {
// 	if (obj->id == id_sphere) // ? obj->id
// 		return(sphere_intersect(/*la, la, la*/));
// 	if (obj->id == id_plane)
// 		return (plane_intersect(/*la, la, la*/));
// }