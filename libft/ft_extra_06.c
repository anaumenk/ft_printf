/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra_06.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 19:30:29 by anaumenk          #+#    #+#             */
/*   Updated: 2017/11/20 19:30:31 by anaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	**extra_06(char const *s, int a, char c, char **new)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	while (s[i] && k < a)
	{
		while (s[i] == c)
			i++;
		j = 0;
		while (s[i] != c)
		{
			new[k][j] = s[i];
			j++;
			if (s[i + 1] == c || s[i + 1] == '\0')
				break ;
			i++;
		}
		new[k][j] = '\0';
		i++;
		k++;
	}
	new[k] = NULL;
	return (new);
}
