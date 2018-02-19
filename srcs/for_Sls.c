/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_Sls.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 23:09:59 by anaumenk          #+#    #+#             */
/*   Updated: 2018/02/19 23:10:00 by anaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	for_Sls_cont_three(int i, wchar_t *x, t_flags *help)
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

void	for_Sls_cont_two(int i, t_flags *help, wchar_t *x)
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
	for_Sls_cont_three(i, x, help);
}

void	for_Sls_cont_one(t_flags *help, wchar_t *x)
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
	for_Sls_cont_two(i, help, x);
}

void	for_Sls(va_list args, t_flags *help)
{
	wchar_t *x;

	x = va_arg(args, wchar_t*);
	if (x == NULL && (help->dot_ex != 1 || help->dot >= 6))
	{
		write(1, "(null)", 6);
		help->result += 6;
	}
	else if (x == NULL)
	{
		write(1, "(null)", help->dot);
		help->result += help->dot;
	}
	else
		for_Sls_cont_one(help, x);
}
