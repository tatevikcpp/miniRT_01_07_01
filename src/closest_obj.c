#include "minirt.h"


static void get_closest_sp(t_base *base, t_ray *ray)
{
    t_sphere *tmp;
    float min_len;
    // float len;

    min_len = INFINITY;
    tmp = base->a_sphere;
    while (tmp)
    {
        if (sphere_intersect(ray, tmp))
        {
            // len = vec_length(vec_sub(min_obj->phit, &base->a_light->coords));
            // len = vec_length(vec_sub(min_obj->phit, &ray->or));
            // printf("min_len = %f\n", min_len);
            // printf(" min_obj->t = %f\n",  ray->hit.t);
            if (min_len > ray->hit.t)
            {
                // printf("")
                min_len = ray->hit.t;
                ray->hit.obj = (void *)tmp;
                ray->hit.obj_type = id_sphere;
            }
        }
        tmp = tmp->next;
    }
}


// static t_hit    *get_closest_pl(t_base *base, t_ray *ray)
// {
//     t_plane *tmp;
//     t_hit *min_obj; 
//     float min_len;
//     float len;
    

//     min_len = 0;
//     min_obj = ft_calloc(sizeof(t_hit), 1);
//     tmp = base->a_plane;
//     while (tmp)
//     {
//         if (plane_intersect(ray, tmp, min_obj))
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
//     return (min_obj);
// }

// static t_hit    *get_closest_cy(t_base *base, t_ray *ray)
// {
//     t_cylinder *tmp;
//     t_hit *min_obj;
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
//             {*
//                 min_len = len;
//                 min_obj->obj = (void *)tmp;
//             }
//         }
//         tmp = tmp->next;
//     }
//     return (min_obj);
// }

void get_closest_obj(t_base *data /*, t_ray *ray*/)
{
    // t_hit *obj;
    // t_hit *tmp;
    t_hit *tmp;


    get_closest_sp(data, &data->utils->ray);
    // set_vec(&from_light->or, data->a_light->coords.x, data->a_light->coords.y, data->a_light->coords.z);
    // from_light.dir = *vec_normalize(vec_sub(obj_min->phit, &from_light.or));
    // set_vec(&from_light.dir, data->a_light->coords.x, data->a_light->coords.y, data->a_light->coords.z);
    // if (sphere_intersect(from_light, data->a_sphere, tmp))
        ;
    // printf("r = %d\n", obj_min->color.r);
    // printf("g = %d\n", obj_min->color.g);
    // printf("b = %d\n", obj_min->color.b);

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
}