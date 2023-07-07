/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 19:51:39 by tkhechoy          #+#    #+#             */
/*   Updated: 2022/05/22 16:21:32 by tkhechoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
size_t	ft_strlen_gnl(char *str);
char	*ft_strdup_gnl(char *str);
char	*ft_strchr_gnl(char *str, int c);
char	*ft_strjoin_gnl(char *str_1, char *str_2);
char	*ft_substr_gnl(char *str, unsigned int start, size_t len);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

#endif
