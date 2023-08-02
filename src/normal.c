#include "minirt.h"

t_vec *norm_sp(t_vec *c, t_vec *p)
{
    t_vec *norm;

    norm = vec_sub(p, c);
    vec_normalize(norm);
    return (norm);
}