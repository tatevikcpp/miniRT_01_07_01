/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 06:05:34 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/08/05 06:06:02 by mavardan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void light_ray(t_light *light, t_ray *ray, t_hit *min_hit)
{
    ray->or = min_hit->phit;
    ray->dir = vec_sub(light->coords, min_hit->phit);
    ray->hit.t = vec_length(ray->dir);
    vec_normalize(&ray->dir);
    // ray->hit.phit = min_hit->phit;
    // ray->hit.nhit = min_hit->nhit;
}

static t_bool   is_in_shadow_sp(t_base *base, t_ray *ray)
{
    t_sphere *tmp;

    tmp = base->a_sphere;
    while (tmp)
    {
        if (sphere_intersect(ray, *tmp))
        {
            return(TRUE);
        }
        tmp = tmp->next;
    }
    return (FALSE);
}

static t_bool   is_in_shadow_pl(t_base *base, t_ray *ray)
{
    t_plane *tmp;
    t_hit *obj;
    float len;
    

    len = vec_length(vec_sub(ray->or, ray->hit.phit)) - 2 * EPSILON; // TODO eps?
    tmp = base->a_plane;
    obj = ft_calloc(sizeof(t_hit), 1);
    while (tmp)
    {
        if (plane_intersect(ray, tmp, obj))
        {
            if (obj->t < len)
                return(TRUE);
        }
        tmp = tmp->next;
    }
    return (FALSE);
}

// static t_bool   is_in_shadow_cy(t_base *base, t_ray *ray, t_vec vec)
// {
    // t_cylinder *tmp;
    // t_hit *obj;
    // float len;
    

    // len = vec_length(vec_sub(&ray->or, vec)) - 2 * EPSILON; // TODO eps?
    // tmp = base->a_cylinder;
    // obj = ft_calloc(sizeof(t_hit), 1);
    // while (tmp)
    // {
    //     if (cylinder_intersect(ray, tmp, obj)) // cheka der
    //     {
    //         if (obj->t < len)
    //             return(TRUE);
    //     }
    //     tmp = tmp->next;
    // }
    // return (FALSE);
// }

t_bool is_in_shadow(t_base *base, t_ray *ray)
{
    // if (is_in_shadow_sp || is_in_shadow_pl /*|| is_in_shadow_cy*/)
    if (is_in_shadow_sp(base, ray) || is_in_shadow_pl(base, ray) /*|| is_in_shadow_cy(base, ray, vec)*/)
        return (TRUE);
    return (FALSE);
}
