:q/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:42:54 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/08/02 11:49:24 by mavardan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count(unsigned long int nbr, const char *base, int fd)
{
	int	counter;

	counter = 0;
	if (nbr >= ft_strlen_ft(base))
		counter = counter + ft_nbr_count(nbr / ft_strlen_ft(base), base, fd);
	counter = counter + write(fd, &base[nbr % ft_strlen_ft(base)], 1);
	return (counter);
}

int	ft_p(unsigned long int c, int fd)
{
	int	counter;

	counter = 0;
	counter += write(fd, "0x", 2);
	counter += count(c, "0123456789abcdef", fd);
	return (counter);
}
