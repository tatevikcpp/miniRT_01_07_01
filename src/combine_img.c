#include "minirt.h"


void print_hit(t_hit *hit)
{
    print_vec("------------in print_hit: nhit = --------", hit->nhit);
    print_vec("------------in print_hit: phit = --------", hit->phit);
    printf("t = %f", hit->t);
}

void combine_img(t_base *data)
{
    int i;
    int j;
    int hit_color;
    t_hit *min_hit;

    i = 0;
    function(data->rt);
    while (i < WIN_WIDTH - 1)
    {
        j = 0;
        while (j < WIN_HEGHT - 1)
        {
            cam_ray(data->rt, &data->utils->ray, i, j);
            //printf(" in 2 whiles ");
            // sphere_intersect(&data->utils->ray, data->a_sphere, &data->utils->ray.hit);
            // sphere_intersect(&data->utils->ray, data->a_sphere->next, &data->utils->ray.hit);
            // color = get_closest_sp(data, &data->utils->ray.hit, &data->utils->ray);
            // color = get_closest_pl(data, &data->utils->ray.hit, &data->utils->ray);
            min_hit = get_closest_obj(data, &data->utils->ray);
            //if (data->utils->ray.hit.nhit)
            if (min_hit)
            {
                // hit_color = ALBEDO / PI * data->a_light->bright * data->a_light->color * ft
                // hitColor = hitObject->albedo / M_PI * light->intensity * light->color * std::max(0.f, hitNormal.dotProduct(L));
                //printf(" before put_pixel ");
		        my_mlx_pixel_put(&data->img_data, i, j, rgb_to_int(compute_color(data, &min_hit->color)));
                //printf(" after put_pixel ");
                free_hit(min_hit);
                // print_hit(&data->utils->ray.hit);
            }
            j++;
        }
        i++;
    }
            // print_vec(&data->utils->ray.dir);
    // prinf_vec(&data->utils->ray.dir);
    // prinf_vec(&data->utils->ray.or);
    // printf("%f\n", )
}