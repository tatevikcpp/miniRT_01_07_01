/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 12:36:55 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/08/02 11:50:12 by mavardan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

//#include "minirt.h"

typedef enum e_bool {FALSE, TRUE}	t_bool;

typedef struct s_img_data	t_img_data;
typedef struct s_ray		t_ray;
typedef struct s_hit		t_hit;
typedef struct s_rt			t_rt;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
}			t_mlx;

typedef struct s_img_data
{
	void	*img;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	*addr;
}			t_img_data;

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
	int	r;
	int	g;
	int	b;
}		t_rgb;

typedef struct s_vec
{
	float	x;
	float	y;
	float	z;
}			t_vec;

typedef struct s_amb
{
	t_obj_id	id;
	t_rgb		rgb; // 0 - 255
	float		amb; // [0.0, 1.0]
}				t_amb;

typedef struct s_camera
{
	t_obj_id	id;
	t_vec		coord; // x, y, z 
	t_vec		norm; //[-1, 1] x, y , z
	float		fov; // [0, 180]
	float		scale;
}				t_camera;

typedef struct s_Light
{
	t_obj_id	id;
	t_vec		coords; //x, y, z
	t_rgb		rgb; // 0 - 255
	float		brigh; // [0.0, 1.0]
}				t_light;

typedef struct s_sphere
{
	t_obj_id		id;
	t_vec			center;
	t_rgb			rgb; // 0 - 255
	float			dm;
	float			r2;
	struct s_sphere	*next;
}					t_sphere;

typedef struct s_cylinder
{
	t_obj_id			id;
	t_vec				center; // x, y, z
	t_vec				norm; // [-1, 1] x, y, z
	t_rgb				rgb; // 0 - 255
	float				dm;
	float				rd;
	float				hg;
	t_vec				p1;
	t_vec				p2;
	struct s_cylinder	*next;
}						t_cylinder;

typedef struct s_plane
{
	t_obj_id		id;
	t_vec			coord; // x, y, z ?
	t_vec			norm; // [-1, 1] x, y, z
	t_rgb			rgb; // 0 - 255
	// t_utils 
	struct s_plane	*next;
}					t_plane;

// typedef union u_object
// {
// 	t_sphere	sphere;
// 	t_plane		plane;
// 	t_cylinder	cylinder;
// }	t_obj_union;

typedef struct s_hit
{
	t_vec	*nhit;
	t_vec	*phit;
	t_rgb	color;
	void	*obj;
	t_obj_id	obj_type;
	float	t;
}			t_hit;

typedef struct s_ray
{
	t_vec	or;
	t_vec	dir;
	t_hit	hit;
}			t_ray;

typedef struct s_utils
{
	t_vec			x;
	t_vec			y;
	t_vec			z;
	t_vec			coord;
	// t_obj_id id;
	// t_obj_union objects;
	t_ray			ray;
	struct s_utils	*next;
	// clcor;
}					t_utils;

typedef struct s_base
{
	t_amb		*a_amb;
	t_camera	*a_camera;
	t_light		*a_light;
	t_sphere	*a_sphere;
	t_cylinder	*a_cylinder;
	t_plane		*a_plane;
	t_utils		*utils;
	t_img_data	img_data;
	t_rt		*rt;
	t_mlx		mlx;
}				t_base;

typedef struct s_param
{
	float	end_x;
	float	end_y;
	float	start_x;
	float	start_y;
	int		max;
}			t_param;

typedef struct s_matrix_trans
{
	float	rot[4][4];
	float	pos[4][4];
	float	trans[4][4];
}			t_matrix_trans;

typedef struct s_rt
{
	t_camera	*cam;
	t_vec		*forward;
	t_vec		*right;
	t_vec		*up;
	float		inverse_view;
	float		cam_matrix[4][4];
	float		aspectratio;
	int			widht;
	int			height;
}				t_rt;

typedef struct s_quadratic
{
	float	a;
	float	b;
	float	c;
	float	x1;
	float	x2;
}	t_quadratic;

typedef struct s_test
{
	int	a;
}		t_test;

#endif
