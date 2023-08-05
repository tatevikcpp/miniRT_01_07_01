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
    // function(data->rt);
    while (i < WIN_WIDTH - 1)
    {
        j = 0;
        while (j < WIN_HEGHT - 1)
        {
            cam_ray(data->rt, &data->utils->ray, i, j);
            min_hit = get_closest_obj(data /*, &data->utils->ray*/);
            // printf("min_hit = %ld\n", min_hit);
            // min_hit = &data->utils->hit;
            // min_hit = data->utils->hit;
            // if (min_hit->obj)
            if (min_hit)
            {
                light_ray(data->a_light, &data->utils->ray, min_hit);
                if (is_in_shadow(data, &data->utils->ray))
				{
					tmp_col = mul_rgb(&min_hit->color, 1);
					color = rgb_to_int(compute_color_with_amb(tmp_col, &data->a_light->rgb));
                    // color = 0x00ff00;
				}
                else
                {
                    // printf("is_in_shadow\n");

                    color = rgb_to_int(compute_color(data, &min_hit->color, min_hit));
                    // color = 0xff0000;
                }
		        my_mlx_pixel_put(&data->img_data, i, j, color);
            }
            j++;
        }
        i++;
    }
}

