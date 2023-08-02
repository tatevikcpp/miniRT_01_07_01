#include "minirt.h"


t_hit    *get_closest_sp(t_base *base, t_hit *hit, t_ray *ray)
{
    t_sphere *tmp;
    t_hit *min_obj;
    float min_len;
    float len;
    

    min_len = 0;
    min_obj = NULL;
    tmp = base->a_sphere;
    while (tmp)
    {
        if (sphere_intersect(ray, tmp, hit))
        {
            len = vec_length(vec_sub(hit->phit, &base->a_light->coords));
            if (len < min_len)
            {
                min_len = len;
                min_obj->obj = (void *)tmp;
            }
        }
        tmp = tmp->next;
    }
    return (min_obj);
}


t_hit    *get_closest_pl(t_base *base, t_hit *hit, t_ray *ray)
{
    t_plane *tmp;
    t_hit *min_obj;
    float min_len;
    float len;
    

    min_len = 0;
    min_obj = NULL;
    tmp = base->a_plane;
    while (tmp)
    {
        if (plane_intersect(ray, tmp, hit))
        {
            len = vec_length(vec_sub(hit->phit, &base->a_light->coords));
            if (len < min_len)
            {
                min_len = len;
                min_obj->obj = (void *)tmp;
            }
        }
        tmp = tmp->next;
    }
    return (min_obj);
}

// t_hit    *get_closest_cy(t_base *base, t_hit *hit, t_ray *ray)
// {
//     t_cylinder *tmp;
//     t_hit *min_obj;
//     float min_len;
//     float len;
    

//     min_len = 0;
//     min_obj = NULL;
//     tmp = base->a_cylinder;
//     while (tmp)
//     {
//         if (cylinder_intersect(ray, tmp, hit))
//         {
//             len = vec_length(vec_sub(hit->phit, &base->a_light->coords));
//             if (len < min_len)
//             {
//                 min_len = len;
//                 min_obj->obj = (void *)tmp;
//             }
//         }
//         tmp = tmp->next;
//     }
//     return (min_obj);
// }