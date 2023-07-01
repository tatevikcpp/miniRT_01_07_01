/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 12:37:52 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/06/25 12:37:53 by tkhechoy         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

char *func(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			if (!is_space(str[i]))
				i++;
			else
			{
				if ((str[i - 1] == '.' || str[i - 1] == ',') ||
					(str[i + 1] == '.' || str[i + 1] == ','))
					print_error_exit("space error\n");
				i++;
			}
		}
    }
	return (str);
}