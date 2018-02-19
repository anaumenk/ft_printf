/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:38:18 by anaumenk          #+#    #+#             */
/*   Updated: 2017/11/14 16:38:19 by anaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	for_malloc(unsigned long int n)
{
	int i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char		*ft_itoa(unsigned long int n)
{
	char		*s;
	int			i;

	i = for_malloc(n);
	s = (char*)malloc(sizeof(char) * (i + 1));
	if (i == 0 || s == NULL)
		return (NULL);
	s[i--] = '\0';
	while (n > 0)
	{
		s[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	return (s);
}
