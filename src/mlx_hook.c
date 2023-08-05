#include <mlx.h>
#include "struct.h"
#include "defines.h"
#include "minirt.h"

int    key_press(int keycode, t_base *obj)
{
    if (keycode == KEY_X)
        rot_vec(obj->a_camera->norm,  PI/12, 'x');
    if (keycode == KEY_Y)
        rot_vec(obj->a_camera->norm,  PI/12, 'y');
    if (keycode == KEY_Z)
        rot_vec(obj->a_camera->norm,  PI/12, 'z');
    if (keycode == LEFT)
        move(obj->a_camera, MOVE_STEP, 0);
    if (keycode == RIGHT)
        move(obj->a_camera, -MOVE_STEP, 0);
    if (keycode == UP)
        move(obj->a_camera, 0, MOVE_STEP);
    if (keycode == DOWN)
        move(obj->a_camera, 0, -MOVE_STEP);
	return (1);
}
