/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 13:51:51 by tkhechoy          #+#    #+#             */
/*   Updated: 2022/05/22 16:05:46 by tkhechoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
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

char	*ft_strdup(char *str)
{
	int		i;
	char	*ptr;

	ptr = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!str || !ptr)
		return (NULL);
	i = 0;
	while (str[i])
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strjoin(char *str1, char *str2)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	i = 0;
	ptr = (char *)malloc((ft_strlen(str1)
				+ ft_strlen(str2) + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (str1[i] && str1)
	{
		ptr[i] = str1[i];
		i++;
	}
	j = 0;
	while (str2[j] && str2)
		ptr[i++] = str2[j++];
	if (str1 != NULL)
		free(str1);
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_substr(char *str, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*ptr;

	if (!str || !*str)
		return (0);
	k = ft_strlen(str);
	if (k < start || len == 0)
		i = 0;
	else if (len <= k - start)
		i = len;
	else
		i = k - start;
	ptr = (char *)malloc((i + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	j = 0;
	while (str[start] && j < i)
		ptr[j++] = str[start++];
	ptr[j] = '\0';
	return (ptr);
}
