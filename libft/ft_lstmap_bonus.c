/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trubat-d <trubat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:15:16 by lord              #+#    #+#             */
/*   Updated: 2022/10/11 15:15:46 by trubat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*node;

	head = NULL;
	if (lst == NULL)
		return (NULL);
	head = ft_lstnew(f(lst->content));
	lst = lst->next;
	if (lst == NULL)
	{
		head->next = NULL;
		return (head);
	}
	node = ft_lstnew(f(lst->content));
	head->next = node;
	lst = lst->next;
	while (lst)
	{
		node->next = ft_lstnew(f(lst->content));
		node = node->next;
		lst = lst->next;
	}
	ft_lstclear(&lst, del);
	free(lst);
	return (head);
}
