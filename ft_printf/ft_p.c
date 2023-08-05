/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:42:54 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/08/05 06:48:26 by tkhechoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count(unsigned long int nbr,  char *base, int fd)
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
