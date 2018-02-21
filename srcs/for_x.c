/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_xX.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 22:41:11 by anaumenk          #+#    #+#             */
/*   Updated: 2018/02/19 22:41:12 by anaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

uint64_t	for_oux_big_x_x(t_flags *help, va_list args)
{
	unsigned long int x;

	if (help->size == '0')
		x = va_arg(args, unsigned int);
	if (help->size == 'b')
		x = (unsigned char)va_arg(args, void*);
	if (help->size == 'h')
		x = (unsigned short)va_arg(args, void*);
	if (help->size == 'l')
		x = va_arg(args, unsigned long);
	if (help->size == 'a')
		x = va_arg(args, unsigned long long);
	if (help->size == 'j')
		x = va_arg(args, uintmax_t);
	if (help->size == 'z')
		x = va_arg(args, size_t);
	return (x);
}

char		*b_x_cont(uint64_t x, char *str, int i, t_flags *help)
{
	char		*hex;
	uint64_t	nb;

	hex = "0123456789ABCDEF";
	nb = x;
	while (nb > 0)
	{
		str[--i] = hex[nb % 16];
		nb = nb / 16;
	}
	if (help->dot != 0 && ft_strlen(str) < (size_t)help->dot)
		while (ft_strlen(str) < (size_t)help->dot)
			str = ft_strjoin(ft_strdup("0"), str);
	if (help->zero == '0' && ft_strlen(str) < (size_t)help->field
		&& help->dot == 0 && help->hash != '#' && help->minus != '-')
		while (ft_strlen(str) < (size_t)help->field)
			str = ft_strjoin(ft_strdup("0"), str);
	if (help->zero == '0' && ft_strlen(str) < (size_t)help->field
		&& help->dot == 0 && help->hash == '#' && help->minus != '-')
		while (ft_strlen(str) < (size_t)help->field - 2)
			str = ft_strjoin(ft_strdup("0"), str);
	if (help->hash == '#' && x != 0)
		str = ft_strjoin(ft_strdup("0X"), str);
	return (str);
}

char		*for_x_cont(uint64_t x, char *str, int i, t_flags *help)
{
	char		*hex;
	uint64_t	nb;

	hex = "0123456789abcdef";
	nb = x;
	while (nb > 0)
	{
		str[--i] = hex[nb % 16];
		nb = nb / 16;
	}
	if (help->dot != 0 && ft_strlen(str) < (size_t)help->dot)
		while (ft_strlen(str) < (size_t)help->dot)
			str = ft_strjoin(ft_strdup("0"), str);
	if (help->zero == '0' && ft_strlen(str) < (size_t)help->field
		&& help->dot == 0 && help->hash != '#' && help->minus != '-')
		while (ft_strlen(str) < (size_t)help->field)
			str = ft_strjoin(ft_strdup("0"), str);
	if (help->zero == '0' && ft_strlen(str) < (size_t)help->field
		&& help->dot == 0 && help->hash == '#' && help->minus != '-')
		while (ft_strlen(str) < (size_t)help->field - 2)
			str = ft_strjoin(ft_strdup("0"), str);
	if (help->hash == '#' && x != 0)
		str = ft_strjoin(ft_strdup("0x"), str);
	return (str);
}

void		for_x_big_x(char c, va_list args, t_flags *help)
{
	char		*str;
	uint64_t	x;
	uint64_t	nb;
	int			i;

	i = 1;
	x = for_oux_big_x_x(help, args);
	nb = x;
	while ((nb = nb / 16))
		i++;
	str = ft_strnew(i);
	if ((x == 0 && ((help->dot == 0 && help->dot_ex == 0) || (help->dot != 0 &&
		help->dot_ex != 0))))
		str[0] = '0';
	str = (c == 'x') ? for_x_cont(x, str, i, help) : b_x_cont(x, str, i, help);
	if (help->minus == '0' && help->zero == '-' && ft_strlen(str) <
		(size_t)help->field)
		while (ft_strlen(str) < (size_t)help->field)
			str = ft_strjoin(ft_strdup(" "), str);
	if (help->minus == '-' && ft_strlen(str) < (size_t)help->field)
		while (ft_strlen(str) < (size_t)help->field)
			str = ft_strjoin(str, ft_strdup(" "));
	ft_putstr(str);
	help->result += ft_strlen(str);
	free(str);
}
