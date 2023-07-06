/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_libft_cy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaghazar <vaghazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 21:46:01 by tkhechoy          #+#    #+#             */
/*   Updated: 2023/07/06 18:17:51 by vaghazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minirt.h"

void	ft_lstadd_front_cy(t_cylinder **lst, t_cylinder *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

void	ft_lstadd_back_cy(t_cylinder **lst, t_cylinder *new)
{
	t_cylinder	*new_node;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	new_node = ft_lstlast_cy(*lst);
	new_node->next = new;
}

t_cylinder	*ft_lstlast_cy(t_cylinder *lst)
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

t_cylinder	*ft_lstnew_cy(void)
{
	t_cylinder	*obj;

	obj = (t_cylinder *)ft_calloc(sizeof(t_cylinder), 1);
	if (!obj)
		return (NULL);
	return (obj);
}