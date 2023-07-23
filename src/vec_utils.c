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
		print_error_exit("Allocation error");
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
	if (0 == len)
		print_error_exit("Try to divide by 0");
	vec->x /= len;
	vec->y /= len;
	vec->z /= len;
}

t_vec	*matrix_vec_mul(float mat[3][3], t_vec *vec)
{
	float	x;
	float	y;
	float	z;

	if (!vec)
		print_error_exit("Null pinter");
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

static void set_3x3_mat(float mat[3][3], t_vec *row1, t_vec *row2, t_vec *row3)
{
	if (!row1 || !row2 || !row3)
		print_error_exit("NULL pointer");
	mat[0][0] = row1->x;
	mat[1][0] = row2->x;
	mat[2][0] = row3->x;
	mat[0][1] = row1->y;
	mat[1][1] = row2->y;
	mat[2][1] = row3->y;
	mat[0][2] = row1->z;
	mat[1][2] = row2->z;
	mat[2][2] = row3->z;
}

t_vec	*rot_vec(t_vec *vec, float alpha, char axis)
{
	float mat[3][3];
	float cosinus;
	float sinus;

	if (!vec)
		print_error_exit("Null pointer");
	cosinus = cos(alpha);
	sinus = sin(alpha);
	if ('x' == axis)
	{
		set_3x3_mat(mat, new_vec(1, 0, 0),
				new_vec(0, cosinus, -sinus), new_vec(0, sinus, cosinus));
	}
	else if ('y' == axis)
	{
		set_3x3_mat(mat, new_vec(cosinus, 0, sinus),
				new_vec(0, 1, 0), new_vec(-sinus, 0, cosinus));
	}
	else if ('z' == axis)
	{
		set_3x3_mat(mat, new_vec(cosinus, -sinus, 0),
				new_vec(sinus, cosinus, 0), new_vec(0, 0, 1));
	}
	return (matrix_vec_mul(mat, vec));
}
