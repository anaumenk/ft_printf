/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 13:22:54 by anaumenk          #+#    #+#             */
/*   Updated: 2018/02/19 19:19:07 by anaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*conv_str(char *str, int i)
{
	char	*new;
	int		j;

	j = i;
	if (str[i] == '\0')
		return (NULL);
	while (FLAGS(str[i]))
		i++;
	new = ft_strnew((size_t)i - j);
	i = 0;
	while (FLAGS(str[j]))
	{
		new[i] = str[j];
		i++;
		j++;
	}
	new[i] = str[j];
	new[i + 1] = '\0';
	return (new);
}

void		init(t_flags *help)
{
	help->field = 0;
	help->hash = '0';
	help->space = '0';
	help->plus = '0';
	help->minus = '0';
	help->zero = '-';
	help->dot = 0;
	help->dot_ex = 0;
	help->size = '0';
	help->alarm = 0;
	help->dotzero = 0;
}

char *if_char(t_flags *help, char *new, char *str, int i)
{
	char *tmp;

	init(help);
	tmp = new;
	new = conv_str(str, i + 1);
	free(tmp);
	return (new);
}

void		print_and_find(const char *format, va_list args, t_flags *help)
{
	char	*str;
	char	*new;
	int		i;

	str = (char*)format;
	new = NULL;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			new = if_char(help, new, str, i);
			i += (new != NULL) ? flags(new, args, help) : 0;
			if (new != NULL && findout(str[i], args, help, new))
					return;
		}
		else
		{
			write(1, &str[i], 1);
			help->result += 1;
		}
		i++;
	}
	if (new != NULL)
		free(new);
}

int			ft_printf(const char *format, ...)
{
	va_list		args;
	t_flags		*help;

	help = ft_memalloc(sizeof(t_flags));
	help->result = 0;
	if (*format)
	{
		va_start(args, format);
		print_and_find(format, args, help);
		va_end(args);
	}
	free(help);
	return (help->result);
}
