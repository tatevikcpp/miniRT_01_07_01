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
	obj->a_camera		= (t_camera *)malloc(sizeof(t_camera));
	obj->a_light		= (t_light *)ft_calloc(sizeof(t_light), 1);
	obj->a_plane		= NULL;
	obj->a_cylinder		= NULL;
	obj->a_sphere		= NULL;
	if (!obj->a_amb || !obj->a_camera || !obj->a_light || !obj->a_plane || !obj->a_cylinder)
		return ;
}

typedef struct	s_data 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

int main(int c, char **v)
{
	int	fd;
	unsigned char flag;
	void	*mlx;

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
	struct_tree(obj);

	// free_base(obj);

	/////*************************
	t_data	img;

	mlx = mlx_init();
	img.img = mlx_new_image(mlx, 300, 300);

	mlx_new_window(mlx, 600, 600, "Hello world!");
	mlx_loop(mlx);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);

	/////*************************

	free(obj);
	printf("\n---------******----------\n\n");
	return (0);
}
