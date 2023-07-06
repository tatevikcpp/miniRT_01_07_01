/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaghazar <vaghazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 12:36:55 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/07/06 18:20:30 by vaghazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

typedef struct s_rgb
{
    int r;
    int g;
    int b;
}   t_rgb;

typedef struct s_coords
{
    float x;
    float y;
    float z;
}   t_coords;

typedef struct s_Ambient_lightning
{
    float amb; // [0.0, 1.0]
    t_rgb rgb; // 0 - 255
}   t_ambient_lightning;

typedef struct s_Camera
{
    t_coords coord_view_point; // x, y, z 
    t_coords norm_orientation_vec; //[-1, 1] x, y , z
    float fov; // [0, 180]
}   t_camera;

typedef struct s_Light
{
    t_coords coord_light_point; //x, y, z
    float light_brightness; // [0.0, 1.0]
    t_rgb rgb; // 0 - 255
}   t_light;

typedef struct s_sphere
{
    t_coords coord_sphere_center;
    float sphere_diameter;
    t_rgb rgb; // 0 - 255
    struct s_sphere *next;
}   t_sphere;

typedef struct s_plane
{
    t_coords coord_point_in_plane; // x, y, z
    t_coords norm_normal_vector; // [-1, 1] x, y, z
    t_rgb rgb; // 0 - 255
    struct s_plane *next;
}   t_plane;

typedef struct s_cylinder
{
    t_coords coord_center_cy; // x, y, z
    t_coords norm_vector_cy; // [-1, 1] x, y, z
    float cy_diameter;
    float cy_height;
    t_rgb rgb; // 0 - 255
    struct s_cylinder *next;
}   t_cylinder;

typedef struct s_base
{
    t_ambient_lightning *a_amb;
    t_camera            *a_camera;
    t_light             *a_light;
    t_sphere            *a_sphere;
    t_cylinder          *a_cylinder;
    t_plane             *a_plane;
    // t_list              *a_list_cy;
    // t_list              *a_list_pl;
    // t_list              *a_list_sp;
}   t_base;

typedef struct s_test
{
    int a;
}   t_test;

