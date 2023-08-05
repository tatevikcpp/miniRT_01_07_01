#include "minirt.h"



static t_hit *get_closest_sp(t_base *base, t_ray *ray, t_hit *final_hit)
{
    t_sphere *tmp;
    t_hit   *result;

    result = NULL;
    tmp = base->a_sphere;
    // ray->hit.t = INFINITY;
    while (tmp)
    {
            // printf("ray->hit.t = %f\n\n, ray->hit.t", ray->hit.t);
        if (sphere_intersect(ray, *tmp))
        {
            // printf("sphere_intersect\n");
            ray->hit.obj = (void *)tmp;
            ray->hit.obj_type = id_sphere;
            // free(*final_hit);
            // if (ray->hit.t < (*final_hit).t)
            // {
            // base->utils->hit = hit_dup(&ray->hit);
                // *final_hit = ray->hit;
            result = hit_dup(&ray->hit); // TODO free
        }
        tmp = tmp->next;
    }
    return (result);
}

static t_hit *get_closest_cy(t_base *base, t_ray *ray, t_hit *final_hit)
{
    t_cylinder *tmp;
    t_hit   *result;

    result = NULL;
    tmp = base->a_cylinder;
    while (tmp)
    {
        if (cylinder_intersect(ray, tmp))
        {
            printf("cylinder_intersect\n");
            ray->hit.obj = (void *)tmp;
            ray->hit.obj_type = id_cylinder;
            // free(*final_hit);
            // *final_hit = hit_dup(&ray->hit);
            // if (ray->hit.t < (*final_hit).t)
            //     *final_hit = ray->hit;
            result = hit_dup(&ray->hit); // TODO free
        }
        tmp = tmp->next;
    }
    return (result);
}

static t_hit *get_closest_pl(t_base *base, t_ray *ray, t_hit *final_hit)
{
    t_plane *tmp;

    tmp = base->a_plane;
    while (tmp)
    {
        if (plane_intersect(ray, tmp, &ray->hit))
        {
            // printf("plane_intersect\n");
            ray->hit.obj = (void *)tmp;
            ray->hit.obj_type = id_cylinder;
            // free(*final_hit);
            // *final_hit = hit_dup(&ray->hit);
            if (ray->hit.t < (*final_hit).t)
                *final_hit = ray->hit;
            // printf("*final_hit = %ld\n", *final_hit);
        }
        tmp = tmp->next;
    }
    return (NULL);
}


// static t_hit    *get_closest_pl(t_base *base, t_ray *ray, t_hit **final_hit)
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


t_hit	*ray_cylinders( t_ray ray, t_base *base, t_hit *hit);

t_hit *get_closest_obj(t_base *data /*, t_ray *ray*/)
{
    // t_hit *obj;
    // t_hit *tmp;
    t_hit *final_hit = NULL;


    // data->utils->ray.hit.t = INFINITY;
    // final_hit.t = INFINITY;

    // get_closest_pl(data, &data->utils->ray, &final_hit);
    // printf("data->utils->ray.hit.t  = %f\n", data->utils->ray.hit.t );
    final_hit = get_closest_sp(data, &data->utils->ray, NULL);
    // printf("data->utils->ray.hit.t  = %f\n", data->utils->ray.hit.t );

    final_hit = ray_cylinders(data->utils->ray, data, &data->utils->ray.hit);
    // printf("data->utils->ray.hit.t get_closest_cy  = %f\n", data->utils->ray.hit.t );
    // if (res && tmp && tmp->t < res->t)

    // set_vec(&from_light->or, data->a_light->coords.x, data->a_light->coords.y, data->a_light->coords.z);
    // from_light.dir = *vec_normalize(vec_sub(obj_min->phit, &from_light.or));
    // set_vec(&from_light.dir, data->a_light->coords.x, data->a_light->coords.y, data->a_light->coords.z);
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
    return (final_hit);
    // return (&data->utils->ray.hit);
}