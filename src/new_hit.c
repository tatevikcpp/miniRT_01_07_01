/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_hit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 21:04:29 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/08/05 10:27:31 by mavardan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_hit	*new_hit(void)
{
	t_hit	*new;

	new = ft_calloc(sizeof(t_hit), 1);
	new->obj_type = id_null;
	new->t = INFINITY;
	return (new);
}

t_hit	*hit_dup(t_hit *hit)
{
	t_hit	*new;

	new = ft_calloc(sizeof(t_hit), 1);
	new->t = INFINITY;
	new->nhit = hit->nhit;
	new->phit = hit->phit;
	new->color = hit->color;
	new->obj = hit->obj;
	new->obj_type = hit->obj_type;
	return (new);
}

// t_vec *vec_dup(t_vec vec)
// {
//     t_vec *new_vec;

//     new_vec = ft_calloc(sizeof(t_vec), 1);
//     new_vec->x = vec->x;
//     new_vec->y = vec->y;
//     new_vec->z = vec->z;
//     return (new_vec);
// }
