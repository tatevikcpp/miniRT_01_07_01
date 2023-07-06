/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaghazar <vaghazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 17:50:18 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/07/06 18:33:05 by vaghazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void struct_tree(t_base *obj)
{
    // printf("obj->amb->rgb->r = %d\n", obj->a_amb->rgb->r);
    // printf("obj->a_sphere->sphere_diameter = %f\n", obj->a_sphere->sphere_diameter);
    
    while (obj->a_cylinder)
    {
        printf("obj->a_cylin    der->cy_diameter, %f\n", obj->a_cylinder->cy_diameter);
        obj->a_cylinder = obj->a_cylinder->next;
    }
    // printf("plane->r = %d\n", obj->a_plane->rgb->r);
}