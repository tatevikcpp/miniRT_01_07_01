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

char	*ft_strchr_gnl(char *str, int c)
{
	int	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != (char)c)
		i++;
	if (str[i] == (char)c)
		return ((char *)&str[i]);
	return (NULL);
}

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
			*line = ft_strdup_gnl(buf);
		else
			*line = ft_strjoin_gnl(*line, buf);
		if (ft_strchr_gnl(buf, '\n') || i == 0)
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
	i = ft_strlen_gnl(str) - ft_strlen_gnl(ft_strchr_gnl(str, '\n')) + 1;
	line = ft_substr_gnl(str, 0, i);
	temp = str;
	str = ft_substr_gnl(str, i, ft_strlen_gnl(str));
	free(temp);
	return (line);
}
