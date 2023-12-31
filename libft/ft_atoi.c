/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 20:37:18 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/08/05 13:59:12 by mavardan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"
#include "../ft_printf/ft_printf.h"

long long	ft_atoi(char *str)
{
	int			i;
	int			j;
	long long	res;

	i = 0;
	res = 0;
	j = 1;
	while (str && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || \
		str[i] == '\v' || str[i] == '\f' || str[i] == '\r'))
		i++;
	if (ft_strlen(str) > 13)
		ft_printf(2, "error atoi\n");
	if (str && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			j *= -1;
		i++;
	}
	while (str && (str[i] >= '0' && str[i] <= '9'))
		res = res * 10 + str[i++] - '0';
	if (res * j > INT_MAX)
		res = INT_MAX;
	else
		res = res * j;
	return (res);
}
