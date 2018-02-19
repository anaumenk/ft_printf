/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 19:25:19 by anaumenk          #+#    #+#             */
/*   Updated: 2017/11/12 19:25:20 by anaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	new = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 2);
	if (new == NULL)
		return (NULL);
	while (s1[j])
	{
		new[j] = s1[j];
		j++;
	}
	while (s2[i])
	{
		new[j] = s2[i];
		i++;
		j++;
	}
	new[j] = '\0';
	free((char*)s1);
	free((char*)s2);
	return (new);
}
