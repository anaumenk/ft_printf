/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 21:09:59 by anaumenk          #+#    #+#             */
/*   Updated: 2017/10/30 21:10:01 by anaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	int		j;
	int		a;
	int		b;

	i = 0;
	j = 0;
	a = ft_strlen(src);
	if (size == 0)
		return (a);
	while (dst[i] && i < size)
		i++;
	b = i;
	while (src[j] && i < size)
	{
		dst[i] = src[j];
		if (src[j + 1] == '\0')
			dst[i + 1] = '\0';
		if (i + 1 == size)
			dst[i] = '\0';
		i++;
		j++;
	}
	return (a + b);
}
