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

char		*strjoin(char *str, char c)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (str == NULL)
		return (NULL);
	new = (char*)malloc(sizeof(char) * ft_strlen(str) + 2);
	if (new == NULL)
		return (NULL);
	while (str[j])
	{
		new[j] = str[j];
		j++;
	}
	new[j] = c;
	new[j + 1] = '\0';
	free((char*)str);
	return (new);
}

char		*conv_str(char *str, int i)
{
	char	*new;
	int		j;

	j = i;
	if (str[i] == '\0' || (!FLAGS(str[i]) && !SIZE(str[i]) && CONV(str[i])))
		return (NULL);
	while (FLAGS(str[i]) || SIZE(str[i]))
		i++;
	new = ft_strnew((size_t)i - j);
	i = 0;
	while (FLAGS(str[j]) || SIZE(str[j]))
	{
		new[i] = str[j];
		i++;
		j++;
	}
	new[i] = str[j];
	new[i + 1] = '\0';
	return (new);
}

char		*init(t_flags *help, char *new, char *str, int i)
{
	char *tmp;

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
	help->color = '0';
	tmp = new;
	new = conv_str(str, i + 1);
	free(tmp);
	return (new);
}

void		print_and_find(const char *format, va_list args, t_flags *help)
{
	int		i;

	help->new = NULL;
	help->str = ft_strnew(0);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			help->new = init(help, help->new, (char*)format, i);
			i += (help->new != NULL) ? flags(help->new, args, help) : 0;
			if (help->new != NULL && findout(format[i], args, help))
				return ;
		}
		else
		{
			help->str = strjoin(help->str, format[i]);
			help->result += 1;
		}
		i++;
	}
	ft_putstr(help->str);
	free(help->str);
	if (help->new != NULL)
		free(help->new);
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
