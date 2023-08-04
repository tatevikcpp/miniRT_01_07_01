#include "minirt.h"

void light_ray(t_light *light, t_ray *ray, t_hit *min_hit)
{
    ray->or = light->coords;
    ray->dir = light->coords;
    vec_normalize(&ray->dir);
    // ray->hit = *min_hit;
    ray->hit.phit = min_hit->phit;
    ray->hit.t = min_hit->t;
    ray->hit.nhit = min_hit->nhit;
}

static t_bool   is_in_shadow_sp(t_base *base, t_ray *ray, t_vec *vec)
{
    t_sphere *tmp;
    t_hit *obj;
    float len;
    

    len = vec_length(vec_sub(&ray->or, vec));// - EPSILON; // TODO eps?
    tmp = base->a_sphere;
    obj = ft_calloc(sizeof(t_hit), 1);
    while (tmp)
    {
        if (sphere_intersect(ray, tmp, obj))
        {
            if (obj->t < len)
                return(TRUE);
        }
        tmp = tmp->next;
    }
    return (FALSE);
}

static t_bool   is_in_shadow_pl(t_base *base, t_ray *ray, t_vec *vec)
{
    t_plane *tmp;
    t_hit *obj;
    float len;
    

    len = vec_length(vec_sub(&ray->or, vec)) - 2 * EPSILON; // TODO eps?
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

static t_bool   is_in_shadow_cy(t_base *base, t_ray *ray, t_vec *vec)
{
    t_cylinder *tmp;
    t_hit *obj;
    float len;
    

    len = vec_length(vec_sub(&ray->or, vec)) - 2 * EPSILON; // TODO eps?
    tmp = base->a_cylinder;
    obj = ft_calloc(sizeof(t_hit), 1);
    while (tmp)
    {
        if (cylinder_intersect(ray, tmp, obj)) // cheka der
        {
            if (obj->t < len)
                return(TRUE);
        }
        tmp = tmp->next;
    }
    return (FALSE);
}

t_bool is_in_shadow(t_base *base, t_ray *ray, t_vec *vec)
{
    // if (is_in_shadow_sp || is_in_shadow_pl /*|| is_in_shadow_cy*/)
    if (is_in_shadow_sp(base, ray, vec) || is_in_shadow_pl(base, ray, vec) /*|| is_in_shadow_cy(base, ray, vec)*/)
        return (TRUE);
    return (FALSE);
}