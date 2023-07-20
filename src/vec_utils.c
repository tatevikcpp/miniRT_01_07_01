/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavardan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 19:24:09 by mavardan          #+#    #+#             */
/*   Updated: 2023/07/20 20:41:12 by tumolabs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "minirt.h"

#include <math.h>
#include <stdlib.h>
#include "../includes/struct.h"
#include "../includes/minirt.h"

t_vec	*new_vec(float x, float y, float z)
{
	t_vec	*vec;

	vec = malloc(sizeof(t_vec));
	if (!vec)
		print_error_exit("Allocation error\n");
	vec->x = x;
	vec->y = y;
	vec->z = z;
	return (vec);
}

t_vec	*vec_sum(t_vec *v1, t_vec *v2)
{
	return (new_vec(v1->x + v2->x, v1->y + v2->y, v1->z + v2->z));
}

t_vec	*vec_sub(t_vec *v1, t_vec *v2)
{
	return (new_vec(v1->x - v2->x, v1->y - v2->y, v1->z - v2->z));
}

t_vec	*vec_num_mul(t_vec *v, float mul)
{
	return (new_vec(v->x * mul, v->y * mul, v->z * mul));
}

float	vec_dot_product(t_vec *v1, t_vec *v2)
{
	return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}

float	vec_length(t_vec *vec)
{
	return (sqrt(vec_dot_product(vec, vec)));
}

void	vec_normalize(t_vec *vec)
{
	float	len;

	len = vec_length(vec);
	vec->x /= len;
	vec->y /= len;
	vec->z /= len;
}

t_vec	*matrix_vec_mul(float mat[3][3], t_vec *vec)
{
	float	x;
	float	y;
	float	z;

	x = mat[0][0] * vec->x + mat[0][1] * vec->y + mat[0][2] * vec->z;
	y = mat[1][0] * vec->x + mat[1][1] * vec->y + mat[1][2] * vec->z;
	z = mat[2][0] * vec->x + mat[2][1] * vec->y + mat[2][2] * vec->z;
	return (new_vec(x, y, z));
}

t_vec	*cross_product(t_vec *v1, t_vec *v2)
{
	float	x;
	float	y;
	float	z;

	x = v1->y * v2->z - v1->z * v2->y;
	y = v1->z * v2->x - v1->x * v2->z;
	z = v1->x * v2->y - v1->y * v2->x;
	return (new_vec(x, y, z));
}
