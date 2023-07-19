/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tumolabs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 20:34:02 by tumolabs          #+#    #+#             */
/*   Updated: 2023/07/19 19:09:04 by tumolabs         ###   ########.fr       */
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
	r = (int)fmax(rgb->r * mul, 255);
	g = (int)fmax(rgb->g * mul, 255);
	b = (int)fmax(rgb->b * mul, 255);
	return (rgb_from_ints(r, g, b));
}
