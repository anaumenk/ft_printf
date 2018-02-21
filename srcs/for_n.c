/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_n.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 19:57:12 by anaumenk          #+#    #+#             */
/*   Updated: 2018/02/20 19:57:13 by anaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	for_n(va_list args, t_flags *help)
{
	int		*x;
	short	*y;
	long	*z;

	if (help->size == '0')
	{
		x = va_arg(args, int*);
		*(int64_t*)x = help->result;
	}
	if (help->size == 'h')
	{
		y = va_arg(args, short*);
		*(int64_t*)y = help->result;
	}
	if (help->size == 'l')
	{
		z = va_arg(args, long*);
		*(int64_t*)z = help->result;
	}
}
