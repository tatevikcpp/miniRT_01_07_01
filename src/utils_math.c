/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavardan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:46:25 by mavardan          #+#    #+#             */
/*   Updated: 2023/08/02 12:17:33 by mavardan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
// #include <math.h>

void	swap(float *x1, float *x2)
{
	float	tmp;

	tmp = *x1;
	*x1 = *x2;
	*x2 = tmp;
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

float	min(float a, float b)
{
	if (a < b)
		return (a);
	return (b);
}

//use t_vec due to norminette limit for 4 arguments

// int	quadratic_eq_solution(t_vec *vec, float *x1, float *x2)
// {
// 	float	discr;

// 	if (0 == vec->x)
// 		print_error_exit("Try to divide by 0");
// 	discr = vec->y * vec->y - 4 * vec->x * vec->c;
// 	if (discr < 0)
// 		return (0);
// 	if (0 == discr)
// 	{
// 		*x1 = -vec->y / (2 * vec->x);
// 		*x2 = *x1;
// 	}
// 	else
// 	{
// 		*x1 = (-vec->y + sqrt(discr)) / (2 * vec->x);
// 		*x2 = (-vec->y - sqrt(discr)) / (2 * vec->x);
// 	}
// 	if (*x1 > *x2)
// 		swap(x1, x2);
// 	return (1);
// }

float	to_rad(const float angle)
{
	return (angle * PI / 180);
}

int	quadratic_eq_solution(t_quadratic *q)
{
	float	discr;

	if (0 == q->a)
		print_error_exit("Try to divide by 0");
	discr = q->b * q->b - 4 * q->a * q->c;
	if (discr < 0)
		return (0);
	if (0 == discr)
	{
		q->x1 = -q->b / (2 * q->a);
		q->x2 = q->x1;
	}
	else
	{
		q->x1 = (-q->b + sqrt(discr)) / (2 * q->a);
		q->x2 = (-q->b - sqrt(discr)) / (2 * q->a);
	}
	if (q->x1 > q->x2)
		swap(&q->x1, &q->x2);
	return (1);
}
