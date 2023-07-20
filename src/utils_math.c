/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tumolabs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:46:25 by tumolabs          #+#    #+#             */
/*   Updated: 2023/07/20 21:00:44 by tumolabs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	solve_quadratic_eq(float a, float b, float c, float *x1, float *x2)
{
	float	discr;

	discr = b * b - 4 * a *c;
	if (discr < 0)
		return (0);
	if (0 == discr)
	{
		*x1 = -b / (2 * a);
		*x2 = *x1;
	}
	else
	{
		*x1 = (-b + sqrt(discr)) / (2 * a);
		*x2 = (-b - sqrt(discr)) / (2 * a);
	}
	return (1);
}
