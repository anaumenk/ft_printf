/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_big_s_ls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 23:09:59 by anaumenk          #+#    #+#             */
/*   Updated: 2018/02/19 23:10:00 by anaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	for_big_s_ls_cont_three(int i, wchar_t *x, t_flags *help)
{
	int j;

	j = 0;
	while (*x && j < i)
	{
		unicode(*x, help);
		j += unilen(*x);
		x++;
	}
	if (help->minus == '-' && i < help->field)
	{
		while (i < help->field)
		{
			write(1, " ", 1);
			help->result++;
			help->field--;
		}
	}
}

void	for_big_s_ls_cont_two(int i, t_flags *help, wchar_t *x)
{
	if (i < help->field && help->zero == '-' && help->minus != '-')
	{
		while (i < help->field)
		{
			write(1, " ", 1);
			help->field--;
			help->result++;
		}
	}
	if (i < help->field && help->zero == '0' && help->minus != '-')
	{
		while (i < help->field)
		{
			write(1, "0", 1);
			help->field--;
			help->result++;
		}
	}
	for_big_s_ls_cont_three(i, x, help);
}

void	for_big_s_ls_cont_one(t_flags *help, wchar_t *x)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (help->dot_ex == 1)
	{
		while (x[j] && i < help->dot)
		{
			i += unilen(x[j]);
			j++;
		}
		if (help->dot != 0 && i != help->dot)
			i -= unilen(x[j]);
	}
	else
	{
		while (x[j])
		{
			i += unilen(x[j]);
			j++;
		}
	}
	for_big_s_ls_cont_two(i, help, x);
}

void	for_null_s(t_flags *help)
{
	char *str;

	str = ft_strdup("(null)");
	if (ft_strlen(str) > (size_t)help->dot && help->dot_ex == 1)
		str = ft_strsub(str, 0, help->dot);
	if (help->minus == '-' && ft_strlen(str) < (size_t)help->field)
		while (ft_strlen(str) < (size_t)help->field)
			str = ft_strjoin(str, ft_strdup(" "));
	if (ft_strlen(str) < (size_t)help->field && help->zero == '-')
		while (ft_strlen(str) < (size_t)help->field)
			str = ft_strjoin(ft_strdup(" "), str);
	if (help->zero == '0' && ft_strlen(str) < (size_t)help->field)
		while (ft_strlen(str) < (size_t)help->field)
			str = ft_strjoin(ft_strdup("0"), str);
	ft_putstr(str);
	help->result += ft_strlen(str);
	free(str);
}

void	for_big_s_ls(va_list args, t_flags *help)
{
	wchar_t *x;
	int		i;

	i = 0;
	x = va_arg(args, wchar_t*);
	if (MB_CUR_MAX == 1 && x != NULL)
	{
		while (x[i])
		{
			if (x[i] > 255)
			{
				help->result = -1;
				return ;
			}
			i++;
		}
	}
	ft_putstr(help->str);
	if (help->color != '0')
		color_on(help);
	if (x == NULL)
		for_null_s(help);
	else
		for_big_s_ls_cont_one(help, x);
}
