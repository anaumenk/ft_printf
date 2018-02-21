/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findout.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 22:36:56 by anaumenk          #+#    #+#             */
/*   Updated: 2018/02/19 22:36:57 by anaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	for_symbol(t_flags *help)
{
	char *str;

	str = ft_strdup("%");
	if (help->zero == '0' && help->minus == '0' && ft_strlen(str) <
		(size_t)help->field)
		while (ft_strlen(str) < (size_t)help->field)
			str = ft_strjoin(ft_strdup("0"), str);
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

void	findout_cont(char c, va_list args, t_flags *help)
{
	if (c == 'o' || c == 'O')
		for_o_big_o(c, args, help);
	if (c == 'u' || c == 'U')
		for_u_big_u(c, args, help);
	if (c == 'x' || c == 'X')
		for_x_big_x(c, args, help);
}

int		findout(char c, va_list args, t_flags *help, char *new)
{
	if (c == '%')
		for_symbol(help);
	if (c == 'i' || c == 'd' || c == 'D')
		for_id_big_d(c, args, help);
	if (c == 's' && help->size == '0')
		for_s(args, help);
	if (c == 'p')
		for_p(args, help);
	if (c == 'c' && help->size != 'l')
		for_c_big_c(0, args, help);
	if (c == 'C' || (c == 'c' && help->size == 'l'))
		for_big_clc(args, help);
	if (c == 'S' || (c == 's' && help->size == 'l'))
		for_big_s_ls(args, help);
	if (c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'x' || c == 'X')
		findout_cont(c, args, help);
	if (help->result == -1)
	{
		free(new);
		return (1);
	}
	return (0);
}
