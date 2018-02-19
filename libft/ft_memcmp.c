/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 18:19:12 by anaumenk          #+#    #+#             */
/*   Updated: 2017/10/30 18:19:14 by anaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*d1;
	unsigned char	*d2;
	size_t			i;

	i = 0;
	d1 = (unsigned char*)s1;
	d2 = (unsigned char*)s2;
	if (n == 0)
		return (0);
	while (d1[i] == d2[i] && i < n)
	{
		if (i + 1 == n)
			return (0);
		i++;
	}
	return (d1[i] - d2[i]);
}
