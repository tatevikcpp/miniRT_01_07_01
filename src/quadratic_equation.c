#include "minirt.h"

static void    swap(float x0, float x1)
{
    float tmp;

    tmp = x0;
    x0 = x1;
    x1 = tmp;
}

t_bool solve_quadratic_eq(const float a, const float b, const float c, float t0, float t1)
{
    float discr;
    float q;

    discr = b * b - 4 * a * c;
    if (discr < 0) 
        return (FALSE);
    else if (discr == 0)
    {
        t0 = - 0.5 * b / a;
        t1 = - 0.5 * b / a;
    }
    else
    {
        if (b > 0)
            q = -0.5 * (b + sqrt(discr));
        else
            q = -0.5 * (b - sqrt(discr));
        t0 = q / a;
        t1 = c / q;
    }
    if (t0 > t1) 
        swap(t0, t1);
    return (TRUE);
}