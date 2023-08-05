/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 12:39:09 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/08/05 09:23:37 by tkhechoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../includes/mlx.h"
# include "../libft/libft.h"
# include "struct.h"
# include "defines.h"

int			ft_printf(int fd,  char *s, ...);
char		*get_next_line(int fd);
void		print_error_exit(char *str);
int			check_file(char *file);
char		**get_map(char *map_name);
void		print_matrix(char **matrix);
int			count_of_rows(char **matrix);
void		valid_map(char **map);

//ankap
char		*func(char *str);
void		split_one(char **map);
void		print_struct(t_amb *a);
void		read_map(int fd, t_base *obj, int flag);
void		free_base(t_base *obj);

//porcnakan
char		*ft_strcat(char *start, int len);
int			is_space(char c);

float		str_to_float(char *s);
int			is_in_float_limit(char *s);

int			is_in_float_limit(char *s);
void		ambient_lightning(t_amb *obj, char **v);
void		camera(t_camera *obj, char **v);
void		light(t_light *obj, char **v);
void		sphere(t_sphere **obj, char **v);
void		plane(t_plane **obj, char **v);
void		cylinder(t_cylinder **obj, char **v);
void		check_valid_coords(t_vec *obj, char **split, int flag);
void		check_valid_rgb(t_rgb *obj, char **split);

void		struct_tree(t_base *obj);
void		free_matrix(char **arr);

//lists
void		print_list_pl(t_plane *list);
t_plane		*ft_lstnew_pl(void);
t_plane		*ft_lstlast_pl(t_plane *lst);
void		ft_lstadd_back_pl(t_plane **lst, t_plane *new);
void		ft_lstadd_front_pl(t_plane **lst, t_plane *new);

void		print_list_cy(t_cylinder *list);
t_cylinder	*ft_lstnew_cy(void);
t_cylinder	*ft_lstlast_cy(t_cylinder *lst);
void		ft_lstadd_back_cy(t_cylinder **lst, t_cylinder *new);
void		ft_lstadd_front_cy(t_cylinder **lst, t_cylinder *new);

void		print_list_sp(t_sphere *list);
t_sphere	*ft_lstnew_sp(void);
t_sphere	*ft_lstlast_sp(t_sphere *lst);
void		ft_lstadd_back_sp(t_sphere **lst, t_sphere *new);
void		ft_lstadd_front_sp(t_sphere **lst, t_sphere *new);

void		print_list_obj(t_utils *list);
t_utils		*ft_lstnew_obj(void);
t_utils		*ft_lstlast_obj(t_utils *lst);
void		ft_lstadd_back_obj(t_utils **lst, t_utils *new);
void		ft_lstadd_front_obj(t_utils **lst, t_utils *new);

//vec_utils.c
t_vec		new_vec(float x, float y, float z);
t_vec		vec_sum(t_vec v1, t_vec v2);
t_vec		vec_sub(t_vec v1, t_vec v2);
t_vec	    vec_mult(t_vec v1, t_vec v2);
t_vec	    vec_num_mul(t_vec v, float mul);
float		vec_dot_product(t_vec v1, t_vec v2);
t_vec       cross_product(t_vec v1, t_vec v2);
float		vec_length(t_vec vec);
void		vec_normalize(t_vec *vec);
t_vec		rot_vec(t_vec vec, float alpha, char axis);
t_vec		vec_inv(t_vec v);
float		distance(t_vec p, t_vec q);
void		cam_ray(t_rt *rt, t_ray *ray, float pixel_x, float pixel_y);
void		look_at(t_rt *rt);

// intersection
t_bool		plane_intersect(t_ray *ray, t_plane *pl, t_hit *hit);

//
void		cam_ray(t_rt *rt, t_ray *ray, float pixel_x, float pixel_y);
void		set_vec(t_vec *vec, float x, float y, float z);
t_vec		cam_to_world(float m[4][4], t_vec *v);
void		build_ray(t_ray *ray, t_vec *or, t_vec *dir);
void		my_mlx_pixel_put(t_img_data *data, int x, int y, int color);
void		combine_img(t_base *data);
void		look_at(/*t_vec *from, t_vec *to, float mat[4][4]*/ t_rt *rt); // TODO 3x3 vra havanabar ));
void		function(t_rt *rt);
t_rt		*new_rt(t_base *base);
void		print_vec(char *s, t_vec vec);
int         rgb_to_int(t_rgb *rgb);
float		to_rad( float angle);


// t_hit       *get_closest_sp(t_base *base, t_ray *ray);
// t_hit       *get_closest_pl(t_base *base, t_ray *ray);
// t_hit       *get_closest_cy(t_base *base, t_ray *ray);

t_hit *get_closest_obj(t_base *base /*, t_ray *ray*/);
void free_hit(t_hit *obj);
t_vec   ray_mult(t_vec *dst, t_ray *r, float t);
t_rgb	*compute_color(t_base *base, t_rgb *p_col, t_hit *hit);
t_rgb	*mul_rgb(t_rgb *rgb, float mul);
t_vec   *norm_sp(t_vec *c, t_vec *p);
t_vec   cross_product(t_vec v1, t_vec v2);
int	    quadratic_eq_solution(t_quadratic *q);
void    light_ray(t_light *light, t_ray *ray, t_hit *min_hit);
t_bool  is_in_shadow(t_base *base, t_ray *ray);
t_rgb	*compute_color_with_amb(t_rgb *p_col, t_rgb *amb_col);


//utils_math.c

int	max(int a, int b);
float	min(float a, float b);


//

t_bool	cylinder_intersect(t_ray *r, t_cylinder *cy);
t_vec	*vec_dup(t_vec vec);
t_vec	get_closest_point_from_line(t_vec a, t_vec b, t_vec p);
t_hit	*hit_dup(t_hit *hit);
t_hit	*new_hit();
t_ray	*new_ray();
t_ray	*ray_dup(t_ray *ray);
void	swap(float *x1, float *x2);
void	move(t_camera *cam, int x_step, int y_step);
float	cy_intersection(t_ray ray,  t_cylinder cylinder);
int		sphere_intersect(t_ray *ray,  t_sphere sphere);
t_vec	rot_vec(t_vec vec, float alpha, char axis);
void	move(t_camera *cam, int x_step, int y_step);
int		key_press(int keycode, t_base *obj);

#endif
