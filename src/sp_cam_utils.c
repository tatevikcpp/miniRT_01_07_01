/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_cam_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavardan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 20:28:47 by mavardan          #+#    #+#             */
/*   Updated: 2023/07/12 20:57:26 by mavardan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/struct.h"
#include "../includes/minirt.h"

t_sphere	*new_sphere(t_vec *center, float diameter, t_rgb *rgb)
{
	t_sphere *sp;

	sp = malloc(sizeof(t_sphere));
	if (!sp)
		print_error_exit("Allocation error");
	sp->center = *center;
	sp->dm = diameter;
	sp->rgb = *rgb;
	sp->next = NULL;
	return (sp);
}

// z = -1
t_camera	*new_cam(t_vec *view_v, t_vec *norm_v, float fov)
{
	t_camera	*cam;

	cam = malloc(sizeof(t_camera));
	if (!cam)
		print_error_exit("Allocation error");
	cam->view = *view_v;
	cam->norm = *norm_v;
	cam->fov = fov;
	return (cam);
}
