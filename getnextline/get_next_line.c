/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 14:47:28 by tkhechoy          #+#    #+#             */
/*   Updated: 2022/05/22 16:18:50 by tkhechoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_line(int fd, char **line)
{
	int		i;
	char	buf[BUFFER_SIZE + 1];

	i = 0;
	while (1)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i < 0)
			return (0);
		buf[i] = '\0';
		if (!*line)
			*line = ft_strdup(buf);
		else
			*line = ft_strjoin(*line, buf);
		if (ft_strchr(buf, '\n') || i == 0)
			break ;
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*str;
	int			i;
	char		*line;
	char		*temp;

	if (!(get_line(fd, &str)))
		return (0);
	i = ft_strlen(str) - ft_strlen(ft_strchr(str, '\n')) + 1;
	line = ft_substr(str, 0, i);
	temp = str;
	str = ft_substr(str, i, ft_strlen(str));
	free(temp);
	return (line);
}
