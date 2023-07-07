/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 02:46:43 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/07/08 02:46:44 by tkhechoy         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void    free_matrix(char **arr)
{
    int i;

    i = 0;
    if (arr)
    {
        while (arr[i])
        {
            free(arr[i]);
            i++;
        }
    }
    free(arr);
}

