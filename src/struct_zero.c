/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_zero.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 12:37:59 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/07/01 16:57:14 by tkhechoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void  init_base(t_base *obj)
{
	obj->a_amb			= (t_ambient_lightning *)ft_calloc(sizeof(t_ambient_lightning), 1);
	obj->a_camera		= (t_camera *)malloc(sizeof(t_camera));
	obj->a_light		= (t_light *)ft_calloc(sizeof(t_light), 1);
	obj->a_plane		= (t_plane *)ft_calloc(sizeof(t_plane), 1);
	obj->a_cylinder		= (t_cylinder *)ft_calloc(sizeof(t_cylinder), 1);
	obj->a_sphere		= (t_sphere *)ft_calloc(sizeof(t_sphere), 1);
	obj->a_list_cy 		= ft_lstnew(NULL);
	obj->a_list_pl 		= ft_lstnew(NULL);
	obj->a_list_sp		= ft_lstnew(NULL);
	if (!obj->a_amb || !obj->a_camera || !obj->a_light || !obj->a_plane || !obj->a_cylinder)
		return ;
	if (!obj->a_camera)
		printf("of esim\n");
}

void init_amb(t_ambient_lightning *obj)
{
	obj->rgb = (t_rgb *)ft_calloc(sizeof(t_rgb), 1);
	if (!obj->rgb)
		return ;
	init_rgb(obj->rgb);
	obj->amb = 0;
}

void  init_camera(t_camera *obj)
{
	obj->norm_orientation_vec = (t_coords *)ft_calloc(sizeof(t_coords), 1);
	obj->coord_view_point = (t_coords *)ft_calloc(sizeof(t_coords), 1);
	if (!obj->norm_orientation_vec || !obj->coord_view_point)
		return ;
	if (!obj)
		printf("chak cam obj\n");
	init_coord(obj->norm_orientation_vec);
	init_coord(obj->coord_view_point);
	obj->fov = 0;
}

void	init_light(t_light *obj)
{
	obj->rgb = (t_rgb *)ft_calloc(sizeof(t_rgb), 1);
	obj->coord_light_point = (t_coords *)ft_calloc(sizeof(t_coords), 1);
	if (!obj->coord_light_point || !obj->rgb)
		return ;
	obj->light_brightness = 0;
	init_rgb(obj->rgb);
	init_coord(obj->coord_light_point);
}

void	init_sphere(t_sphere *obj)
{
	obj->rgb = (t_rgb *)ft_calloc(sizeof(t_rgb), 1);
	obj->coord_sphere_center = (t_coords *)ft_calloc(sizeof(t_coords), 1);
	if (!obj->rgb || !obj->coord_sphere_center)
		return ;
	init_coord(obj->coord_sphere_center);
	obj->sphere_diameter = 0;
	init_rgb(obj->rgb);
}

void init_plane(t_plane *obj)
{
	obj->norm_normal_vector = (t_coords *)ft_calloc(sizeof(t_coords), 1);
	obj->coord_point_in_plane = (t_coords *)ft_calloc(sizeof(t_coords), 1);
	obj->rgb = (t_rgb *)ft_calloc(sizeof(t_rgb), 1);
	if (!obj->norm_normal_vector || !obj->coord_point_in_plane || !obj->rgb)
		return ;
	init_coord(	obj->coord_point_in_plane);
	init_coord(obj->norm_normal_vector);
	init_rgb(obj->rgb);
}

void init_cylinder(t_cylinder *obj)
{
	obj->norm_vector_cy = (t_coords *)ft_calloc(sizeof(t_coords), 1);
	obj->coord_center_cy = (t_coords *)ft_calloc(sizeof(t_coords), 1);
	obj->rgb = (t_rgb *)ft_calloc(sizeof(t_rgb), 1);
	if (!obj->norm_vector_cy || !obj->coord_center_cy || !obj->rgb)
		return ;
	init_coord(obj->coord_center_cy);
	init_coord(obj->norm_vector_cy);
	obj->cy_diameter = 0;
	obj->cy_height = 0;
	init_rgb(obj->rgb);
}

void init_rgb(t_rgb *obj)
{
	obj->g = 0;
	obj->b = 0;
}

void init_coord(t_coords *obj)
{
	obj->x = 0;
	obj->y = 0;
	obj->z = 0;
}