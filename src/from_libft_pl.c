/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_libft_pl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaghazar <vaghazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 20:29:27 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/07/06 18:11:55 by vaghazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_lstadd_front_pl(t_plane **lst, t_plane *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

void	ft_lstadd_back_pl(t_plane **lst, t_plane *new)
{
	t_plane	*new_node;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	new_node = ft_lstlast_pl(*lst);
	new_node->next = new;
}

t_plane	*ft_lstlast_pl(t_plane *lst)
{
	if (!lst)
		return (0);
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

t_plane	*ft_lstnew_pl(void)
{
	t_plane	*obj;

	obj = (t_plane *)ft_calloc(sizeof(t_plane), 1);
	if (!obj)
		return (NULL);
	return (obj);
}
