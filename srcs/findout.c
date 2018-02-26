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
	if (c == 's' && help->size != 'l')
		for_s(args, help);
	else if (c == 'o' || c == 'O')
		for_o_big_o(c, args, help);
	else if (c == 'u' || c == 'U')
		for_u_big_u(c, args, help);
	else if (c == 'x' || c == 'X')
		for_x_big_x(c, args, help);
	else if (c == 'n')
		for_n(args, help);
	else if (c == 'i' || c == 'd' || c == 'D')
		for_id_big_d(c, args, help);
	else if (c == 'p')
		for_p(args, help);
	else if (c == 'c' && help->size != 'l')
		for_c(0, args, help);
}

int		findout(char c, va_list args, t_flags *help)
{
	if (c == 'S' || (c == 's' && help->size == 'l'))
		for_big_s_ls(args, help);
	else if (c == 'C' || (c == 'c' && help->size == 'l'))
		for_big_clc(args, help);
	else if (help->alarm != 1)
		ft_putstr(help->str);
	if (help->color != '0')
		color_on(help);
	if (c == '%')
		for_symbol(help);
	else if (c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'x'
		|| c == 'X' || c == 'n' || (c == 's' && help->size != 'l') || c == 'i'
		|| c == 'd' || c == 'D' || (c == 'c' && help->size != 'l') || c == 'p')
		findout_cont(c, args, help);
	if (help->color != '0')
		ft_putstr("\033[37m");
	ft_bzero(help->str, ft_strlen(help->str));
	if (help->result == -1)
	{
		free(help->str);
		free(help->new);
		return (1);
	}
	return (0);
}
