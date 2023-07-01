/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   porcnakan.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 12:37:47 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/06/25 12:37:48 by tkhechoy         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

char *ft_strcat(char *start, int len)
{
	int i;
	char *ptr;

	ptr = (char *)calloc(len + 1, sizeof(char));
	if (!ptr || !start)
		return (0);
	i = 0;
	while (i < len)
	{
		ptr[i] = *start;
		start++;
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}