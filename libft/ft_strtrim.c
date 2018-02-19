/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:55:36 by anaumenk          #+#    #+#             */
/*   Updated: 2017/11/13 16:55:38 by anaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	size(char const *s)
{
	int i;
	int j;
	int a;

	i = 0;
	j = 0;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i])
		i++;
	a = i;
	while (s[i + 1] != '\0')
		i++;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && i > 0)
	{
		i--;
		j++;
	}
	return (ft_strlen(s) - a - j);
}

static int	spaceinend(const char *s, int i)
{
	int a;

	a = 0;
	while (s[i + a] == ' ' || s[i + a] == '\n' || s[i + a] == '\t')
	{
		if (s[i + a + 1] == '\0')
			return (1);
		a++;
	}
	return (0);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	char	*new;

	j = 0;
	if (s == NULL)
		return (NULL);
	i = size(s);
	new = (char*)malloc(sizeof(char) * (i + 1));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (s[i])
	{
		if (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			if (spaceinend(s, i) == 1)
				break ;
		new[j] = s[i];
		i++;
		j++;
	}
	new[j] = '\0';
	return (new);
}
