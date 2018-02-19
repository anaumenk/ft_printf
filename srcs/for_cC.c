/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_cC.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 22:42:18 by anaumenk          #+#    #+#             */
/*   Updated: 2018/02/19 22:42:19 by anaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void for_Ccl_continue(t_flags *help, unsigned int x)
{
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
	if (help->minus == '-' && unilen(x) < help->field)
		while (unilen(x) != help->field)
		{
			write(1, " ", 1);
			help->result++;
			help->field--;
		}
}

void for_Clc(va_list args, t_flags *help)
{
	unsigned int x;

	x = va_arg(args, unsigned int);
	if (MB_CUR_MAX == 1 && x < 256)
	{
		write(1, &x, 1);
		help->result++;
		return ;
	}
	else if (MB_CUR_MAX == 1 && x >= 256)
	{
		help->result = -1;
		return ;
	}
	if (MB_CUR_MAX == 1 && x > 256)
		return ;
	if (help->zero == '0' && (unilen(x) < help->field) && help->minus == '0')
		while (unilen(x) != help->field)
		{
			write(1, "0", 1);
			help->result++;
			help->field--;
		}
	for_Ccl_continue(help, x);
}

void	putstr_c( char *s)
{
	int i;

	i = 0;
	if (s != NULL)
	{
		while (s[i])
		{
			if (s[i] == 'c')
				write(1, "\0", 1);
			else 
				write(1, &s[i], 1);
			i++;
		}
	}
}

char		*for_c_continue(t_flags *help, char *str)
{
	if (help->zero == '0' && (ft_strlen(str) < (size_t)help->field)
		&& help->minus == '0')
		while (ft_strlen(str) < (size_t)help->field)
			str = ft_strjoin(ft_strdup("0"), str);
	if (help->minus == '0' && help->zero == '-'
		&& ft_strlen(str) < (size_t)help->field)
		while (ft_strlen(str) < (size_t)help->field)
			str = ft_strjoin(ft_strdup(" "), str);
	if (help->minus == '-' && ft_strlen(str) < (size_t)help->field)
		while (ft_strlen(str) < (size_t)help->field)
			str = ft_strjoin(str, ft_strdup(" "));
	return (str);
}

void		for_c(char c, va_list args, t_flags *help)
{
	char x;
	char *str;

	if (help->alarm == 1)
		x = c;
	if (help->size == '0' && help->alarm != 1)
		x = (unsigned char)va_arg(args, void*);
	if (x != '\0')
	{
		str = ft_strnew(1);
		str[0] = x;
	}
	else
	{
		str = ft_strnew(0);
		str[0] = 'c';
	}
	str = for_c_continue(help, str);
	if (x == '\0')
		putstr_c(str);
	else
		ft_putstr(str);
	help->result += ft_strlen(str);
	free(str);
}