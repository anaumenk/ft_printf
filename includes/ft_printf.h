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
# define CONV(x) (CONV1(x) && CONV2(x) && CONV3(x))
# define SIZE(x) (x == 'l' || x == 'h' || x == 'j' || x == 'z')
# define FLAG1(x) (x == '+' || x == '-' || x == '.' || x == '*' || x == '#')
# define FLAG2(x) ((x >= '0' && x <= '9') || x == ' ' || SIZE(x))
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
}				t_flags;

int				ft_printf(const char *format, ...);

#endif
