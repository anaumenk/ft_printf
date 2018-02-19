/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:03:32 by anaumenk          #+#    #+#             */
/*   Updated: 2017/11/10 14:03:34 by anaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	k;

	i = 0;
	k = c;
	while (s[i])
	{
		if (s[i] == k)
			return ((char*)&s[i]);
		i++;
	}
	if (k == '\0' && s[i] == k)
		return ((char*)&s[i]);
	return (NULL);
}
