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
	ray_mult(hit->phit, ray, hit->t); // TODO offff
	hit->nhit = vec_sub(&sp->center , hit->phit);
	vec_normalize(&hit->nhit);
	return (TRUE);
}