/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 12:39:09 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/07/01 17:24:39 by tkhechoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define SPACES " \t\v\f\r"
# define NUMBERS ".,-0123456789"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <mlx.h>
# include "../libft/libft.h"
# include "struct.h"

int     ft_printf(int fd, const char *s, ...);
char    *get_next_line(int fd);
void	  print_error_exit(char *str);
int		  check_file(char *file);
char    **get_map(char *map_name);
void    print_matrix(char **matrix);
int     count_of_rows(char **matrix);
void    valid_map(char **map);

//ankap
char    *func(char *str);
void	split_one(char **map);
void    print_struct(t_ambient_lightning *a);
void    init_base(t_base *obj);
void    init_amb(t_ambient_lightning *obj);
void    init_camera(t_camera *obj);
void	init_light(t_light *obj);
void	init_sphere(t_sphere *obj);
void    init_cylinder(t_cylinder *obj);
void    init_plane(t_plane *obj);
void    read_map(int fd, t_base *obj);

//porcnakan
char *ft_strcat(char *start, int len);
int	is_space(char c);

float	str_to_float(char *s);
int	is_in_float_limit(char *s);

//lcnel

int     is_in_float_limit(char *s);
void    init_rgb(t_rgb *obj);
void    init_coord(t_coords *obj);
void    ambient_lightning( t_ambient_lightning *obj, char **v);
void    camera(t_camera *obj, char **v);
void    light(t_light *obj, char **v);
void    sphere(t_sphere *obj, char **v);
void    plane(t_plane *obj, char **v);
void    cylinder(/* t_cylinder *obj, */t_base *obj, char **v);
void    check_valid_coords(t_coords *obj, char **split, int flag);
void    check_valid_rgb(t_rgb *obj, char **split);

void    struct_tree(t_base *obj);
void    print_list(t_list *list);
#endif