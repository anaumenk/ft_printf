/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 22:42:18 by anaumenk          #+#    #+#             */
/*   Updated: 2018/02/19 22:42:19 by anaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	for_big_c_cl_cont(t_flags *help, unsigned int x)
{
	if (help->minus == '-' && unilen(x) < help->field)
		while (unilen(x) != help->field)
		{
			write(1, " ", 1);
			help->result++;
			help->field--;
		}
}

void	for_big_c_cl_continue(t_flags *help, unsigned int x)
{
	if (help->zero == '0' && (unilen(x) < help->field) && help->minus == '0')
		while (unilen(x) != help->field)
		{
			write(1, "0", 1);
			help->result++;
			help->field--;
		}
	if (help->minus == '0' && help->zero == '-' && unilen(x) < help->field)
		while (unilen(x) != help->field)
		{
			write(1, " ", 1);
			help->result++;
			help->field--;
		}
	if (x == '\0')
	{
		write(1, "\0", 1);
		help->result++;
	}
	else
		unicode(x, help);
	for_big_c_cl_cont(help, x);
}

void	for_big_clc(va_list args, t_flags *help)
{
	unsigned int x;

	x = va_arg(args, unsigned int);
	if (MB_CUR_MAX == 1 && x < 256)
	{
		ft_putstr(help->str);
		if (help->color != '0')
			color_on(help);
		write(1, &x, 1);
		help->result++;
		return ;
	}
	else if (MB_CUR_MAX == 1 && x >= 256)
	{
		help->result = -1;
		return ;
	}
	ft_putstr(help->str);
	if (help->color != '0')
		color_on(help);
	for_big_c_cl_continue(help, x);
}

char	*for_c_continue(t_flags *help, char *str, char x)
{
	int i;

	i = 0;
	if (help->minus == '0' && help->zero == '-'
		&& ft_strlen(str) < (size_t)help->field)
		while (ft_strlen(str) < (size_t)help->field)
			str = ft_strjoin(ft_strdup(" "), str);
	if (help->minus == '-' && ft_strlen(str) < (size_t)help->field)
		while (ft_strlen(str) < (size_t)help->field)
			str = ft_strjoin(str, ft_strdup(" "));
	if (x == '\0')
	{
		while (str[i])
		{
			if (str[i] == 'c')
				write(1, "\0", 1);
			else
				write(1, &str[i], 1);
			i++;
		}
	}
	else
		ft_putstr(str);
	return (str);
}

void	for_c(char c, va_list args, t_flags *help)
{
	char x;
	char *str;

	if (help->color != '0')
		color_on(help);
	if (help->alarm == 1)
		x = c;
	else
		x = (unsigned char)va_arg(args, void*);
	str = (x != '\0') ? ft_strnew(1) : ft_strnew(0);
	str[0] = (x != '\0') ? x : 'c';
	if (help->zero == '0' && (ft_strlen(str) < (size_t)help->field)
		&& help->minus == '0')
		while (ft_strlen(str) < (size_t)help->field)
			str = ft_strjoin(ft_strdup("0"), str);
	str = for_c_continue(help, str, x);
	help->result += ft_strlen(str);
	free(str);
}
