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

t_vec   *ray_mult(t_vec *dst, t_ray *r, float t)
{
    dst->x = r->or.x + t * r->dir.x;
    dst->y = r->or.y + t * r->dir.y;
    dst->z = r->or.z + t * r->dir.z;
    return (dst);
}

void    build_ray(t_ray *ray, t_vec *or, t_vec *dir)
{
    ray->or.x = or->x;
    ray->or.y = or->y;
    ray->or.z = or->z;
    ray->dir.x = dir->x;
    ray->dir.y = dir->y;
    ray->dir.z = dir->z;
    vec_normalize(&ray->dir);
}

void    cam_ray(t_rt *rt, t_ray *ray, float pixel_x, float pixel_y) // TODO veranayel
{
    t_camera *cam;

    cam = &rt->cam;
    ray->or = cam->view; // kam new_vector()
    ray->dir.x = (2 * (pixel_x + 0.5) / (float)rt->widht - 1) * cam->tga * rt->aspectratio;
    ray->dir.y = (1 - 2 * (pixel_y + 0.5) / (float)rt->height) * cam->tga;
    ray->dir.z = 1; // TODO chshtell kam 0.5 ??
    ray->dir = cam_to_world(rt->cam_matrix, &ray->dir);
    vec_normalize(&ray->dir);
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

t_vec	vec_inv(t_vec v)
{
	v.x = -v.x;
	v.y = -v.y;
	v.z = -v.z;
	return (v);
}

