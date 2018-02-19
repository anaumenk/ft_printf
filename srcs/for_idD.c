/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_idD.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 22:38:03 by anaumenk          #+#    #+#             */
/*   Updated: 2018/02/19 22:38:04 by anaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*ft_itoa_ll(unsigned long long int n)
{
	char					*s;
	int						i;
	unsigned long long int	nb;

	i = 1;
	nb = n;
	while (nb /= 10)
		i++;
	s = ft_strnew(i);
	if (s == NULL)
		return (NULL);
	s[i--] = '\0';
	while (n > 0)
	{
		s[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	return (s);
}

char		*for_idD_continue(t_flags *help, char *str, long int x)
{
	if (help->zero == '0' && help->minus == '0' && ft_strlen(str) < (size_t)help->field && help->dot == 0
		&& (help->space == ' ' || x < 0 || help->plus == '+') && help->dot_ex != 1)
		while (ft_strlen(str) < (size_t)help->field - 1)
			str = ft_strjoin(ft_strdup("0"), str);
	if (help->zero == '0' && ft_strlen(str) < (size_t)help->field && help->dot == 0
		&& help->space != ' ' && help->plus != '+' && x >= 0 && help->minus != '-')
		while (ft_strlen(str) < (size_t)help->field)
			str = ft_strjoin(ft_strdup("0"), str);
	if (help->zero == '0' && ft_strlen(str) < (size_t)help->field && help->dot == 0
		&& help->space != ' ' && help->plus == '+' && help->minus != '-')
		while (ft_strlen(str) < (size_t)help->field - 1)
			str = ft_strjoin(ft_strdup("0"), str);
	if (help->plus == '+' && x >= 0)
		str = ft_strjoin(ft_strdup("+"), str);
	if (help->space == ' ' && help->plus == '0' && x >= 0)
		str = ft_strjoin(ft_strdup(" "), str);
	if (x < 0)
		str = ft_strjoin(ft_strdup("-"), str);
	if (help->minus == '0' && ft_strlen(str) < (size_t)help->field)
		while (ft_strlen(str) < (size_t)help->field)
			str = ft_strjoin(ft_strdup(" "), str);
	if (help->minus == '-' && ft_strlen(str) < (size_t)help->field)
		while (ft_strlen(str) < (size_t)help->field)
			str = ft_strjoin(str, ft_strdup(" "));
	return (str);
}

long int	for_id_x(t_flags *help, va_list args)
{
	long int x;

	if (help->size == '0')
		x = va_arg(args, int);
	if (help->size == 'h')
		x = (short)va_arg(args, void*);
	if (help->size == 'b')
		x = (char)va_arg(args, void*);
	if (help->size == 'l')
		x = va_arg(args, long);
	if (help->size == 'a')
		x = va_arg(args, long long);
	if (help->size == 'j')
		x = va_arg(args, int64_t);
	if (help->size == 'z')
		x = va_arg(args, int64_t);
	return (x);
}

void		for_idD(char c, va_list args, t_flags *help)
{
	long int	x;
	char		*str;

	if (c == 'd' || c == 'i')
		x = for_id_x(help, args);
	if (c == 'D')
		x = va_arg(args, long int);
	if (x >= 0)
		str = ft_itoa(x);
	if (x < 0 && help->size != 'a' && help->size != 'j' && help->size != 'z')
		str = ft_itoa(-x);
	if (x < 0 && (help->size == 'a' || help->size == 'j' || help->size == 'z'))
		str = ft_itoa_ll(-x);
	if (x == 0)
		ft_bzero(str, ft_strlen(str));
	if ((x == 0 && ((help->dot == 0 && help->dot_ex == 0) || (help->dot != 0 && help->dot_ex != 0))))
		str[0] = '0';
	if (help->dot != 0 && ft_strlen(str) < (size_t)help->dot)
		while (ft_strlen(str) < (size_t)help->dot)
			str = ft_strjoin(ft_strdup("0"), str);
	str = for_idD_continue(help, str, x);
	ft_putstr(str);
	help->result += ft_strlen(str);
	free(str);
}
