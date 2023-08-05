/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 19:00:04 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/08/05 06:48:26 by tkhechoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr( char	*s, int c)
{
	int		i;
	int		j;
	char	l;

	l = c;
	j = 0;
	i = 0;
	while (s[i] != '\0')
	{
		j++;
		i++;
	}
	while (j >= 0)
	{
		if (s[j] == l)
			return ((char *)&s[j]);
		j--;
	}
	return (NULL);
}
