/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_ray.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 22:22:28 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/08/05 09:41:29 by mavardan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray	*new_ray(void)
{
	return (ft_calloc(sizeof(t_ray), 1));
}

t_ray	*ray_dup(t_ray *ray)
{
	t_ray	*new_ray;

	new_ray = ft_calloc(sizeof(t_ray), 1);
	new_ray->or = ray->or;
	new_ray->dir = ray->dir;
	new_ray->hit = ray->hit;
	return (new_ray);
}
