/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_libft_sp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkhechoy <tkhechoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 21:45:38 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/08/05 12:17:07 by mavardan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	ft_lstadd_front_sp(t_sphere **lst, t_sphere *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

void	ft_lstadd_back_sp(t_sphere **lst, t_sphere *new)
{
	t_sphere	*new_node;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	new_node = ft_lstlast_sp(*lst);
	new_node->next = new;
}

t_sphere	*ft_lstlast_sp(t_sphere *lst)
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

t_sphere	*ft_lstnew_sp(void)
{
	t_sphere	*obj;

	obj = (t_sphere *)ft_calloc(sizeof(t_sphere), 1);
	if (!obj)
		return (NULL);
	return (obj);
}
