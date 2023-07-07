/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_spatial_figures.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaghazar <vaghazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 14:18:26 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/07/06 18:48:15 by vaghazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void free_arr(char **a1, char **a2, char **a3)
{
    free_matrix(a1);
    free_matrix(a2);
    free_matrix(a3);
}

void    sphere(t_sphere **obj, char **v)
{
    char        **split_rgb;
    char        **split_coord;
    t_sphere    *tmp;

    if (count_of_rows(v) == 3 && is_in_float_limit(v[1]) && 
        str_to_float(v[1]) >= 0)
    {
        split_coord = ft_split(v[0], ',');
        split_rgb = ft_split(v[2], ',');
        if ((count_of_rows(split_coord) != 3 || count_of_rows(split_rgb) != 3))
                print_error_exit("sxal split qanak sphere\n");
        else 
        {
            tmp = ft_lstnew_sp();
            check_valid_coords(&tmp->coord_sphere_center, split_coord, 0);
            check_valid_rgb(&tmp->rgb, split_rgb);
            tmp->sphere_diameter = str_to_float(v[1]);
            ft_lstadd_back_sp(obj, tmp);
        }
    }
    else
        print_error_exit("sxal split qanak SPHERE\n");
    free_matrix(split_rgb);
    free_matrix(split_coord);
}

void    plane(t_plane **obj, char **v)
{
    char    **split_rgb;
    char    **split_norm;
    char    **split_coord; 
    t_plane *tmp;

    if (count_of_rows(v) == 3)
    {
        split_coord = ft_split(v[0], ',');
        split_norm = ft_split(v[1], ',');
        split_rgb = ft_split(v[2], ',');
        if (count_of_rows(split_coord) != 3 || count_of_rows(split_rgb) != 3 ||
            count_of_rows(split_norm) != 3)
                print_error_exit("sxal split qanak plane\n");
        else
        {
            tmp = ft_lstnew_pl();
            check_valid_coords(&tmp->coord_point_in_plane, split_coord, 0);
            check_valid_coords(&tmp->norm_normal_vector, split_norm, 1);
            check_valid_rgb(&tmp->rgb, split_rgb);
            ft_lstadd_back_pl(obj,tmp);
        }
    }
    else
        print_error_exit("sxal split qanak PLANE\n");
   free_arr(split_rgb, split_norm, split_coord);
}

void    cylinder(t_cylinder **obj, char **v) // TODO 25 toxic avel e
{
    char        **split_rgb;
    char        **split_norm;
    char        **split_coord;
    t_cylinder  *tmp;

    if (count_of_rows(v) == 5 && is_in_float_limit(v[2]) &&
        is_in_float_limit(v[3]))
    {
        split_coord = ft_split(v[0], ',');
        split_norm = ft_split(v[1], ',');
        split_rgb = ft_split(v[4], ',');
        if (count_of_rows(split_coord) != 3 || count_of_rows(split_rgb) != 3 ||
            count_of_rows(split_norm) != 3 || (str_to_float(v[2]) <  0 && str_to_float(v[3]) < 0))
                print_error_exit("sxal_split_qanak_cylinder\n");
        else
        {
            tmp = ft_lstnew_cy();
            check_valid_coords(&tmp->coord_center_cy ,split_coord, 0);
            check_valid_coords(&tmp->norm_vector_cy, split_norm, 1);
            check_valid_rgb(&tmp->rgb, split_rgb);
            tmp->cy_diameter = str_to_float(v[2]);
            tmp->cy_height = str_to_float(v[3]);
            ft_lstadd_back_cy(obj, tmp);
        }
    }
    else
        print_error_exit("sxal_split_qanak_CYLINDER\n");
    free_arr(split_rgb, split_norm, split_coord);
}