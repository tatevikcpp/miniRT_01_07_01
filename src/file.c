/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 12:37:06 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/08/05 10:48:25 by mavardan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <fcntl.h>

static char	*func_space(char *str)
{
	char	*new;

	new = str;
	while (*str)
	{
		if (!ft_strchr(SPACES, *str) && !ft_strchr(NUMBERS, *str) && *str != '\n')
		{
			print_error_exit("Invalid symbol in map file");
		}
		else if (ft_strchr(SPACES, *str) || *str == '\n')
			*str = '\1';
		str++;
	}
	return (new);
}

int	check_file(char *file)
{
	int	fd;

	fd = 0;
	if (ft_strcmp(file + (ft_strlen(file) - 3), ".rt"))
		print_error_exit("File extension must be .rt");
	if (!access(file, F_OK | R_OK))
		fd = open(file, O_RDONLY);
	else
		print_error_exit("File access error");
	if (fd == -1)
		print_error_exit("File descriptor error");
	return (fd);
}

static char	**helper(char *str, int flag)
{
	char	*ptr;
	char	**arr;

	ptr = func_space(str + flag);
	arr = ft_split(ptr, '\1');
	return (arr);
}

static unsigned char	nor_alc(char **arr, t_base *obj, char *str, int flag)
{
	arr = helper(str, 1);
	if (*str == 'A')
	{
		ambient_lightning(obj->a_amb, arr); //arayjm aysqany :D
		free_matrix(arr);
		if (flag & 4)
			print_error_exit("Ambient light is specified twice");
		else
			flag |= 4;
	}
	if (*str == 'C')
	{
		camera(obj->a_camera, arr);
		free_matrix(arr);
		if (flag & 2)
			print_error_exit("Camera is specified twice");
		else
			flag |= 2;
	}
	if (*str == 'L')
	{
		light(obj->a_light, arr);
		free_matrix(arr);
		if (flag & 1)
			print_error_exit("Light is specified twice");
		else
			flag |= 1;
	}
	return (flag);
}

static unsigned char	nor_cps(char **arr, t_base *obj, char *str, int flag)
{
	flag |= 8;
	arr = helper(str, 2);
	if ((ft_strncmp(str, "pl", 2) == 0))
	{
		plane(&obj->a_plane, arr);
		free_matrix(arr);
	}
	if ((ft_strncmp(str, "sp", 2) == 0))
	{
		sphere(&obj->a_sphere, arr);
		free_matrix(arr);
	}
	if ((ft_strncmp(str, "cy", 2) == 0))
	{
		cylinder(&obj->a_cylinder, arr);
		free_matrix(arr);
	}
	return (flag);
}

void	read_map(int fd, t_base *obj, int flag)
{
	char	*line;
	char	*str;
	char	**arr;

	arr = 0;
	flag = 0;
	line = get_next_line(fd);
	while (line && *line)
	{
		str = ft_strtrim(line, SPACES); // TODO free str
		if (*str == 'A' || *str == 'L' || *str == 'C')
			flag = nor_alc(arr, obj, str, flag);
		else if (*str && *str != '\n')
		{
			if ((ft_strncmp(str, "pl", 2) == 0) || (ft_strncmp(str, "sp", 2) == 0) || \
					(ft_strncmp(str, "cy", 2) == 0))
				flag = nor_cps(arr, obj, str, flag);
			else
				print_error_exit("Invalid element is specified");
		}
		free(line);
		free(str);
		line = get_next_line(fd);
	}
	if (flag != 15)
		print_error_exit("Missing component in map file");
}
