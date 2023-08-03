#include <stdlib.h>
#include "../includes/struct.h"
#include "../includes/defines.h"
#include "../includes/minirt.h"


static void	compute_color_with_amb(t_rgb *p_col, t_rgb *amb_col)
{
	p_col->r = max(p_col->r - 255 + amb_col->r, 0);
	p_col->g = max(p_col->g - 255 + amb_col->g, 0);
	p_col->b = max(p_col->b - 255 + amb_col->b, 0);
}

t_rgb	*compute_color(t_base *base, t_rgb *p_col, t_hit *hit) // TODO piti vor
{
	//printf("----------------------------1111111111--------------------------------------------");
	float sum_ratio;
	float cosa;
	t_vec *light_ray;
	t_rgb *tmp;

	tmp = p_col;
	//printf("-----------------------------2222222222-------------------------------------------");

	//light_ray = vec_sub(&base->a_light->coords, hit->phit);
	//cosa = vec_dot_product(light_ray, hit->nhit) / vec_length(light_ray); 

	sum_ratio = ALBEDO + base->a_amb->amb + base->a_light->brigh * cosa;
	// sum_ratio = ALBEDO + base->a_amb->amb + base->a_light->brigh;
	p_col = mul_rgb(p_col, sum_ratio);
	// free(tmp);
	compute_color_with_amb(p_col, &base->a_amb->rgb);
	return (p_col);
}


// var n_dot_l = DotProduct(normal, vec_l);
//      if (n_dot_l > 0) 
//    intensity += light.intensity * n_dot_l / (length_n * Length(vec_l));




//t_rgb compute_light (t_base *base, t_vec *p, t_vec *norm, t_vec *view) {
//  float intensity;
//  t_rgb *amb_col;
//
//  intensity = 0;
//  var length_n = Length(normal);  // Should be 1.0, but just in case...
//  var length_v = Length(view);
//  intensity += base->a_amb->amb;
//
//  amb_color = mul_rgb(base->a_amb->rgb, base->a_amb->amb);
//  n_dot_l = dot_product(norm, L)
//            if n_dot_l > 0
//                i += light.intensity*n_dot_l/(length(N)*length(L))
//
//  /*
//
//typedef struct s_base
//{
//    t_amb *a_amb;
//    t_camera *a_camera;
//    t_light  *a_light;
//    t_sphere *a_sphere;
//    t_cylinder *a_cylinder;
//    t_plane *a_plane;
//    t_utils *obj;
//    t_img_data img_data;
//}   t_base;
//
//typedef struct s_Light
//{
//    t_obj_id	id;
//    t_vec light; //x, y, z
//    float brigh; // [0.0, 1.0]
//}   t_light;
//*/
//for (var i = 0; i < lights.length; i++) {
//    var light = lights[i];
//    if (light.ltype == Light.AMBIENT) {
//      intensity += light.intensity;
//    } else {
//      var vec_l, t_max;
//      if (light.ltype == Light.POINT) {
//    vec_l = Subtract(light.position, point);
//    t_max = 1.0;
//      } else {  // Light.DIRECTIONAL
//    vec_l = light.position;
//    t_max = Infinity;
//      }
//
//      // Shadow check.
//      var blocker = ClosestIntersection(point, vec_l, EPSILON, t_max);
//      if (blocker) {
//    continue;
//      }
//
//      // Diffuse reflection.
//      var n_dot_l = DotProduct(normal, vec_l);
//      if (n_dot_l > 0) {
//    intensity += light.intensity * n_dot_l / (length_n * Length(vec_l));
//      }
//    }
//  }
//
//  return intensity;
//}
//
///*
//var ComputeLighting = function(point, normal, view, specular) {
//  var intensity = 0;
//  var length_n = Length(normal);  // Should be 1.0, but just in case...
//  var length_v = Length(view);
//
//  for (var i = 0; i < lights.length; i++) {
//    var light = lights[i];
//    if (light.ltype == Light.AMBIENT) {
//      intensity += light.intensity;
//    } else {
//      var vec_l, t_max;
//      if (light.ltype == Light.POINT) {
//    vec_l = Subtract(light.position, point);
//    t_max = 1.0;
//      } else {  // Light.DIRECTIONAL
//    vec_l = light.position;
//    t_max = Infinity;
//      }
//
//      // Shadow check.
//      var blocker = ClosestIntersection(point, vec_l, EPSILON, t_max);
//      if (blocker) {
//    continue;
//      }
//
//      // Diffuse reflection.
//      var n_dot_l = DotProduct(normal, vec_l);
//      if (n_dot_l > 0) {
//    intensity += light.intensity * n_dot_l / (length_n * Length(vec_l));
//      }
//
//      // Specular reflection.
//      if (specular != -1) {
//    var vec_r = ReflectRay(vec_l, normal);
//    var r_dot_v = DotProduct(vec_r, view);
//    if (r_dot_v > 0) {
//      intensity += light.intensity * Math.pow(r_dot_v / (Length(vec_r) * length_v), specular);
//    }
//      }
//    }
//  }
//
//  return intensity;
//}
//*/
