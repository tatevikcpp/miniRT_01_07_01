/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 06:38:58 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/08/05 09:15:04 by tkhechoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../includes/minirt.h"

float	distance(t_vec p, t_vec q)
{
	return (sqrt(pow(q.x - p.x, 2) + pow(q.y - p.y, 2) + pow(q.z - p.z, 2)));
}


float	solve_plane(t_vec o, t_vec d, t_vec plane_p, t_vec plane_nv)
{
	float	x;
	float	denom;

	denom = vec_dot_product(plane_nv, d);
	if (denom == 0)
		return (INFINITY);
	x = (vec_dot_product(plane_nv, vec_sub(plane_p, o))) / denom;
	if (x > EPSILON)
		return (x);
	return (INFINITY);
}

static t_vec	caps_int(t_ray ray,  t_cylinder cylinder, \
	float *id1, float *id2)
{
	t_vec	c2;

	c2 = vec_sum(cylinder.center, vec_num_mul(cylinder.norm, cylinder.hg)); // TODO free
	*id1 = solve_plane(ray.or, ray.dir, cylinder.center, cylinder.norm);
	*id2 = solve_plane(ray.or, ray.dir, c2, cylinder.norm);
	return (c2);
}

static float	caps_intersection(t_ray ray,  t_cylinder cylinder)
{
	float	id1;
	float	id2;
	t_vec	ip1;
	t_vec	ip2;
	t_vec	c2;

	c2 = caps_int(ray, cylinder, &id1, &id2);
	if (id1 < INFINITY || id2 < INFINITY)
	{
		ip1 = vec_sum(ray.or, vec_num_mul(ray.dir, id1));
		ip2 = vec_sum(ray.or, vec_num_mul(ray.dir, id2));
		if ((id1 < INFINITY && distance(ip1, cylinder.center) <= cylinder.rd)
			&& (id2 < INFINITY && distance(ip2, c2) <= cylinder.rd))
		{
			if (id1 < id2)
				return (id1);
			return (id2);
		}
		else if (id1 < INFINITY && distance(ip1, cylinder.center)
			<= cylinder.rd)
			return (id1);
		else if (id2 < INFINITY && distance(ip2, c2) <= cylinder.rd)
			return (id2);
	}
	return (INFINITY);
}

static float	cylinder_intersection( t_ray ray, \
	 t_cylinder cylinder, int *is_on_side)
{
	float	cylinder_inter;
	float	caps_inter;

	*is_on_side = 0;
	cylinder_inter = cy_intersection(ray, cylinder);
	if (!cylinder.is_closed)
		caps_inter = INFINITY;
	else
		caps_inter = caps_intersection(ray, cylinder);
	if (cylinder_inter < INFINITY || caps_inter < INFINITY)
	{
		if (cylinder_inter < caps_inter)
		{
			*is_on_side = 1;
			return (cylinder_inter);
		}
		return (caps_inter);
	}
	return (INFINITY);
}

t_hit	*ray_cylinders( t_ray ray, t_base *base, \
	t_hit *hit)
{
	t_hit *result = NULL;
	t_cylinder	*cylinder;
	float		tmp;
	int			is_on_side;

	cylinder = base->a_cylinder;
	while (cylinder)
	{
		tmp = cylinder_intersection(ray, *cylinder, &is_on_side);
		if (tmp < hit->t && tmp > 0)
		{
			printf("tmp = %f\n", tmp);
			hit->obj = cylinder;
			hit->t = tmp;
			hit->phit = new_vec(tmp * ray.dir.x, tmp * ray.dir.y,
					tmp * ray.dir.z);
			hit->nhit = cylinder->norm;
			if (is_on_side)
				hit->nhit = vec_sub(get_closest_point_from_line(\
					cylinder->center, cylinder->p2, hit->phit), hit->phit);
			vec_normalize(&hit->nhit);
			hit->obj_type = id_cylinder;
			result = hit_dup(hit);
		}
		cylinder = cylinder->next;
	}
	return (result);
}
