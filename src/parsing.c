/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 12:37:43 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/06/25 12:37:44 by tkhechoy         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <fcntl.h>

// char *read_map(int fd, char *str)
// {
//     char *line;

//     line = NULL;
//     if (!str)
//         str = get_next_line(fd);
//     while (str)
//     {
//         if (str[0] == '\0')
//             break ;
//         line = ft_strjoin(line, str);
//         free(str);
//         str = get_next_line(fd);
//     }
//     free(str);
//     return (line);
// }

// char **get_map(char *map_name)
// {
//     int     fd;
//     char    *join_line;
//     char    *current_line;
//     char    **map;
    
//     current_line = NULL;
//     join_line = NULL;
//     map = NULL;
//     join_line = read_map(fd, current_line);
//     map = ft_split(join_line, '\n');
//     valid_map(map);//sxal- exitic heto-lalala
//     // print_matrix(map);
//     close(fd);
//     return (map);
// }

// void valid_map(char **map) //zronr meker/flag
// {
//     int i;

//     i = 0;
//     while (map && map[i] && map[i][0] && i < 3)
//     {
//         if (map[i][0] != 'A' && map[i][0] != 'C' && map[i][0] != 'L') /
//             print_error_exit("invalid argument\n");
//         i++;
//     }
//     if ((map[0][0] == map[1][0] || map[0][0] == map[2][0]) || 
//         (map[1][0] == map[0][0] || map[1][0] == map[2][0]))
//             print_error_exit("krkrnutyan error\n");
// }