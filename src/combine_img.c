#include "minirt.h"


void print_hit(t_hit *hit)
{
    //print_vec("------------in print_hit: nhit = --------", hit->nhit);
    //print_vec("------------in print_hit: phit = --------", hit->phit);
    printf("t = %f", hit->t);
}

void combine_img(t_base *data)
{
    int i;
    int j;
    // int hit_color;
    t_hit *min_hit;
    int color;
	t_rgb	*tmp_col;

    i = 0;
    function(data->rt);
    while (i < WIN_WIDTH - 1)
    {
        j = 0;
        while (j < WIN_HEGHT - 1)
        {
            cam_ray(data->rt, &data->utils->ray, i, j);
            // sphere_intersect(&data->utils->ray, data->a_sphere, &data->utils->ray.hit);
            // sphere_intersect(&data->utils->ray, data->a_sphere->next, &data->utils->ray.hit);
            // color = get_closest_sp(data, &data->utils->ray.hit, &data->utils->ray);
            // color = get_closest_pl(data, &data->utils->ray.hit, &data->utils->ray);
            min_hit = get_closest_obj(data /*, &data->utils->ray*/);
            //print_vec("min_hit->p_hit = ", min_hit->phit);
            //if (data->utils->ray.hit.nhit)
            if (min_hit->obj)
            {
                light_ray(data->a_light, &data->utils->ray, min_hit);
                if (is_in_shadow(data, &data->utils->ray, min_hit->phit))
				{
					tmp_col = mul_rgb(&min_hit->color, 1);
					color = rgb_to_int(compute_color_with_amb(tmp_col, data->a_light->amb_col));
				}
                else
                    color = rgb_to_int(compute_color(data, &min_hit->color, min_hit));
		        my_mlx_pixel_put(&data->img_data, i, j, color);
                free_hit(min_hit);
            }
            j++;
        }
        i++;
    }
}
