/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_hit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 21:04:29 by tkhechoy          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/08/05 10:09:41 by mavardan         ###   ########.fr       */
=======
/*   Updated: 2023/08/05 08:22:17 by tkhechoy         ###   ########.fr       */
>>>>>>> ddf3a0766a22efb2c079fff1b0d903351951194d
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

<<<<<<< HEAD
	new = ft_calloc(sizeof(t_hit), 1);
	new->t = INFINITY;
	new->nhit = hit->nhit;
=======
    new = ft_calloc(sizeof(t_hit), 1);
	new->t = hit->t;
   	new->nhit = hit->nhit;
>>>>>>> ddf3a0766a22efb2c079fff1b0d903351951194d
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
