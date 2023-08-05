/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavardan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 17:56:01 by mavardan          #+#    #+#             */
/*   Updated: 2023/08/05 08:03:23 by mavardan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "../includes/defines.h"
#include "../includes/struct.h"

void	move(t_camera *cam, int x_step, int y_step)
{
	cam->coord.x += x_step;
	cam->coord.y += y_step;
}
