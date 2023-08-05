/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavardan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 10:14:56 by mavardan          #+#    #+#             */
/*   Updated: 2023/08/05 10:16:16 by mavardan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>
#include "struct.h"
#include "defines.h"
#include "minirt.h"

int	key_press(int keycode, t_base *obj)
{
	float	pi;

	pi = acos(-1);
	if (keycode == KEY_X)
		rot_vec(obj->a_camera->norm, pi / 12, 'x');
	if (keycode == KEY_Y)
		rot_vec(obj->a_camera->norm, pi / 12, 'y');
	if (keycode == KEY_Z)
		rot_vec(obj->a_camera->norm, pi / 12, 'z');
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
