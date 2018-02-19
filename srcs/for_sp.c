/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_sp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 22:38:54 by anaumenk          #+#    #+#             */
/*   Updated: 2018/02/19 22:38:55 by anaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*for_p_continue(char *str, t_flags *help)
{
	if (help->dot != 0 && ft_strlen(str) < (size_t)help->dot)
		while (ft_strlen(str) < (size_t)help->dot)
			str = ft_strjoin(ft_strdup("0"), str);
	if (help->zero == '0' && ft_strlen(str) < (size_t)help->field && help->dot == 0
		&& help->minus == '0')
		while (ft_strlen(str) < (size_t)help->field - 2)
			str = ft_strjoin(ft_strdup("0"), str);
	str = ft_strjoin(ft_strdup("0x"), str);
	if (help->minus == '0' && help->zero == '-' && ft_strlen(str) < (size_t)help->field)
		while (ft_strlen(str) < (size_t)help->field)
			str = ft_strjoin(ft_strdup(" "), str);
	if (help->minus == '-' && ft_strlen(str) < (size_t)help->field)
		while (ft_strlen(str) < (size_t)help->field)
			str = ft_strjoin(str, ft_strdup(" "));
	return (str);
}

void		for_p(va_list args, t_flags *help)
{
	char		*hex;
	uint64_t	pointer;
	uint64_t	nb;
	char		*str;
	int			i;

	hex = "0123456789abcdef";
	pointer = va_arg(args, uint64_t);
	i = 1;
	nb = pointer;
	while ((nb = nb / 16))
		i++;
	str = ft_strnew(i);
	if (pointer == 0 && help->dot == 0 && help->dot_ex != 1)
		str[0] = '0';
	while (pointer > 0)
	{
		str[--i] = hex[pointer % 16];
		pointer = pointer / 16;
	}
	str = for_p_continue(str, help);
	ft_putstr(str);
	help->result += ft_strlen(str);
	free(str);
}

void		for_s(va_list args, t_flags *help)
{
	char	*str;

	str = va_arg(args, char*);
	if (str == NULL)
		str = ft_strdup("(null)");
	else
		str = ft_strsub(str, 0, ft_strlen(str));
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
