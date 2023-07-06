/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaghazar <vaghazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 12:37:06 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/07/06 18:48:57 by vaghazar         ###   ########.fr       */
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
		else if (ft_strchr(SPACES, *str) || *str == '\n')
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
	unsigned char flag = 0;
	
	line = get_next_line(fd);
	while (line && *line)
	{
		str = ft_strtrim(line, SPACES); // TODO free str
		if (*str == 'A' || *str == 'L' || *str == 'C')
		{
			arr = helper(str, 1);
			if (*str == 'A')
			{
				ambient_lightning(obj->a_amb, arr); //arayjm aysqany :D
				if (flag & 4)
					print_exit_error("erkrord angam\n");
				else
					flag |= 4;
			}
			if (*str == 'C')
			{
				camera(obj->a_camera, arr);
				if (flag & 2)
					print_exit_error("erkrord angam\n");
				else
					flag |= 2;
			}
			if (*str == 'L')
			{
				light(obj->a_light, arr);
				if (flag & 1)
					print_exit_error("erkrord angam\n");
				else
					flag |= 1;
			}
		}
		else if (*str && *str != '\n')
		{
			if ((ft_strncmp(str, "pl", 2) == 0) ||  (ft_strncmp(str, "sp", 2) == 0) ||
			 (ft_strncmp(str, "cy", 2) == 0))
			{
				flag |= 8;
				arr = helper(str, 2);
				if ((ft_strncmp(str, "pl", 2) == 0))
					plane(&obj->a_plane, arr);
				if ((ft_strncmp(str, "sp", 2) == 0))
					sphere(&obj->a_sphere, arr);
				if ((ft_strncmp(str, "cy", 2) == 0))
				{
					cylinder(&obj->a_cylinder, arr);
					// print_list_cy(obj->a_cylinder);
				}
			}
			else
				print_error_exit("eli sxal argument\n");
		}
		// free(line); 
		line = get_next_line(fd);
	}
	if (flag != 15)
		print_error_exit("ERROR_flag_not_7\n");
}
