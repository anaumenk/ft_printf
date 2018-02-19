/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:57:29 by anaumenk          #+#    #+#             */
/*   Updated: 2017/11/13 17:57:30 by anaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char	**split(char const *s, int a, char c, char **new)
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

static char	**chars(char const *s, char c, char **new, int a)
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
			j++;
			if (s[i + 1] == c || s[i + 1] == '\0')
				break ;
			i++;
		}
		new[k] = (char*)malloc(sizeof(char) * (j + 1));
		k++;
		i++;
	}
	return (new);
}

static int	words(char const *s, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
		{
			if (s[i + 1] == '\0')
				return (j);
			i++;
		}
		while (s[i] != c && s[i])
		{
			if (s[i + 1] == c || s[i + 1] == '\0')
				j++;
			i++;
		}
		i++;
	}
	return (j);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**new;
	int		a;

	if (s == NULL)
		return (NULL);
	a = words(s, c);
	new = (char**)malloc(sizeof(char*) * (a + 1));
	if (new == NULL)
		return (NULL);
	if (a == 0)
	{
		new[0] = NULL;
		return (new);
	}
	new = chars(s, c, new, a);
	new = split(s, a, c, new);
	return (new);
}
