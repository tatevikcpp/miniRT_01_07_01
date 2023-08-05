/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 02:46:43 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/08/05 01:20:04 by mavardan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdlib.h>

void	free_matrix(char **arr)
{
	int	i;

	i = 0;
	if (arr)
	{
		while (arr[i])
		{
			free(arr[i]);
			i++;
		}
	}
	free(arr);
}

static void	free_plane(t_plane *obj)
{
	t_plane	*tmp;

	while (obj)
	{
		tmp = obj;
		obj = obj->next;
		free(tmp);
	}
}

void	free_base(t_base *obj)
{
	free(obj->a_amb);
	free(obj->a_camera);
	free(obj->a_light);
	// free(obj->a_plane);
	free_plane(obj->a_plane);
	free(obj->a_sphere);
	free(obj->a_cylinder);
	free(obj->a_sphere);
	// free_plane(obj->a_plane);
}

// void	free_hit(t_hit *obj)
// {
// 	free(obj->nhit);
// 	obj->nhit = NULL;
// 	free(obj->phit);
// 	obj->phit = NULL;
// 	free(obj);
// 	obj = NULL;
// }
