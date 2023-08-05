/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 06:39:02 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/08/05 12:19:32 by mavardan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_vec	get_closest_point_from_line(t_vec a, t_vec b, t_vec p)
{
	t_vec	ap;
	t_vec	ab;
	double	ab2;
	double	ap_ab;
	double	t;

	ap = vec_sum(p, a);
	ab = vec_sum(b, a);
	ab2 = vec_dot_product(ab, ab);
	ap_ab = vec_dot_product(ap, ab);
	t = ap_ab / ab2;
	if (t < 0.0)
		t = 0.0;
	else if (t > 1.0)
		t = 1.0;
	return (vec_sum(a, vec_num_mul(ab, t)));
}

static void	calc(float *dist, float *x, float dist1, float x2)
{
	*dist = dist1;
	*x = x2;
}

static void	calc_cy_normal(float x2[2],  t_cylinder cylinder, \
	float dist1, float dist2)
{
	float	dist;
	float	x;

	if ((dist1 >= 0 && dist1 <= cylinder.hg && x2[0] > EPSILON)
		&& (dist2 >= 0 && dist2 <= cylinder.hg && x2[1] > EPSILON))
	{
		if (x2[0] < x2[1])
			calc(&dist, &x, dist1, x2[0]);
		else
		{
			dist = dist2;
			x = x2[1];
		}
	}
	else if (dist1 >= 0 && dist1 <= cylinder.hg && x2[0] > EPSILON)
		calc(&dist, &x, dist1, x2[0]);
	else
	{
		dist = dist2;
		x = x2[1];
	}
	x2[0] = x;
}

static int	solve_cylinder(float x[2], t_ray ray,  t_cylinder cylinder)
{
	t_vec 	v;
	t_vec 	u;
	float	a;
	float	b;
	float	c;

	v = vec_num_mul(cylinder.norm, vec_dot_product(ray.dir, cylinder.norm));
	v = vec_sub(ray.dir, v);
	u = vec_num_mul(cylinder.norm, vec_dot_product(vec_sub(ray.or, \
		cylinder.center), cylinder.norm));
	u = vec_sub(vec_sub(ray.or, cylinder.center), u);
	a = vec_dot_product(v, v);
	b = 2 * vec_dot_product(v, u);
	c = vec_dot_product(u, u) - pow(cylinder.rd, 2);
	x[0] = (-b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
	x[1] = (-b - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
	if (x[0] < EPSILON && x[1] < EPSILON)
		return (0);
	return (1);
}

float	cy_intersection(t_ray ray,  t_cylinder cylinder)
{
	float	x2[2];
	float	dist1;
	float	dist2;

	if (!solve_cylinder(x2, ray, cylinder))
		return (INFINITY);
	dist1 = vec_dot_product(cylinder.norm, vec_sub(vec_num_mul(ray.dir, x2[0]),
				vec_sub(cylinder.center, ray.or)));
	dist2 = vec_dot_product(cylinder.norm, vec_sub(vec_num_mul(ray.dir, x2[1]),
				vec_sub(cylinder.center, ray.or)));
	if (!((dist1 >= 0 && dist1 <= cylinder.hg && x2[0] > EPSILON)
			|| (dist2 >= 0 && dist2 <= cylinder.hg && x2[0] > EPSILON)))
		return (INFINITY);
	calc_cy_normal(x2, cylinder, dist1, dist2);
	return (x2[0]);
}

