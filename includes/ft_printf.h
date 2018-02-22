/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 13:27:25 by anaumenk          #+#    #+#             */
/*   Updated: 2018/02/05 13:27:26 by anaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include <stdio.h>
# include "libft.h"

# define CONV1(x) (x != 's' && x != 'S' && x != 'p' && x != 'd' && x != 'D')
# define CONV2(x) (x != 'i' && x != 'o' && x != 'O' && x != 'u' && x != 'U')
# define CONV3(x) (x != 'x' && x != 'X' && x != 'c' && x != 'C' && x != '%')
# define CONV4(x) (x != 'n')
# define CONV(x) (CONV1(x) && CONV2(x) && CONV3(x) && CONV4(x))
# define SIZE(x) (x == 'l' || x == 'h' || x == 'j' || x == 'z')
# define FLAG1(x) (x == '+' || x == '-' || x == '.' || x == '*' || x == '#')
# define FLAG2(x) ((x >= '0' && x <= '9') || x == ' ' || SIZE(x) || x == '{')
# define FLAGS(x) (FLAG1(x) || FLAG2(x))

typedef struct	s_flags
{
	int		field;
	int		dot;
	char	hash;
	char	space;
	char	plus;
	char	minus;
	char	zero;
	char	size;
	int		result;
	int		dot_ex;
	int		alarm;
	int		dotzero;
	char	color;
}				t_flags;

int				ft_printf(const char *format, ...);
int				flags(char *str, va_list args, t_flags *help);
int				findout(char c, va_list args, t_flags *help, char *new);
void			for_id_big_d(char c, va_list args, t_flags *help);
void			for_s(va_list args, t_flags *help);
char			*for_p_continue(char *str, t_flags *help);
uint64_t		for_oux_big_x_x(t_flags *help, va_list args);
void			for_o_big_o(char c, va_list args, t_flags *help);
void			for_u_big_u(char c, va_list args, t_flags *help);
void			for_x_big_x(char c, va_list args, t_flags *help);
void			for_c(char c, va_list args, t_flags *help);
void			for_big_clc(va_list args, t_flags *help);
void			for_big_s_ls(va_list args, t_flags *help);
void			unicode(unsigned int x, t_flags *help);
void			for_p(va_list args, t_flags *help);
int				unilen(unsigned int x);
void			for_n(va_list args, t_flags *help);
void			flag_color(t_flags *help, va_list args);
void			color_on(t_flags *help);

#endif
