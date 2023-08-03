#include "minirt.h"


static t_hit    *get_closest_sp(t_base *base, t_ray *ray)
{
    t_sphere *tmp;
    t_hit *min_obj;
    float min_len;
    float len;
    

    min_len = 0;
    tmp = base->a_sphere;
    min_obj = ft_calloc(sizeof(t_hit), 1);
    while (tmp)
    {
        if (sphere_intersect(ray, tmp, min_obj))
        {
            len = vec_length(vec_sub(min_obj->phit, &base->a_light->coords));
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


static t_hit    *get_closest_pl(t_base *base, t_ray *ray)
{
    t_plane *tmp;
    t_hit *min_obj;
    float min_len;
    float len;
    

    min_len = 0;
    min_obj = ft_calloc(sizeof(t_hit), 1);
    tmp = base->a_plane;
    while (tmp)
    {
        if (plane_intersect(ray, tmp, min_obj))
        {
            len = vec_length(vec_sub(min_obj->phit, &base->a_light->coords));
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

static t_hit    *get_closest_cy(t_base *base, t_ray *ray)
{
//     t_cylinder *tmp;
    t_hit *min_obj;
//     float min_len;
//     float len;
    

//     min_len = 0;
//     min_obj = ft_calloc(sizeof(t_hit), 1);
//     tmp = base->a_cylinder;
//     while (tmp)
//     {
//         if (cylinder_intersect(ray, tmp, min_obj))
//         {
//             len = vec_length(vec_sub(min_obj->phit, &base->a_light->coords));
//             if (len < min_len)
//             {
//                 min_len = len;
//                 min_obj->obj = (void *)tmp;
//             }
//         }
//         tmp = tmp->next;
//     }
    return (min_obj);
}

t_hit *get_closest_obj(t_base *data, t_ray *ray)
{
    t_hit *obj;
    t_hit *tmp;
    t_hit *obj_min;

    obj_min = get_closest_sp(data, &data->utils->ray);
    // obj = get_closest_pl(data, &data->utils->ray);
    // tmp = obj;
    // if (obj->t < obj_min->t)
    // {
    //     tmp = obj_min;
    //     obj_min = obj;
    // }
    // print_vec(tmp->phit);
    // free_hit(tmp);
    // obj = get_closest_cy(data, &data->utils->ray);
    // tmp = obj;
    // if (obj->t < obj_min->t)
    // {
    //     tmp = obj_min;
    //     obj_min = obj;
    // }
    // free_hit(tmp);
    return (obj_min);
}