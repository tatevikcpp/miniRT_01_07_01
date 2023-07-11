/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaghazar <vaghazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 12:39:09 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/07/06 18:30:04 by vaghazar         ###   ########.fr       */
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
# include "../mlx_linux/mlx.h"
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
void    read_map(int fd, t_base *obj, int flag);
void free_base(t_base *obj);

//porcnakan
char *ft_strcat(char *start, int len);
int	is_space(char c);

float	str_to_float(char *s);
int	is_in_float_limit(char *s);

int     is_in_float_limit(char *s);
void    ambient_lightning( t_ambient_lightning *obj, char **v);
void    camera(t_camera *obj, char **v);
void    light(t_light *obj, char **v);
void    sphere(t_sphere **obj, char **v);
void    plane(t_plane **obj, char **v);
void    cylinder(t_cylinder **obj, /* t_base *obj, */ char **v);
void    check_valid_coords(t_coords *obj, char **split, int flag);
void    check_valid_rgb(t_rgb *obj, char **split);

void    struct_tree(t_base *obj);
void    free_matrix(char **arr);


//lists
void    print_list_pl(t_plane *list);
t_plane	*ft_lstnew_pl(void);
t_plane	*ft_lstlast_pl(t_plane *lst);
void	ft_lstadd_back_pl(t_plane **lst, t_plane *new);
void	ft_lstadd_front_pl(t_plane **lst, t_plane *new);

void    print_list_cy(t_cylinder *list);
t_cylinder	*ft_lstnew_cy(void);
t_cylinder	*ft_lstlast_cy(t_cylinder *lst);
void	ft_lstadd_back_cy(t_cylinder **lst, t_cylinder *new);
void	ft_lstadd_front_cy(t_cylinder **lst, t_cylinder *new);


void    print_list_sp(t_sphere *list);
t_sphere	*ft_lstnew_sp(void);
t_sphere	*ft_lstlast_sp(t_sphere *lst);
void	ft_lstadd_back_sp(t_sphere **lst, t_sphere *new);
void	ft_lstadd_front_sp(t_sphere **lst,t_sphere *new);


#endif