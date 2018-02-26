/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 22:35:18 by anaumenk          #+#    #+#             */
/*   Updated: 2018/02/19 22:35:20 by anaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			forsize(char *str, int i, t_flags *help)
{
	if (str[i] == 'h' && str[i + 1] == 'h')
	{
		if (help->size != 'h' && help->size != 'l' && help->size != 'a'
			&& help->size != 'j' && help->size != 'z')
			help->size = 'b';
		i++;
	}
	else if ((str[i] == 'h' && str[i + 1] != 'h') && help->size != 'l'
		&& help->size != 'a' && help->size != 'j' && help->size != 'z')
		help->size = 'h';
	else if ((str[i] == 'l' && str[i + 1] != 'l') && help->size != 'a'
		&& help->size != 'j' && help->size != 'z')
		help->size = 'l';
	else if (str[i] == 'l' && str[i + 1] == 'l')
	{
		if (help->size != 'j' && help->size != 'z')
			help->size = 'a';
		i++;
	}
	else if (str[i] == 'j' && help->size != 'z')
		help->size = 'j';
	else if (str[i] == 'z')
		help->size = 'z';
	return (i);
}

int			fordot(char *str, int i, t_flags *help, va_list args)
{
	help->dot_ex = 1;
	if (str[i + 1] >= '0' && str[i + 1] <= '9')
	{
		if (str[i + 1] == '0')
			help->dotzero = 1;
		help->dot = ft_atoi(ft_strchr(str, str[i]) + 1);
		while (str[i + 1] >= '0' && str[i + 1] <= '9')
			i++;
	}
	if (str[i + 1] == '*')
	{
		help->dot = va_arg(args, int);
		help->dot = (help->dot != 0) ? help->dot : 0;
		if (help->dot < 0)
		{
			help->dot = 0;
			help->dot_ex = 0;
		}
		i++;
	}
	return (i);
}

int			flags_continue(char *str, int i, t_flags *help, va_list args)
{
	if (str[i] == '.')
		i = fordot(str, i, help, args);
	if (str[i] == '%')
		return (i);
	if (str[i] == '-')
		help->minus = '-';
	if (str[i] == '+')
		help->plus = '+';
	if (str[i] == ' ')
		help->space = ' ';
	if (str[i] == '#')
		help->hash = '#';
	if (SIZE(str[i]))
		i = forsize(str, i, help);
	if (str[i] == '{')
		flag_color(help, args);
	return (i);
}

int			fornb(char *str, int i, t_flags *help, va_list args)
{
	if (str[i] == '*')
	{
		help->field = va_arg(args, int);
		if (help->field < 0)
		{
			help->minus = '-';
			help->field = -help->field;
		}
		help->field = (help->field != 0) ? help->field : 0;
	}
	if ((str[i] >= '1' && str[i] <= '9'))
	{
		help->field = ft_atoi(ft_strchr(str, str[i]));
		while (str[i + 1] >= '0' && str[i + 1] <= '9')
			i++;
	}
	return (i);
}

int			flags(char *str, va_list args, t_flags *help)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '0')
			help->zero = '0';
		else if ((str[i] >= '1' && str[i] <= '9') || str[i] == '*')
			i = fornb(str, i, help, args);
		else if (str[i] == '%' || str[i] == '-' || str[i] == '+'
			|| str[i] == '.' || str[i] == ' ' || str[i] == '#' || SIZE(str[i])
			|| str[i] == '{')
			i = flags_continue(str, i, help, args);
		else if (!(CONV(str[i])))
			return (i + 1);
		else
		{
			help->alarm = 1;
			ft_putstr(help->str);
			for_c(str[i], args, help);
			return (i + 1);
		}
		i++;
	}
	return (i);
}
