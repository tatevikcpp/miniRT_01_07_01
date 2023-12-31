/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_of_element.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 12:37:12 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/08/05 07:26:10 by tkhechoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "utils.h"

void	check_valid_rgb(t_rgb *obj, char **split)
{
	int	i;
	int	num;

	i = 0;
	if (split)
	{
		while (split[i])
		{
			num = ft_atoi(split[i]);
			if (num < 0 || num > 255)
				print_error_exit("Invalid rgb");
			i++;
		}
		obj->r = (ft_atoi(split[0]));
		obj->g = (ft_atoi(split[1]));
		obj->b = (ft_atoi(split[2]));// der ayspes, int[3];
	}
}

void	ambient_lightning(t_amb *obj, char **v)
{
	char	**split;

	if (!obj)
		print_error_exit("Null pointer");
	if (count_of_rows(v) == 2 && is_in_float_limit(v[0]))
	{
		split = ft_split(v[1], ',');
		if ((str_to_float(v[0]) < 0.0 || str_to_float(v[0]) > 1.0) || \
				count_of_rows(split) != 3)
			print_error_exit("Something invalid for ambient lightning");
		else
		{
			if (!obj)
				print_error_exit("chka amb");
			obj->id = id_amb;
			obj->amb = str_to_float(v[0]);
			check_valid_rgb(&obj->rgb, split);
			obj->rgb.r = (int)(obj->rgb.r * obj->amb);
			obj->rgb.g = (int)(obj->rgb.g * obj->amb);
			obj->rgb.b = (int)(obj->rgb.b * obj->amb);
		}
	}
	else
		print_error_exit("Something invalid for ambient lightning");
	// free_matrix(split);
}

void	check_valid_coords(t_vec *obj, char **split, int norm_flag)
{
	int	i;

	i = 0;
	if (split)
	{
		while (split[i]) //
		{
			if (norm_flag == 1)
			{
				if (str_to_float(split[i]) < -1 || str_to_float(split[i]) > 1)
					print_error_exit("Invalid float argument");
			}
			if (!is_in_float_limit(split[i]))
				print_error_exit("Invalid float argument");
			i++;
		}
		obj->x = str_to_float(split[0]);
		obj->y = str_to_float(split[1]);
		obj->z = str_to_float(split[2]);
		if (norm_flag && fabsf(vec_length(*obj) - 1) > 0.01)
			print_error_exit("Invalid float argument");
	}
}

void	camera(t_camera *obj, char **v)
{
	char	**split_coord;
	char	**split_norm;

	if (count_of_rows(v) == 3)
	{
		split_coord = ft_split(v[0], ',');
		split_norm = ft_split(v[1], ',');
		if ((count_of_rows(split_coord) != 3 || count_of_rows(split_norm) != 3) \
			|| (str_to_float(v[2]) < 0.0 || str_to_float(v[2]) > 180.0))
			print_error_exit("Something invalid for camera");
		else
		{
			obj->id = id_camera;
			obj->fov = ft_atof(v[2]);
			check_valid_coords(&obj->coord, split_coord, 0);
			check_valid_coords(&obj->norm, split_norm, 1);
		}
	}
	else
		print_error_exit("Something invalid for camera");
	// free_matrix(split_coord);
	// free_matrix(split_norm);
}

void	light(t_light *obj, char **v)
{
	char	**split_coord;
	char	**split_rgb;

	if (count_of_rows(v) == 3 && is_in_float_limit(v[1]))
	{
		split_coord = ft_split(v[0], ',');
		split_rgb = ft_split(v[2], ',');
		if ((count_of_rows(split_coord) != 3 || count_of_rows(split_rgb) != 3) \
			|| (str_to_float(v[1]) < 0.0 || str_to_float(v[1]) > 1.0))
			print_error_exit("Something invalid for light");
		else
		{
			obj->id = id_light;
			check_valid_coords(&obj->coords, split_coord, 0);
			check_valid_rgb(&obj->rgb, split_rgb);
			obj->brigh = str_to_float(v[1]);
		}
	}
	else
		print_error_exit("Something invalid for light");
	// free_matrix(split_coord);
	// free_matrix(split_rgb);
}
