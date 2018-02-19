/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 13:22:54 by anaumenk          #+#    #+#             */
/*   Updated: 2018/02/05 13:22:55 by anaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int unilen(unsigned int x)
{
	int i;

	i = 1;
	while (x /= 2)
		i++;
	if (i <= 7)
		return (1);
	else if (i > 7 && i <= 11)
		return (2);
	else if (i > 11 && i <= 16)
		return (3);
	else
		return (4);
}

void unicode(unsigned int x, t_flags *help)
{
	unsigned int nb;
	int i;

	i = 1;
	nb = x;
	while (nb /= 2)
		i++;
	if (i <= 7)
	{
		write(1, &x, 1);
		help->result++;
	}
 	else if (i > 7 && i <= 11)
 	{
 		nb = (x >> 6) | 192;
 		write(1, &nb, 1);
 		nb = ((x << 26) >> 26) | 128;
 		write(1, &nb, 1);
 		help->result += 2;

 	}
	else if (i > 11 && i <= 16)
	{
		nb = (x >> 12) | 224;
		write(1, &nb, 1);
		nb = (x << 20) >> 26 | 128;
		write(1, &nb, 1);
		nb = (x << 26) >> 26 | 128;
		write(1, &nb, 1);
		help->result += 3;
	}
	else
	{
		nb = (x >> 18) | 240;
		write(1, &nb, 1);
		nb = (x << 14) >> 27 | 128;
		write(1, &nb, 1);
		nb = (x << 20) >> 26 | 128;
		write(1, &nb, 1);
		nb = (x << 26) >> 26 | 128;
		write(1, &nb, 1);
		help->result += 4;
	}
}

void for_Sls(va_list args, t_flags *help)
{
	wchar_t *x;
	int i;
	int j;

	x = va_arg(args, wchar_t*);
	i = 0;
	j = 0;
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
	{
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
				i += unilen(*x);
				j++;
			}
		}
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
	// if (MB_CUR_MAX == 1 && x > 256)
	// 	return ;
	if (help->minus == '-' && unilen(x) < help->field)
		while (unilen(x) != help->field)
		{
			write(1, " ", 1);
			help->result++;
			help->field--;
		}
}

void	putstr_с(char const *s)
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

void		for_c(char c, va_list args, t_flags *help)
{
	char x;
	char *str;

	if (help->alarm == 1)
		x = c;
	if (help->size == '0' && help->alarm != 1)
		x = (unsigned char)va_arg(args, void*);
	if (help->size == 'l')
	{
		for_Clc(args, help);
		return ;
	}
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
	if (x == '\0')
		putstr_с(str);
	else
		ft_putstr(str);
	help->result += ft_strlen(str);
	free(str);
}

uint64_t	for_ouxX_x(t_flags *help, va_list args)
{
	unsigned long int x;

	if (help->size == '0')
		x = va_arg(args, unsigned int);
	if (help->size == 'b')
		x = (unsigned char)va_arg(args, void*);
	if (help->size == 'h')
		x = (unsigned short)va_arg(args, void*);
	if (help->size == 'l')
		x = va_arg(args, unsigned long);
	if (help->size == 'a')
		x = va_arg(args, unsigned long long);
	if (help->size == 'j')
		x = va_arg(args, uintmax_t);
	if (help->size == 'z')
		x = va_arg(args, size_t);
	return (x);
}

char		*for_X_continue(uint64_t x, char *str, int i, t_flags *help)
{
	char		*hex;
	uint64_t	nb;

	hex = "0123456789ABCDEF";
	nb = x;
	while (nb > 0)
	{
		str[--i] = hex[nb % 16];
		nb = nb / 16;
	}
	if (help->dot != 0 && ft_strlen(str) < (size_t)help->dot)
		while (ft_strlen(str) < (size_t)help->dot)
			str = ft_strjoin(ft_strdup("0"), str);
	if (help->zero == '0' && ft_strlen(str) < (size_t)help->field && help->dot == 0)
		while (ft_strlen(str) < (size_t)help->field)
			str = ft_strjoin(ft_strdup("0"), str);
	if (help->zero == '0' && ft_strlen(str) < (size_t)help->field && help->dot == 0
		&& help->hash == '#' && help->minus != '-')
		while (ft_strlen(str) < (size_t)help->field - 2)
			str = ft_strjoin(ft_strdup("0"), str);
	if (help->hash == '#' && x != 0)
		str = ft_strjoin(ft_strdup("0X"), str);
	if (help->minus == '0' && help->zero == '-' && ft_strlen(str) < (size_t)help->field)
		while (ft_strlen(str) < (size_t)help->field)
			str = ft_strjoin(ft_strdup(" "), str);
	if (help->minus == '-' && ft_strlen(str) < (size_t)help->field)
		while (ft_strlen(str) < (size_t)help->field)
			str = ft_strjoin(str, ft_strdup(" "));
	return (str);
}

char		*for_x_continue(uint64_t x, char *str, int i, t_flags *help)
{
	char		*hex;
	uint64_t	nb;

	hex = "0123456789abcdef";
	nb = x;
	while (nb > 0)
	{
		str[--i] = hex[nb % 16];
		nb = nb / 16;
	}
	if (help->dot != 0 && ft_strlen(str) < (size_t)help->dot)
		while (ft_strlen(str) < (size_t)help->dot)
			str = ft_strjoin(ft_strdup("0"), str);
	if (help->zero == '0' && ft_strlen(str) < (size_t)help->field && help->dot == 0
		&& help->hash != '#' && help->minus != '-')
		while (ft_strlen(str) < (size_t)help->field)
			str = ft_strjoin(ft_strdup("0"), str);
	if (help->zero == '0' && ft_strlen(str) < (size_t)help->field && help->dot == 0
		&& help->hash == '#' && help->minus != '-')
		while (ft_strlen(str) < (size_t)help->field - 2)
			str = ft_strjoin(ft_strdup("0"), str);
	if (help->hash == '#' && x != 0)
		str = ft_strjoin(ft_strdup("0x"), str);
	if (help->minus == '0' && help->zero == '-' && ft_strlen(str) < (size_t)help->field)
		while (ft_strlen(str) < (size_t)help->field)
			str = ft_strjoin(ft_strdup(" "), str);
	if (help->minus == '-' && ft_strlen(str) < (size_t)help->field)
		while (ft_strlen(str) < (size_t)help->field)
			str = ft_strjoin(str, ft_strdup(" "));
	return (str);
}

void		for_xX(char c, va_list args, t_flags *help)
{
	char		*str;
	uint64_t	x;
	uint64_t	nb;
	int			i;

	i = 1;
	x = for_ouxX_x(help, args);
	nb = x;
	while ((nb = nb / 16))
		i++;
	str = ft_strnew(i);
	if ((x == 0 && ((help->dot == 0 && help->dot_ex == 0) || (help->dot != 0 && help->dot_ex != 0))))
		str[0] = '0';
	if (c == 'x')
		str = for_x_continue(x, str, i, help);
	if (c == 'X')
		str = for_X_continue(x, str, i, help);
	ft_putstr(str);
	help->result += ft_strlen(str);
	free(str);
}

char		*for_uU_continue(uint64_t x, char *str, int i, t_flags *help)
{
	char		*hex;
	uint64_t	nb;

	hex = "0123456789";
	nb = x;
	while (nb > 0)
	{
		str[--i] = hex[nb % 10];
		nb = nb / 10;
	}
	if (help->dot != 0 && ft_strlen(str) < (size_t)help->dot)
		while (ft_strlen(str) < (size_t)help->dot)
			str = ft_strjoin(ft_strdup("0"), str);
	if (help->zero == '0' && ft_strlen(str) < (size_t)help->field && help->dot == 0)
		while (ft_strlen(str) < (size_t)help->field)
			str = ft_strjoin(ft_strdup("0"), str);
	if (help->minus == '0' && help->zero == '-' && ft_strlen(str) < (size_t)help->field)
		while (ft_strlen(str) < (size_t)help->field)
			str = ft_strjoin(ft_strdup(" "), str);
	if (help->minus == '-' && ft_strlen(str) < (size_t)help->field)
		while (ft_strlen(str) < (size_t)help->field)
			str = ft_strjoin(str, ft_strdup(" "));
	return (str);
}

void		for_uU(char c, va_list args, t_flags *help)
{
	char		*str;
	uint64_t	x;
	uint64_t	nb;
	int			i;

	i = 1;
	if (c == 'u')
		x = for_ouxX_x(help, args);
	if (c == 'U')
		x = va_arg(args, unsigned long int);
	nb = x;
	while ((nb = nb / 10))
		i++;
	str = ft_strnew(i);
	if (x == 0 && ((help->dot == 0 && help->dot_ex == 0) || (help->dot != 0 && help->dot_ex != 0)))
		str[0] = '0';
	str = for_uU_continue(x, str, i, help);
	ft_putstr(str);
	help->result += ft_strlen(str);
	free(str);
}

char		*for_oO_continue(uint64_t x, char *str, int i, t_flags *help)
{
	char		*hex;
	uint64_t	nb;

	hex = "01234567";
	nb = x;
	while (x > 0)
	{
		str[--i] = hex[x % 8];
		x = x / 8;
	}
	if (help->hash == '#')
		str = ft_strjoin(ft_strdup("0"), str);
	if (help->dot != 0 && ft_strlen(str) < (size_t)help->dot)
		while (ft_strlen(str) < (size_t)help->dot)
			str = ft_strjoin(ft_strdup("0"), str);
	if (help->zero == '0' && ft_strlen(str) < (size_t)help->field && help->dot == 0 && help->minus != '-')
		while (ft_strlen(str) < (size_t)help->field)
			str = ft_strjoin(ft_strdup("0"), str);
	if (help->minus == '0' && help->zero == '-' && ft_strlen(str) < (size_t)help->field)
		while (ft_strlen(str) < (size_t)help->field)
			str = ft_strjoin(ft_strdup(" "), str);
	if (help->minus == '-' && ft_strlen(str) < (size_t)help->field)
		while (ft_strlen(str) < (size_t)help->field)
			str = ft_strjoin(str, ft_strdup(" "));
	return (str);
}

void		for_oO(char c, va_list args, t_flags *help)
{
	uint64_t	nb;
	uint64_t	x;
	int			i;
	char		*str;

	if (c == 'o')
		x = for_ouxX_x(help, args);
	if (c == 'O')
		x = va_arg(args, uint64_t);
	nb = x;
	i = 1;
	while ((nb = nb / 8))
		i++;
	str = ft_strnew(i);
	if (x == 0 && ((help->dot == 0 && help->dot_ex == 0) || (help->dot != 0 && help->dot_ex != 0)) && help->hash != '#')
		str[0] = '0';
	str = for_oO_continue(x, str, i, help);
	ft_putstr(str);
	help->result += ft_strlen(str);
	free(str);
}

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

	if (help->size == '0')
		str = va_arg(args, char*);
	if (help->size == 'l')
	{
	 	for_Sls(args, help);
	 	return ;
	}
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
	//printf("size = %c\n", help->size);
	//printf("str = %s\n", str);
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

void		for_symbol(t_flags *help)
{
	char *str;

	str = ft_strdup("%");
	if (help->zero == '0' && help->minus == '0' && ft_strlen(str) < (size_t)help->field)
		while (ft_strlen(str) < (size_t)help->field)
			str = ft_strjoin(ft_strdup("0"), str);
	if (help->minus == '0' && help->zero == '-' && ft_strlen(str) < (size_t)help->field)
		while (ft_strlen(str) < (size_t)help->field)
			str = ft_strjoin(ft_strdup(" "), str);
	if (help->minus == '-' && ft_strlen(str) < (size_t)help->field)
		while (ft_strlen(str) < (size_t)help->field)
			str = ft_strjoin(str, ft_strdup(" "));
	ft_putstr(str);
	help->result += ft_strlen(str);
	free(str);
}

void		findout(char c, va_list args, t_flags *help)
{
	if (c == '%')
		for_symbol(help);
	if (c == 'i' || c == 'd' || c == 'D')
		for_idD(c, args, help);
	if (c == 's')
		for_s(args, help);
	if (c == 'p')
		for_p(args, help);
	if (c == 'o' || c == 'O')
		for_oO(c, args, help);
	if (c == 'u' || c == 'U')
		for_uU(c, args, help);
	if (c == 'x' || c == 'X')
		for_xX(c, args, help);
	if (c == 'c')
		for_c(0, args, help);
	if (c == 'C')
		for_Clc(args, help);
	if (c == 'S')
	 	for_Sls(args, help);
}

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

int			flags_continue(char *str, int i, t_flags *help)
{
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

int			fornb(char *str, int i, t_flags *help, va_list args)
{
	if (str[i] == '*')
	{
		help->field = va_arg(args, int);
		if (help->field < 0)
		{
			help->minus = '-';
			help->field = - help->field;
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
		else if (str[i] == '.')
			i = fordot(str, i, help, args);
		else if (str[i] == '%' || str[i] == '-' || str[i] == '+'
			|| str[i] == ' ' || str[i] == '#' || SIZE(str[i]))
			i = flags_continue(str, i, help);
		else if (!(CONV(str[i])))
			return (i + 1);
		else
		{
			help->alarm = 1;
			for_c(str[i], args, help);
			return (i + 1);
		}
		i++;
	}	
	return (i);
}

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

void		print_and_find(const char *format, va_list args, t_flags *help)
{
	char	*str;
	char	*new;
	char	*tmp;
	int		i;

	str = (char*)format;
	new = NULL;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			init(help);
			tmp = new;
			new = conv_str(str, i + 1);
			free(tmp);
			if (new != NULL)
			{
				i += flags(new, args, help);
				findout(str[i], args, help);
				if (help->result == -1)
				{
					if (new != NULL)
						free(new);
					return;
				}
			}
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
