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

void    build_ray(t_ray *ray, t_vec *or, t_vec *dir)
{
    ray->or.x = or->x;
    ray->or.y = or->y;
    ray->or.z = or->z;
    ray->dir.x = dir->x;
    ray->dir.y = dir->y;
    ray->dir.z = dir->z;
    ray->hit.t = INFINITY;
    ray->hit.nhit = NULL;
    ray->hit.phit = NULL;
    vec_normalize(&ray->dir);
}


void    cam_ray(t_rt *rt, t_ray *ray, float pixel_x, float pixel_y) // TODO veranayel
{
    t_camera *cam;

    cam = rt->cam;
    set_vec(&ray->or, cam->coord.x, cam->coord.y, cam->coord.z);
    ray->dir.x = (2 * (pixel_x + 0.5) / (float)rt->widht - 1) * cam->scale * rt->aspectratio;
    ray->dir.y = (1 - 2 * (pixel_y + 0.5) / (float)rt->height) * cam->scale;
    ray->dir.z = 0.1; // TODO chshtell kam 0.5 ??
    ray->hit.t = INFINITY;
    ray->hit.phit = new_vec(0, 0, 0);
    ray->hit.nhit = NULL;
    // prinf_vec(&ray->dir);
    // prinf_vec(&ray->dir);
    ray->dir = cam_to_world(rt->cam_matrix, &ray->dir);
    // prinf_vec(&ray->dir);
    vec_normalize(&ray->dir);
}

