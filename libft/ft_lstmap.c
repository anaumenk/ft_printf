/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:38:55 by anaumenk          #+#    #+#             */
/*   Updated: 2017/11/16 17:38:57 by anaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *list;
	t_list *begin;

	if (lst == NULL || f == NULL)
		return (NULL);
	list = f(lst);
	new = ft_lstnew(list->content, list->content_size);
	if (new == NULL)
		return (NULL);
	begin = new;
	lst = lst->next;
	while (lst != NULL)
	{
		list = f(lst);
		new->next = ft_lstnew(list->content, list->content_size);
		if (new->next == NULL)
			return (NULL);
		lst = lst->next;
		new = new->next;
	}
	return (begin);
}
