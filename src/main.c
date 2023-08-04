/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 12:37:36 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/08/02 11:50:54 by mavardan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void init_base(t_base *obj) // 48
{
	if (!obj)
		print_error_exit("chak init obj");
	obj->a_amb			= (t_amb *)ft_calloc(sizeof(t_amb), 1);
	obj->a_camera		= (t_camera *)ft_calloc(sizeof(t_camera), 1);
	obj->a_light		= (t_light *)ft_calloc(sizeof(t_light), 1);
	obj->utils 			= (t_utils *)ft_calloc(sizeof(t_utils), 1);
	obj->rt 			= new_rt(obj);
	obj->a_plane		= NULL;
	obj->a_cylinder		= NULL;
	obj->a_sphere		= NULL;
	if (!obj->a_amb || !obj->a_camera || !obj->a_light || !obj->a_plane || !obj->a_cylinder)
		return ;

}

int main(int c, char **v)
{
	int	fd;
	unsigned char flag;
	// void	*mlx;
	// void	*mlx_win;

	flag = 0;
	t_base *obj = (t_base *)ft_calloc(sizeof(t_base), 1);
	if (!obj)
		print_error_exit("chka obj main");
	if (c != 2)
		print_error_exit("error argument");
	init_base(obj);
	fd = check_file(v[1]); // esim
	if (fd)
		read_map(fd, obj, flag);  // TODO check if
	// struct_tree(obj);

	// free_base(obj);

	/////*************************
	obj->mlx.mlx_ptr = mlx_init();
	obj->img_data.img = mlx_new_image(obj->mlx.mlx_ptr, WIN_WIDTH, WIN_HEGHT);
	
	obj->mlx.win_ptr = mlx_new_window(obj->mlx.mlx_ptr, WIN_WIDTH, WIN_HEGHT, "Hello world!");
	obj->img_data.addr = mlx_get_data_addr(obj->img_data.img, &obj->img_data.bits_per_pixel, &obj->img_data.line_length,
								&obj->img_data.endian);
	obj->rt->widht = WIN_WIDTH;
	obj->rt->height = WIN_HEGHT;
    // mlx_get_screen_size(obj->mlx.mlx_ptr, &obj->rt->widht, &obj->rt->height);
    obj->rt->aspectratio = (float) obj->rt->widht / obj->rt->height;
	combine_img(obj);
	mlx_put_image_to_window(obj->mlx.mlx_ptr, obj->mlx.win_ptr, obj->img_data.img, 0, 0);

	/////*************************

	mlx_loop(obj->mlx.mlx_ptr);
	free(obj);
	pause();
	return (0);
}
