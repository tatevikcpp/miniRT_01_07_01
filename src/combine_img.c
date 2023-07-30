#include "test.h"
#include "minirt.h"


void print_hit(t_hit *hit)
{
    print_vec(hit->nhit);
    print_vec(hit->phit);
    printf("t = %f", hit->t);
}

void combine_img(t_base *data)
{
    int i;
    int j;

    i = 0;
    function(data->rt);
    // cam_to_world()
    // build_ray(&data->utils->ray, &data->a_camera->coord, &data->a_camera->norm);
    while (i < WIN_WIDTH - 1)
    {
        j = 0;
        while (j < WIN_HEGHT - 1)
        {
            cam_ray(data->rt, &data->utils->ray, i, j);
            sphere_intersect(&data->utils->ray, data->a_sphere, &data->utils->ray.hit);
            if (data->utils->ray.hit.nhit)
            {
		        my_mlx_pixel_put(&data->img_data, i, j, 0x00bfff);
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