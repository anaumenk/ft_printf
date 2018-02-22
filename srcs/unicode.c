/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 23:11:58 by anaumenk          #+#    #+#             */
/*   Updated: 2018/02/19 23:11:59 by anaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		unilen(unsigned int x)
{
	int i;

	i = 1;
	while (x /= 2)
		i++;
	if (i <= 7)
		return (1);
	else if (i > 7 && i <= 11)
		return (2);
	else if (i > 11 && i <= 16)
		return (3);
	else
		return (4);
}

void	uni_else(unsigned int x, t_flags *help)
{
	unsigned int nb;

	nb = (x >> 18) | 240;
	write(1, &nb, 1);
	nb = (x << 14) >> 26 | 128;
	write(1, &nb, 1);
	nb = (x << 20) >> 26 | 128;
	write(1, &nb, 1);
	nb = (x << 26) >> 26 | 128;
	write(1, &nb, 1);
	help->result += 4;
}

void	uni_else_if(unsigned int x, t_flags *help)
{
	unsigned int nb;

	nb = (x >> 12) | 224;
	write(1, &nb, 1);
	nb = (x << 20) >> 26 | 128;
	write(1, &nb, 1);
	nb = (x << 26) >> 26 | 128;
	write(1, &nb, 1);
	help->result += 3;
}

void	unicode(unsigned int x, t_flags *help)
{
	unsigned int	nb;
	int				i;

	i = 1;
	nb = x;
	while (nb /= 2)
		i++;
	if (i <= 7)
	{
		write(1, &x, 1);
		help->result++;
	}
	else if (i > 7 && i <= 11)
	{
		nb = (x >> 6) | 192;
		write(1, &nb, 1);
		nb = ((x << 26) >> 26) | 128;
		write(1, &nb, 1);
		help->result += 2;
	}
	else if (i > 11 && i <= 16)
		uni_else_if(x, help);
	else
		uni_else(x, help);
}
