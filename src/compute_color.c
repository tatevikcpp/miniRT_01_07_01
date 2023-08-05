/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 06:06:25 by mavardan          #+#    #+#             */
/*   Updated: 2023/08/05 13:37:35 by mavardan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/struct.h"
#include "../includes/defines.h"
#include "../includes/minirt.h"

t_rgb	*compute_color_with_amb(t_rgb *p_col, t_rgb *amb_col)
{
	p_col->r = max(-255 + p_col->r + amb_col->r, 0);
	p_col->g = max(-255 + p_col->g + amb_col->g, 0);
	p_col->b = max(-255 + p_col->b + amb_col->b, 0);
	return (p_col);
}

t_rgb	*compute_color(t_base *base, t_rgb *p_col, t_hit *hit) // TODO piti vor
{
	float	sum_ratio;
	float	cosa;
	t_vec	light_ray;

	// t_rgb *tmp;
	// tmp = p_col;
	light_ray = vec_sub(base->a_light->coords, hit->phit);
	// printf("light_ray = %ld\n", light_ray);
	cosa = vec_dot_product(light_ray, hit->nhit) / vec_length(light_ray);
	if (cosa <= 0)
		cosa = 0;
	sum_ratio = ALBEDO + base->a_light->brigh * cosa;
	p_col = mul_rgb(p_col, sum_ratio);
	// free(tmp);
	compute_color_with_amb(p_col, &base->a_amb->rgb);
	return (p_col);
}
