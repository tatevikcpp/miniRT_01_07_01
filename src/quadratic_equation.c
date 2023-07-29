#include "minirt.h"

static void    swap(float x0, float x1)
{
    float tmp;

    tmp = x0;
    x0 = x1;
    x1 = tmp;
}

t_bool solveQuadratic(const float a, const float b, const float c, float x0, float x1)
{
    float discr;
    float q;

    discr = b * b - 4 * a * c;
    if (discr < 0) 
        return (FALSE);
    else if (discr == 0)
    {
        x0 = - 0.5 * b / a;
        x1 = - 0.5 * b / a;
    }
    else
    {
        if (b > 0)
            q = -0.5 * (b + sqrt(discr));
        else
            q = -0.5 * (b - sqrt(discr));
        x0 = q / a;
        x1 = c / q;
    }
    if (x0 > x1) 
        swap(x0, x1);
    return (TRUE);
}