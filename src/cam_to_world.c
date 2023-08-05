#include "minirt.h"
#include "struct.h"

t_vec	cam_to_world(float m[4][4], t_vec *v)
{
	t_vec	dst;

	dst.x = v->x * m[0][0] + v->y * m[1][0] + v->z * m[2][0];
	dst.y = v->x * m[0][1] + v->y * m[1][1] + v->z * m[2][1];
	dst.z = v->x * m[0][2] + v->y * m[1][2] + v->z * m[2][2];

	return (dst);
}


void    cam_ray(t_rt *rt, t_ray *ray, float pixel_x, float pixel_y) // TODO veranayel floatr to int
{
    t_camera *cam;
	float	a;
	float	b;
	float	c;
	int		max;

    cam = rt->cam;
    set_vec(&ray->or, cam->coord.x, cam->coord.y, cam->coord.z);
	a = pixel_x + 0.5 - (rt->widht) * 0.5;
	b = pixel_y + 0.5 - (rt->height) * 0.5;
	if (rt->widht > rt->height)
		max = rt->widht;
	else
		max = rt->height;
	c = max / (2 * tan((to_rad(cam->fov * 0.5))));
	vec_normalize(&cam->norm);
	ray->dir = vec_num_mul(cam->norm, c);
	ray->dir = vec_sum(ray->dir, vec_num_mul(new_vec(0, 1, 0), b));
	ray->dir = vec_sum(ray->dir, vec_num_mul(new_vec(1, 0, 0), a));
    ray->hit.t = INFINITY;
    ray->hit.phit = new_vec(0, 0, 0);
    ray->hit.nhit = new_vec(0, 0, 0);
    ray->hit.obj = NULL;
    vec_normalize(&ray->dir);
}


