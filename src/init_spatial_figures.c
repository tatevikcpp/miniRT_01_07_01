/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_spatial_figures.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 14:18:26 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/08/05 10:39:58 by mavardan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// static void free_arr(char **a1, char **a2, char **a3)
// {
//	 free_matrix(a1);
//	 free_matrix(a2);
//	 free_matrix(a3);
// }

void	sphere(t_sphere **obj, char **v)
{
	char		**split_rgb;
	char		**split_coord;
	t_sphere	*tmp;

	split_coord = NULL;
	// split_rgb
	if (count_of_rows(v) == 3 && is_in_float_limit(v[1]) && \
		str_to_float(v[1]) >= 0)
	{
		split_coord = ft_split(v[0], ',');
		split_rgb = ft_split(v[2], ',');
		if ((count_of_rows(split_coord) != 3 || count_of_rows(split_rgb) != 3))
			print_error_exit("Something invalid for sphere");
		else
		{
			tmp = ft_lstnew_sp();
			check_valid_coords(&tmp->center, split_coord, 0);
			check_valid_rgb(&tmp->rgb, split_rgb);
			tmp->dm = str_to_float(v[1]);
			tmp->id = id_sphere;
			tmp->r2 = ft_atof(v[1]);
			tmp->r2 *= tmp->r2; // TODO ysenc pah ka
			ft_lstadd_back_sp(obj, tmp);
		}
	}
	else
		print_error_exit("Something invalid for sphere");
	// free_matrix(split_rgb);
	free_matrix(split_coord);
}

void	plane(t_plane **obj, char **v)
{
	char	**split_rgb;
	char	**split_norm;
	char	**split_coord;
	t_plane	*tmp;

	if (count_of_rows(v) == 3)
	{
		split_coord = ft_split(v[0], ',');
		split_norm = ft_split(v[1], ',');
		split_rgb = ft_split(v[2], ',');
		if (count_of_rows(split_coord) != 3 || count_of_rows(split_rgb) != 3 || \
			count_of_rows(split_norm) != 3)
			print_error_exit("Something invalid for plane");
		else
		{
			tmp = ft_lstnew_pl();
			check_valid_coords(&tmp->coord, split_coord, 0);
			check_valid_coords(&tmp->norm, split_norm, 1);
			check_valid_rgb(&tmp->rgb, split_rgb);
			tmp->id = id_plane;
			ft_lstadd_back_pl(obj, tmp);
		}
	}
	else
		print_error_exit("Something invalid for plane");
}

void	cylinder(t_cylinder **obj, char **v) // TODO 25 toxic avel e
{
	t_cylinder	*tmp;
	char		**split_rgb;
	char		**split_norm;
	char		**split_coord;

	if (count_of_rows(v) == 5 && is_in_float_limit(v[2]) && \
		is_in_float_limit(v[3]))
	{
		split_coord = ft_split(v[0], ',');
		split_norm = ft_split(v[1], ',');
		split_rgb = ft_split(v[4], ',');
		if (count_of_rows(split_coord) != 3 || count_of_rows(split_rgb) != 3 || \
			count_of_rows(split_norm) != 3 || (str_to_float(v[2]) < 0 && \
			str_to_float(v[3]) < 0))
			print_error_exit("Something invalid for cylinder");
		else
		{
			tmp = ft_lstnew_cy();
			check_valid_coords(&tmp->center, split_coord, 0);
			check_valid_coords(&tmp->norm, split_norm, 1);
			check_valid_rgb(&tmp->rgb, split_rgb);
			tmp->id = id_cylinder;
			tmp->dm = str_to_float(v[2]);
			tmp->hg = str_to_float(v[3]);
			ft_lstadd_back_cy(obj, tmp);
		}
	}
	else
		print_error_exit("Something invalid for cylinder");
	// free_arr(split_rgb, split_norm, split_coord);
}
