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

static void init_base(t_base *obj)
{
	if (!obj)
		print_error_exit("chak init obj\n");
	obj->a_amb			= (t_ambient_lightning *)ft_calloc(sizeof(t_ambient_lightning), 1);
	obj->a_camera		= (t_camera *)malloc(sizeof(t_camera));
	obj->a_light		= (t_light *)ft_calloc(sizeof(t_light), 1);
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

	flag = 0;
	t_base *obj = (t_base *)ft_calloc(sizeof(t_base), 1);
	if (!obj)
		print_error_exit("chka obj main\n");
	if (c != 2)
		print_error_exit("error argument\n");
	init_base(obj);
	fd = check_file(v[1]); // esim
	if (fd)
		read_map(fd, obj, flag);  // TODO check if
	struct_tree(obj);
	free(obj);
	printf("\n---------******----------\n\n");
	return (0);
}