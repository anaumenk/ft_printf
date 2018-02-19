/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_oOuU.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 22:39:57 by anaumenk          #+#    #+#             */
/*   Updated: 2018/02/19 22:39:58 by anaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*for_uU_continue(uint64_t x, char *str, int i, t_flags *help)
{
	char		*hex;
	uint64_t	nb;

	hex = "0123456789";
	nb = x;
	while (nb > 0)
	{
		str[--i] = hex[nb % 10];
		nb = nb / 10;
	}
	if (help->dot != 0 && ft_strlen(str) < (size_t)help->dot)
		while (ft_strlen(str) < (size_t)help->dot)
			str = ft_strjoin(ft_strdup("0"), str);
	if (help->zero == '0' && ft_strlen(str) < (size_t)help->field && help->dot == 0)
		while (ft_strlen(str) < (size_t)help->field)
			str = ft_strjoin(ft_strdup("0"), str);
	if (help->minus == '0' && help->zero == '-' && ft_strlen(str) < (size_t)help->field)
		while (ft_strlen(str) < (size_t)help->field)
			str = ft_strjoin(ft_strdup(" "), str);
	if (help->minus == '-' && ft_strlen(str) < (size_t)help->field)
		while (ft_strlen(str) < (size_t)help->field)
			str = ft_strjoin(str, ft_strdup(" "));
	return (str);
}

void		for_uU(char c, va_list args, t_flags *help)
{
	char		*str;
	uint64_t	x;
	uint64_t	nb;
	int			i;

	i = 1;
	if (c == 'u')
		x = for_ouxX_x(help, args);
	if (c == 'U')
		x = va_arg(args, unsigned long int);
	nb = x;
	while ((nb = nb / 10))
		i++;
	str = ft_strnew(i);
	if (x == 0 && ((help->dot == 0 && help->dot_ex == 0) || (help->dot != 0 && help->dot_ex != 0)))
		str[0] = '0';
	str = for_uU_continue(x, str, i, help);
	ft_putstr(str);
	help->result += ft_strlen(str);
	free(str);
}

void		for_oO_continue(char *str, t_flags *help)
{
	if (help->hash == '#')
		str = ft_strjoin(ft_strdup("0"), str);
	if (help->dot != 0 && ft_strlen(str) < (size_t)help->dot)
		while (ft_strlen(str) < (size_t)help->dot)
			str = ft_strjoin(ft_strdup("0"), str);
	if (help->zero == '0' && ft_strlen(str) < (size_t)help->field && help->dot == 0
		&& help->minus != '-')
		while (ft_strlen(str) < (size_t)help->field)
			str = ft_strjoin(ft_strdup("0"), str);
	if (help->minus == '0' && help->zero == '-' && ft_strlen(str) < (size_t)help->field)
		while (ft_strlen(str) < (size_t)help->field)
			str = ft_strjoin(ft_strdup(" "), str);
	if (help->minus == '-' && ft_strlen(str) < (size_t)help->field)
		while (ft_strlen(str) < (size_t)help->field)
			str = ft_strjoin(str, ft_strdup(" "));
	ft_putstr(str);
	help->result += ft_strlen(str);
	free(str);
}

void		for_oO(char c, va_list args, t_flags *help)
{
	uint64_t	nb;
	uint64_t	x;
	int			i;
	char		*str;
	char		*hex;

	hex = "01234567";
	if (c == 'o')
		x = for_ouxX_x(help, args);
	if (c == 'O')
		x = va_arg(args, uint64_t);
	nb = x;
	i = 1;
	while ((nb = nb / 8))
		i++;
	str = ft_strnew(i);
	if (x == 0 && ((help->dot == 0 && help->dot_ex == 0) || (help->dot != 0
		&& help->dot_ex != 0)) && help->hash != '#')
		str[0] = '0';
	while (x > 0)
	{
		str[--i] = hex[x % 8];
		x = x / 8;
	}
	for_oO_continue(str, help);
}