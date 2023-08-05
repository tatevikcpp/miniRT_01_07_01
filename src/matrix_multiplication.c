/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_multiplication.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 10:29:17 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/08/05 10:32:01 by mavardan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	mult_matrix(float A[4][4], float B[4][4]) // TODO return res_mat[][] ?
{
	float	res_mat[4][4];
	int		mult;
	int		i;
	int		j;
	int		k;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			mult = 0;
			k = 0;
			while (k < 4)
			{
				mult += A[i][k] * B[k][j];
				k++;
			}
			res_mat[i][j] = mult;
			printf("%f\n", res_mat[i][j]);
			j++;
		}
		i++;
	}
}
