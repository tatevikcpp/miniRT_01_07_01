/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavardan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 20:31:39 by mavardan          #+#    #+#             */
/*   Updated: 2023/07/19 19:49:04 by tumolabs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef UTILS_H
# define UTILS_H

# include "struct.h"

//vec_utils.c
t_vec	*new_vec(float x, float y, float z);
t_vec	*vec_sum(t_vec *v1, t_vec *v2);
t_vec	*vec_sub(t_vec *v1, t_vec *v2);
float	vec_dot_product(t_vec *v1, t_vec *v2);
float	vec_length(t_vec *vec);
t_vec	*vec_normalize(t_vec *vec);
t_vec	*rot_vec(t_vec *vec, float alpha, char axis);

//sp_cam_utils.c
t_sphere	*new_sphere(t_vec *center, float diameter, t_rgb *rgb);
t_camera	*new_cam(t_vec *view_v, t_vec *norm_v, float fov);

//rgb_utils.c
t_rgb	*mul_rgb(t_rgb *rgb1, float mul);
t_rgb	*sum_rgb(t_rgb *rgb1, t_rgb *rgb2);
t_rgb	*sub_rgb(t_rgb *rgb1, t_rgb *rgb2);

//utils.c
int	is_int_in_range(int val, int left, int right);

//utils_math.c
int	min(int a, int b);
int	max(int a, int b);
int	quadratic_eq_solution(t_vec *vec, float *x1, float *x2);

#endif
