/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 17:50:18 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/08/05 09:43:56 by mavardan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	struct_tree(t_base *obj)
{
	t_sphere	*tmp;

	tmp = obj->a_sphere;
	while (obj->a_cylinder)
	{
		printf("der->cy_diameter, %f\n", obj->a_cylinder->dm);
		obj->a_cylinder = obj->a_cylinder->next;
	}
	while (obj->a_plane)
	{
		printf("obj->a_plane, %f\n", obj->a_plane->coord.x);
		obj->a_plane = obj->a_plane->next;
	}
	while (obj->a_sphere)
	{
		printf("obj->a_sphere, %f\n", obj->a_sphere->dm);
		obj->a_sphere = obj->a_sphere->next;
	}
	while (tmp)
	{
		printf("obj->a_RRR, %d\n", tmp->rgb.r);
		tmp = tmp->next;
	}
}
