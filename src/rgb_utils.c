/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavardan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 20:34:02 by mavardan          #+#    #+#             */
/*   Updated: 2023/08/02 11:46:58 by mavardan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "../includes/struct.h"
#include "../includes/utils.h"
#include "../includes/minirt.h"

t_rgb	*rgb_from_ints(int r, int g, int b)
{
	t_rgb	*rgb;

	if (!is_int_in_range(r, 0, 255) || !is_int_in_range(g, 0, 255) || \
			!is_int_in_range(b, 0, 255))
		print_error_exit("RGB value is out of range");
	rgb = malloc(sizeof(t_rgb));
	if (!rgb)
		print_error_exit("Allocation error");
	rgb->r = r;
	rgb->g = g;
	rgb->b = b;
	return (rgb);
}

t_rgb	*mul_rgb(t_rgb *rgb, float mul)
{
	int	r;
	int	g;
	int	b;

	if (mul > 255)
		mul = 255;
	if (mul < 0)
		return (rgb_from_ints(0, 0, 0));
	r = min(rgb->r * mul, 255);
	g = min(rgb->g * mul, 255);
	b = min(rgb->b * mul, 255);
	return (rgb_from_ints(r, g, b));
}

t_rgb	*sum_rgb(t_rgb *rgb1, t_rgb *rgb2)
{
	int	r;
	int	g;
	int	b;

	r = max(rgb1->r + rgb2->r, 255);
	g = max(rgb1->g + rgb2->g, 255);
	b = max(rgb1->b + rgb2->b, 255);
	return (rgb_from_ints(r, g, b));
}

t_rgb	*sub_rgb(t_rgb *rgb1, t_rgb *rgb2)
{
	int	r;
	int	g;
	int	b;

	r = max(rgb1->r - rgb2->r, 0);
	g = max(rgb1->g - rgb2->g, 0);
	b = max(rgb1->b - rgb2->b, 0);
	return (rgb_from_ints(r, g, b));
}

int	rgb_to_int(t_rgb *rgb)
{
	return (rgb->r << 16 | rgb->g << 8 | rgb->b);
}

t_rgb	*int_to_rgb(int col)
{
	int	r;
	int	g;
	int	b;

	b = col & 255;
	g = (col >> 8) & 255;
	r = (col >> 16) & 255;
	return (rgb_from_ints(r, g, b));
}
