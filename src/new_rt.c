#include "minirt.h"

t_rt *new_rt(t_base *base)
{
    t_rt    *rt;

    rt = ft_calloc(sizeof(t_rt), 1);
    rt->cam = base->a_camera;
}
