#include <mlx.h>
#include "struct.h"
#include "minirt.h"
#include "defines.h"

void    key_press(int keycode, t_base *obj)
{
    if (keycode == KEY_X)
        rot_vec(&obj->a_camera->norm,  PI/12, 'x');
    if (keycode == KEY_y)
        rot_vec(&obj->a_camera->norm,  PI/12, 'y');
    if (keycode == KEY_z)
        rot_vec(&obj->a_camera->norm,  PI/12, 'z');
}