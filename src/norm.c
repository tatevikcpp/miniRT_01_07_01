#include "minirt.h"


void	cylinder_norm(t_cylinder *cy)
{
	vec_normalize(&cy->norm);
	cy->rd = cy->dm * cy->dm * 0.25;
	// cy->delta_p = vect_mul(cy->orient, cy->height);
	// cy->p1 = vect_mul(cy->orient, -0.5 * cy->height);
	// cy->p1 = vect_add(cy->p1, cy->coords);
	// cy->p2 = vect_mul(cy->orient, 0.5 * cy->height);
	// cy->p2 = vect_add(cy->p2, cy->coords);
}



void    function(t_rt *rt)
{
    t_camera *cam;
    t_utils *obj; // malloc

    t_vec *from = new_vec(1, 1, 1);
    t_vec *to = new_vec(200,200,20);
    cam = rt->cam;
    printf("cam->cam->fov = %f\n", cam->fov);
    cam->scale = tan(cam->fov / 2 * PI / 180);
    printf("cam->scale = %f\n", cam->scale);
    // look_at(from, to, rt);
    // look_at(rt);
    lookat(rt, *new_vec(0, 0, 6), vec_sum(new_vec(0, 0, 6), new_vec(0, 0, -1)), new_vec(0, 1, 0));
    rt->inverse_view = 
    // obj = rt->utils;
    // while (obj) 
    // {
    //     //image_param();
    //     // if (obj->id == id_sphere)
    //         // obj->objects.sphere.rd = pow(obj->objects.sphere.dm / 2, 2);
    //     // if (obj->id == id_cylinder)
    //         // cylinder_norm(&obj->objects.cylinder);
    //     //FUNC
    //     obj = obj->next;
    // }
}