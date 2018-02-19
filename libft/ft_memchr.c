/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 19:55:53 by anaumenk          #+#    #+#             */
/*   Updated: 2017/10/27 19:55:54 by anaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*d;
	size_t			i;
	unsigned char	k;

	d = (unsigned char*)s;
	i = 0;
	k = c;
	while (i < n)
	{
		if (d[i] == k)
			return (&d[i]);
		i++;
	}
	return (NULL);
}
