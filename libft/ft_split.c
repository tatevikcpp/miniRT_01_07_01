/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 18:15:29 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/08/05 06:48:26 by tkhechoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_sub_str(char 	*str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str && str[i] != '\0')
	{
		if (str[i] == c && str[i + 1] != c && str[i + 1] != '\0')
			count++;
		i++;
	}
	if (count == 0 || str[0] != c)
		count++;
	return (count);
}

char	*word_dup(char 	*str, int start, int finish)
{
	int		i;
	char	*word;

	word = (char *)malloc(sizeof(char) * (finish - start + 1));
	i = 0;
	while (start < finish)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char 	*s, char c)
{
	int				i;
	int				j;
	int				index;
	char			**split;

	split = (char **)ft_calloc (sizeof(char *), (count_sub_str(s, c) + 1));
	if (!s || !split)
		return (NULL);
	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			split[j++] = word_dup(s, index, i);
			index = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}
