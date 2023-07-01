/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 12:37:36 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/07/01 17:25:58 by tkhechoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void init_all(t_base *obj)
{
  if (!obj)
  	print_error_exit("chak init obj\n");
  init_base(obj);
  init_amb(obj->a_amb);
  init_camera(obj->a_camera);
  init_light(obj->a_light);
  init_sphere(obj->a_sphere);
  init_cylinder(obj->a_cylinder);
  init_plane(obj->a_plane);
}

int main(int c, char **v)
{
    t_base *obj = (t_base *)ft_calloc(sizeof(t_base), 1);
    if (!obj)
		print_error_exit("chka obj main\n");
    if (c != 2)
        print_error_exit("error argument\n");
    init_all(obj);
    read_map(check_file(v[1]), obj);
	struct_tree(obj);
	printf("\n---------******----------\n\n");
	printf("flot = %d\n", is_in_float_limit("5"));

  print_list(obj->a_list_cy);
    return (0);
}