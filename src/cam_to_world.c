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

