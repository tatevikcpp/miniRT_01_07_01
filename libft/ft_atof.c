/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavardan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 13:47:11 by mavardan          #+#    #+#             */
/*   Updated: 2023/08/05 13:48:20 by mavardan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

float	ft_atof(char *str)
{
	float	res;
	int		sgn;
	int		div;

	sgn = 1;
	res = 0;
	div = 10;
	if (!str || *str == '\0')
		return (0);
	while (ft_strchr(SPACES, *str))
		str++;
	if (*str == '-')
		sgn = -1;
	while (*str >= '0' && *str <= '9')
		res = res * 10 + *str++ - '0';
	if (*str++ != '.')
		return (sgn * res);
	while (*str >= '0' && *str <= '9')
	{
		res += ((float)(*str++ - '0')) / div;
		div *= 10;
	}
	return (res * sgn);
}
