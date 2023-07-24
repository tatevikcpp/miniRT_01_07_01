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
    float amb; // [0.0, 1.0]
    t_rgb rgb; // 0 - 255
}   t_amb;

typedef struct s_Camera
{
    t_vec view; // x, y, z 
    t_vec norm; //[-1, 1] x, y , z
    float fov; // [0, 180]
}   t_camera;

typedef struct s_Light
{
    t_vec light; //x, y, z
    float brigh; // [0.0, 1.0]
    t_rgb rgb; // 0 - 255
}   t_light;

typedef struct s_sphere
{
    t_vec center;
    float dm;
    t_rgb rgb; // 0 - 255
    struct s_sphere *next;
}   t_sphere;

typedef struct s_plane
{
    t_vec coord; // x, y, z ?
    t_vec norm; // [-1, 1] x, y, z
    t_rgb rgb; // 0 - 255
    struct s_plane *next;
}   t_plane;

typedef struct s_cylinder
{
    t_vec center; // x, y, z
    t_vec norm; // [-1, 1] x, y, z
    float dm;
    float hg;
    t_rgb rgb; // 0 - 255
    struct s_cylinder *next;
}   t_cylinder;

typedef struct s_base
{
    t_amb *a_amb;
    t_camera *a_camera;
    t_light  *a_light;
    t_sphere *a_sphere;
    t_cylinder *a_cylinder;
    t_plane *a_plane;
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
}   t_matrix_tranc


typedef struct s_test
{
    int a;
}   t_test;

#endif
