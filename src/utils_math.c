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

//use t_vec due to norminette limit for 4 arguments
int	quadratic_eq_solution(t_vec *vec, float *x1, float *x2)
{
	float	a;
	float	b;
	float	c;
	float	discr;

	a = t->x;
	b = t->y;
	c = t->z;
	if (0 == a)
		print_error_exit("Try to divide by 0");

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
