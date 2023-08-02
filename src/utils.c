/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 12:38:09 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/08/02 11:52:30 by mavardan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_matrix(char **matrix)
{
	int	i;

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

int	count_of_rows(char **matrix)
{
	int	i;

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

int	is_float_in_range(float val, float left, float right)
{
	float	low;
	float	high;

	low = left;
	high = right;
	if (left > right)
	{
		low = right;
		high = left;
	}
	else if (left == right)
		print_error_exit("Invalid range, both boundaries are equal");
	if (val >= low && val <= high)
		return (1);
	return (0);
}

int	is_int_in_range(int val, int left, int right)
{
	int	low;
	int	high;

	low = left;
	high = right;
	if (left > right)
	{
		low = right;
		high = left;
	}
	else if (left == right)
		print_error_exit("Invalid range, both boundaries are equal");
	if (val >= low && val <= high)
		return (1);
	return (0);
}
