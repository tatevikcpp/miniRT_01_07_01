/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 12:38:09 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/06/25 12:38:10 by tkhechoy         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void print_matrix(char **matrix)
{
	int i;

	i = 0;
	if (matrix)
	{
		while (matrix[i])
		{
			printf("/%s/\n", matrix[i]);
			i++;
		}
	}
}

int count_of_rows(char **matrix)
{
	int i;
	
	i = 0;
	if (matrix)
	{
		while (matrix[i])
			i++;
	}
	return (i);
}

int	is_space(char c)
{
	if (ft_strchr(SPACES, c))
		return (1);
	return (0);
}