/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 12:37:06 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/07/01 17:15:23 by tkhechoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <fcntl.h>

static char *func_space(char *str)
{
	char *new;

	new = str;
	while (*str)
	{
		if (!ft_strchr(SPACES, *str) && !ft_strchr(NUMBERS, *str) && *str != '\n')
		{
			printf("smb /%c/\n", *str);
			print_error_exit("sxal simvol\n");
		}
		else if (ft_strchr(SPACES, *str))
			*str = '\1';
		str++;
	}
	return (new);
}

int		check_file(char *file)
{
	int 	fd;

	fd = 0;
	if (ft_strcmp(file + (ft_strlen(file) - 3), ".rt"))
		print_error_exit("error_map.rt\n");
	if (!access(file, F_OK | R_OK))
		fd = open(file, O_RDONLY);
	if (fd == -1)
		print_error_exit("error\n");
	return (fd);
}

static char **helper(char *str, int flag)
{
	char *ptr;
	char **arr;

	ptr = func_space(str + flag);
	arr = ft_split(ptr, '\1');
	return (arr);
}

void	read_map(int fd, t_base *obj)
{
	char *line;
	char *str;
	char **arr;

	line = get_next_line(fd); 
	while (*line)
	{	
		str = ft_strtrim(line, SPACES);
		if (*str == 'A' || *str == 'L' || *str == 'C')
		{
			arr = helper(str, 1);
			if (*str == 'A')
				ambient_lightning(obj->a_amb, arr); //arayjm aysqany :D
			if (*str == 'C')
				camera(obj->a_camera, arr);
			if (*str == 'L')
				light(obj->a_light, arr);
		}
		else if (*str && *str != '\n')
		{
			if ((ft_strncmp(str, "pl", 2) == 0) ||  (ft_strncmp(str, "sp", 2) == 0) ||
			 (ft_strncmp(str, "cy", 2) == 0))
			{
				arr = helper(str, 2);
				if ((ft_strncmp(str, "pl", 2) == 0))
					plane(obj->a_plane, arr);
				if ((ft_strncmp(str, "sp", 2) == 0))
					sphere(obj->a_sphere, arr);
				if ((ft_strncmp(str, "cy", 2) == 0))
					cylinder(/* obj->a_cylinder, */ obj, arr);
			}
			else
				print_error_exit("eli sxal argument\n");
		}
		// free(line);
		line = get_next_line(fd);
	}
}