/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:38:21 by anaumenk          #+#    #+#             */
/*   Updated: 2017/11/16 17:38:22 by anaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *new;

	if (alst == NULL || del == NULL)
		return ;
	new = *alst;
	while (*alst != NULL)
	{
		del((*alst)->content, (*alst)->content_size);
		*alst = (*alst)->next;
		free(new);
		new = new->next;
	}
}
