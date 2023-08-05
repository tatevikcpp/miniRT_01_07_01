/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 09:57:27 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/08/05 10:11:08 by mavardan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "minirt.h"

void	cylinder_norm(t_cylinder *cy)
{
	vec_normalize(&cy->norm);
	cy->rd = cy->dm * cy->dm * 0.25;
	// cy->delta_p = vect_mul(cy->orient, cy->height);
	// cy->p1 = veHct_mul(cy->orient, -0.5 * cy->height);
	// cy->p1 = vect_add(cy->p1, cy->coords);
	// cy->p2 = vect_mul(cy->orient, 0.5 * cy->height);
	// cy->p2 = vect_add(cy->p2, cy->coords);
}

void	function(t_rt *rt)
{
	t_camera	*cam;
	float		pi;
	// t_utils *obj; // malloc

	cam = rt->cam;
	pi = acos(-1);
	// printf("cam->cam->fov = %f\n", cam->fov);
	cam->scale = tan(cam->fov / 2 * pi / 180);
	// printf("cam->scale = %f\n", cam->scale);
	// look_at(rt);
	// obj = rt->utils;
	// while (obj) 
	// {
	//     //image_param();
	//     // if (obj->id == id_sphere)
	//         // obj->objects.sphere.rd = pow(obj->objects.sphere.dm / 2, 2);
	//     // if (obj->id == id_cylinder)
	//         // cylinder_norm(&obj->objects.cylinder);
	//     //FUNC
	//     obj = obj->next;
	// }
}
