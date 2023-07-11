/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lists.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaghazar <vaghazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 11:34:18 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/07/06 18:38:53 by vaghazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void    print_list_pl(t_plane *obj)
{
    t_plane *tmp;
    
    tmp = obj;
    while (tmp)
    {
        printf("pl_1 r = %d\n", tmp->rgb.r);
        if (!tmp->next)
            return ;
        tmp = tmp->next;
    }
}

void    print_list_cy(t_cylinder *obj)
{
    t_cylinder *tmp;
    
    tmp = obj;
    while (tmp)
    {
        printf("cy_diameter r = %f\n", tmp->dm);
        if (!tmp->next)
            return ;
        tmp = tmp->next;
    }
}

void    print_list_sp(t_sphere *obj)
{
    t_sphere *tmp;
    
    tmp = obj;
    while (tmp)
    {
        printf("sp_1 r = %d\n", tmp->rgb.r);
        if (!tmp->next)
            return ;
        tmp = tmp->next;
    }
}