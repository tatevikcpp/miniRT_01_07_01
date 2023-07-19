/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavardan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 20:31:39 by mavardan          #+#    #+#             */
/*   Updated: 2023/07/19 18:47:36 by tumolabs         ###   ########.fr       */
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
void	vec_normalize(t_vec *vec);

//sp_cam_utils.c
t_sphere	*new_sphere(t_vec *center, float diameter, t_rgb *rgb);
t_camera	*new_cam(t_vec *view_v, t_vec *norm_v, float fov);

//utils.c
int	is_int_in_range(int val, int left, int right);

#endif
