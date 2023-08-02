#include "minirt.h"


t_hit    *get_closest_sp(t_base *base, t_hit *hit, t_ray *ray)
{
    t_sphere *tmp;
    t_hit *min_obj;
    float min_len;
    float len;
    

    min_len = 0;
    min_obj = NULL;
    tmp = base->a_sphere;
    while (tmp)
    {
        if (sphere_intersect(ray, tmp, hit))
        {
            len = vec_length(vec_sub(hit->phit, &base->a_light->coords));
            if (len < min_len)
            {
                min_len = len;
                min_obj->obj = (void *)tmp;
            }
        }
        tmp = tmp->next;
    }
    return (min_obj);
}



// int	intersect(t_ray *ray, void *obj, t_hit *hit)
// {
// 	if ((t_sphere *)obj->id == id_sphere)
// 		return(sphere_intersect(ray, obj->a_sphere, hit));
// 	if ((t_plane *)obj->id == id_plane)
// 		return (plane_intersect(ray, obj->a_plane, hit));
// 	if ((t_cylinder *)obj->id = id_cylinder)
// 		return (cylinder_intersect(lalala)); // TODO
// 	return (0);
// }