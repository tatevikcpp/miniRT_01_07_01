/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_libft_obj.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 12:17:37 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/08/05 12:18:10 by mavardan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_lstadd_front_obj(t_utils **lst, t_utils *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

void	ft_lstadd_back_obj(t_utils **lst, t_utils *new)
{
	t_utils	*new_node;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	new_node = ft_lstlast_obj(*lst);
	new_node->next = new;
}

t_utils	*ft_lstlast_obj(t_utils *lst)
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

t_utils	*ft_lstnew_obj(void)
{
	t_utils	*obj;

	obj = (t_utils *)ft_calloc(sizeof(t_utils), 1);
	if (!obj)
		return (NULL);
	return (obj);
}
