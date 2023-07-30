/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavardan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 19:24:09 by mavardan          #+#    #+#             */
/*   Updated: 2023/07/24 21:26:37 by tumolabs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "minirt.h"

#include <math.h>
#include <stdlib.h>
#include "../includes/struct.h"
#include "../includes/minirt.h"
#include "utils.h"

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

void	set_vec(t_vec *vec, float x, float y, float z)
{
	vec->x = x;
	vec->y = y;
	vec->z = z;
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

t_vec   *ray_mult(t_vec *dst, t_ray *r, float t)
{
    dst->x = r->or.x + t * r->dir.x;
    dst->y = r->or.y + t * r->dir.y;
    dst->z = r->or.z + t * r->dir.z;
    return (dst);
}

t_vec	*vec_normalize(t_vec *vec) // TODO return type ?
{
	float	len;

	len = vec_length(vec);
	if (0 == len)
		print_error_exit("Try to divide by 0");
	vec->x /= len;
	vec->y /= len;
	vec->z /= len;
	return (vec);
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

float   distance(t_vec a, t_vec b)
{
    float   x;
    float   y;  
    float   z;

    x = a.x - b.x;
    y = a.y - b.y;
    z = a.z - b.z;
    x *= x;
    y *= y;
    z *= z;
    return (sqrt(x + y +z));
}

t_vec	*vec_inv(t_vec *v)
{
	v->x = -v->x;
	v->y = -v->y;
	v->z = -v->z;
	return (v);
}

static void	set_3x3_mat(float mat[3][3], t_vec *row1, t_vec *row2, t_vec *row3)
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
	float	mat[3][3];
	float	cosinus;
	float	sinus;

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
		set_3x3_mat(mat, new_vec(cosinus, 0, -sinus),
			new_vec(0, 1, 0), new_vec(sinus, 0, cosinus));
	}
	else if ('z' == axis)
	{
		set_3x3_mat(mat, new_vec(cosinus, sinus, 0),
			new_vec(-sinus, cosinus, 0), new_vec(0, 0, 1));
	}
	return (matrix_vec_mul(mat, vec));
}

//camera-to-world matrix calculation
//from - camera's coordinates, to - what the camera is looking at
//??????? 3x4 dardznel, 3 hat,0-ner@ kareli a chgrel, qani vor 0 e init arvum
//???????tox-syun
void	look_at(t_vec *from, t_vec *to, t_rt *rt) // TODO 3x3 vra havanabar ))
{
	t_vec	*forward;
	t_vec	*right;
	t_vec	*up;

	forward = vec_sub(from, to); 
	// forward = &rt->cam->norm; // havanabar
	vec_normalize(forward);
	right = cross_product(new_vec(0, 1, 0), forward);
	vec_normalize(right);
	up = cross_product(forward, right);
	rt->cam_matrix[0][0] = right->x;
	rt->cam_matrix[1][0] = right->y;
	rt->cam_matrix[2][0] = right->z;
	rt->cam_matrix[0][1] = up->x;
	rt->cam_matrix[1][1] = up->y;
	rt->cam_matrix[2][1] = up->z;
	rt->cam_matrix[0][2] = forward->x;
	rt->cam_matrix[1][2] = forward->y;
	rt->cam_matrix[2][2] = forward->z;
	// rt->cam_matrix[0][3] = from->x;
	// rt->cam_matrix[1][3] = from->y;
	// rt->cam_matrix[2][3] = from->z;
	// rt->cam_matrix[0][3] = 0;
	// rt->cam_matrix[1][3] = 0;
	// rt->cam_matrix[2][3] = 0;
	// //erevi
	// rt->cam_matrix[3][0] = 0;
	// rt->cam_matrix[3][1] = 0;
	// rt->cam_matrix[3][2] = 0;
	// rt->cam_matrix[3][3] = 1;
}

void lookat(t_rt *rt, t_vec  const eye, t_vec  const center, t_vec  const up)
{
    vec3  f = normalize(center - eye);
    vec3  u = normalize(up);
    vec3  s = normalize(cross_product(f, u));
    u = cross_product(s, f);

    rt->cam_matrix[0][0] = s.x;
    rt->cam_matrix[1][0] = s.y;
    rt->cam_matrix[2][0] = s.z;
    rt->cam_matrix[0][1] = u.x;
    rt->cam_matrix[1][1] = u.y;
    rt->cam_matrix[2][1] = u.z;
    rt->cam_matrix[0][2] =-f.x;
    rt->cam_matrix[1][2] =-f.y;
    rt->cam_matrix[2][2] =-f.z;
    rt->cam_matrix[3][0] = -vec_dot_product(s, eye);
    rt->cam_matrix[3][1] = -vec_dot_product(u, eye);
    rt->cam_matrix[3][2] = vec_dot_product(f, eye);
}



// void	look_at(t_rt *rt)
// {
// 	t_vec	*forward;
// 	t_vec	*right;
// 	t_vec	*up;
// 	t_vec	*tmp;

// 	tmp = new_vec(0, 1, 0);
// 	forward = &rt->cam->norm;
// 	vec_normalize(forward);
// 	right = cross_product(tmp, forward);
// 	up = cross_product(forward, right);
// 	rt->cam_matrix[0][0] = right->x;
// 	rt->cam_matrix[0][1] = right->y;
// 	rt->cam_matrix[0][2] = right->z;
// 	rt->cam_matrix[1][0] = up->x;
// 	rt->cam_matrix[1][1] = up->y;
// 	rt->cam_matrix[1][2] = up->z;
// 	rt->cam_matrix[2][0] = forward->x;
// 	rt->cam_matrix[2][1] = forward->y;
// 	rt->cam_matrix[2][2] = forward->z;
// }