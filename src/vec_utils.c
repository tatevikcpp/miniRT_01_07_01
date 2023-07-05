#include <math.h>

t_coords	*new_vec(float x, float, y, float z)
{
	t_coords	*vec;

	vec = malloc(sizeof(t_coords));
	if(!vec)
		print_error_exit("Allocation error\n");
	vex->x = x;
	vec->y = y;
	vec->z = z;
	return (vec);
}

t_coords	*vec_sum(t_coords *v1, t_coords *v2)
{
	return (new_vec(v1->x + v2->x, v1->y + v2->y, v1->z + v2->z));
}

t_coords	*vec_sub(t_coords *v1, t_coords *v2)
{
	return (new_vec(v1->x - v2->x, v1->y - v2->y, v1->z - v2->z));
}

float vec_dot_product(t_coords *v1, t_coords *v2)
{
  return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}

float vec_length(t_coords *vec)
{
  return (sqrt(dot_product(vec, vec)));
}

void vec_normalize(t_coords *vec)
{
	float len;

	len = vec_length(vec);
	vec->x /= len;
	vec->y /= len;
	vec->z /= len;
}

