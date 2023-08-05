/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 08:50:53 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/08/05 06:48:26 by tkhechoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int				ft_printf(int fd,  char *str, ...);
int				ft_convert(va_list arg,  char form, int fd);
int				ft_print_percent(int fd);
int				ft_s(char *str, int fd);
int				ft_c(char c, int fd);
int				ft_xl(unsigned int n, int fd);
int				ft_xu(unsigned int n, int fd);
int				ft_u(unsigned int n, int fd);
int				ft_p(unsigned long int n, int fd);
int				ft_d(int n, int fd);
int				ft_nbr_count(long long int n,  char *base, int fd);
unsigned int	ft_strlen_ft(char  *str);

#endif
