/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_checkings.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 17:54:19 by mavardan          #+#    #+#             */
/*   Updated: 2023/08/05 05:11:45 by tkhechoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "minirt.h"
#include <stdio.h>
#include <float.h>
#include "../libft/libft.h"

static int	is_str_float(char *s)
{
	int	i;
	int	is_dot;
	int	len;

	i = 0;
	is_dot = 0;
	len = ft_strlen(s);
	if (!s || ('-' == s[0] && len < 4) || ('-' != s[0] && len < 3))
		return (0);
	if ('-' == s[0] && '.' == s[++i])
		return (0);
	while (s[i])
	{
		if (!ft_isdigit(s[i]) && ('.' != s[i]))
			return (0);
		if ('.' == s[i] && (is_dot || 0 == i || len - 1 == i))
			return (0);
		if ('.' == s[i])
			is_dot = 1;
		++i;
	}
	return (1);
}

static int	is_str_float_wo_point(char *s)
{
	int	i;
	int	is_dot;
	int	len;

	if (!s)
		return (0);
	len = ft_strlen(s);
	i = 0;
	if ('-' == s[i])
	{
		if (len > 1 && '0' == s[i + 1])
			return (0);
		++i;
	}
	if (len - i < 1)
		return (0);
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		++i;
	}
	if (len != 1 && '0' == s[0])
		return (0);
	return (1);
}

float	str_to_float(char *s)
{
	float	res;
	float	div;
	int		sign;
	int		i;

	sign = 1;
	res = 0;
	div = 10;
	i = 0;
	if ('-' == s[i] && ++i)
		sign = -1;
	while (s[i] >= '0' && s[i] <= '9')
		res = res * 10 + s[i++] - '0';
	if ('.' == s[i])
		++i;
	while (s[i] >= '0' && s[i] <= '9')
	{
		res += (s[i++] - '0') / div;
		div *= 10;
	}
	return (res * sign);
}

static double	str_to_double(char *s)
{
	double	res;
	double	div;
	int		sign;
	int		i;

	sign = 1;
	res = 0;
	div = 10;
	i = 0;
	if ('-' == s[i] && ++i)
		sign = -1;
	while (s[i] >= '0' && s[i] <= '9')
		res = res * 10 + s[i++] - '0';
	if ('.' == s[i])
		++i;
	while (s[i] >= '0' && s[i] <= '9')
	{
		res += (s[i++] - '0') / div;
		div *= 10;
	}
	return (res * sign);
}

int	is_in_float_limit(char *s)
{
	double	num;
	int		i;
	int		j;
	int		sign;

	i = 0;
	sign = 0;
	if (!s || (!is_str_float(s) && !is_str_float_wo_point(s)))
		return (0);
	if ('-' == s[i] && ++i)
		sign = 1;
	if (!is_str_float_wo_point(s))
		while ('.' != s[i])
			++i;
	if (i++ > 40)
		return (0);
	j = 0;
	while (s[i + j])
		++j;
	if (j > 6)
		return (0);
	num = str_to_double(s) * sign;
	if (num > FLT_MAX || num < -1 * FLT_MAX)
		return (0);
	return (1);
}
