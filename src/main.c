/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaghazar <vaghazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 12:37:36 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/07/06 18:24:25 by vaghazar         ###   ########.fr       */
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
	obj->obj 			= (t_utils *)ft_calloc(sizeof(t_utils), 1);
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
	void	*mlx;
	void	*mlx_win;

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
	mlx = mlx_init();
	obj->img_data.img = mlx_new_image(mlx, WIN_WIDTH, WIN_HEGHT);
	
	mlx_win = mlx_new_window(mlx, WIN_WIDTH, WIN_HEGHT, "Hello world!");
	obj->img_data.addr = mlx_get_data_addr(obj->img_data.img, &obj->img_data.bits_per_pixel, &obj->img_data.line_length,
								&obj->img_data.endian);
	int i = 0;
	while (i < 100 )
	{
		my_mlx_pixel_put(&obj->img_data, i++, 5, 0x00bfff);
		/* code */
	}
	combine_img(obj);	
	mlx_put_image_to_window(mlx, mlx_win, obj->img_data.img, 0, 0);

	/////*************************

	mlx_loop(mlx);
	free(obj);
	return (0);
}
