/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaghazar <vaghazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 12:36:55 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/07/12 20:53:46 by mavardan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

//#include "minirt.h"

typedef enum e_bool {FALSE, TRUE}	t_bool;
typedef struct	s_img_data t_img_data;

typedef struct	s_img_data 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img_data;

typedef enum e_obj_id
{
	id_amb,
	id_light,
	id_camera,
	id_plane,
	id_sphere,
	id_cylinder,
}	t_obj_id;

typedef struct s_rgb
{
    int r;
    int g;
    int b;
}   t_rgb;

typedef struct s_vec
{
    float x;
    float y;
    float z;
}   t_vec;

typedef struct s_amb
{
    t_obj_id	id;
    float amb; // [0.0, 1.0]
    t_rgb rgb; // 0 - 255
}   t_amb;

typedef struct s_camera
{
    t_obj_id	id;
    t_vec view; // x, y, z 
    t_vec norm; //[-1, 1] x, y , z
    float fov; // [0, 180]
    float scale;
}   t_camera;

typedef struct s_Light
{
    t_obj_id	id;
    t_vec light; //x, y, z
    float brigh; // [0.0, 1.0]
    t_rgb rgb; // 0 - 255
}   t_light;

typedef struct s_sphere
{
    t_obj_id	id;
    t_vec center;
    float dm;
    float r2;
    t_rgb rgb; // 0 - 255
    struct s_sphere *next;
}   t_sphere;

typedef struct s_cylinder
{
    t_obj_id	id;
    t_vec center; // x, y, z
    t_vec norm; // [-1, 1] x, y, z
    float dm;
    float rd;
    float hg;
    t_rgb rgb; // 0 - 255
    struct s_cylinder *next;
}   t_cylinder;

typedef struct s_plane
{
    t_obj_id	id;
    t_vec coord; // x, y, z ?
    t_vec norm; // [-1, 1] x, y, z
    t_rgb rgb; // 0 - 255
    // t_utils 
    struct s_plane *next;
}   t_plane;

// typedef union u_object
// {
// 	t_sphere	sphere;
// 	t_plane		plane;
// 	t_cylinder	cylinder;
// }	t_obj_union;

typedef struct s_utils
{
    t_vec x;
    t_vec y;
    t_vec z;
    t_vec coord;
    // t_obj_id id;
    // t_obj_union objects;
    struct s_utils *next;
    // clcor;
}   t_utils;

typedef struct s_base
{
    t_amb *a_amb;
    t_camera *a_camera;
    t_light  *a_light;
    t_sphere *a_sphere;
    t_cylinder *a_cylinder;
    t_plane *a_plane;
    t_utils *obj;
    t_img_data img_data;
}   t_base;

typedef struct s_param
{
    int   max;
    float end_x;
    float end_y;
    float start_x;
    float start_y;
}   t_param;

typedef struct s_matrix_trans
{
    float rot[4][4];
    float pos[4][4];
    float tranc[4][4];
}   t_matrix_tranc;

typedef struct s_ray
{
    t_vec   or;
    t_vec   dir;
}   t_ray;

typedef struct s_rt
{
    float widht;
    float height;
    float cam_matrix[4][4];
    float aspectratio;
    t_camera cam;
    t_utils *obj;
}   t_rt;

typedef struct s_hit
{
	t_vec	*nhit;
	t_vec	*phit;
	t_rgb	*color;
	float	t;
}	t_hit;

typedef struct s_test
{
    int a;
}   t_test;

#endif
