/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaumenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 14:22:28 by anaumenk          #+#    #+#             */
/*   Updated: 2018/02/22 14:22:29 by anaumenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	flag_color(t_flags *help, va_list args)
{
	char *str;

	str = va_arg(args, char*);
	if (!ft_strcmp(str, "black"))
		help->color = 'b';
	if (!ft_strcmp(str, "red"))
		help->color = 'r';
	if (!ft_strcmp(str, "green"))
		help->color = 'g';
	if (!ft_strcmp(str, "yellow"))
		help->color = 'y';
	if (!ft_strcmp(str, "blue"))
		help->color = 'B';
	if (!ft_strcmp(str, "magenta"))
		help->color = 'm';
	if (!ft_strcmp(str, "cyan"))
		help->color = 'c';
}

void	color_on(t_flags *help)
{
	if (help->color == 'b')
		ft_putstr("\033[30m");
	else if (help->color == 'r')
		ft_putstr("\033[31m");
	else if (help->color == 'g')
		ft_putstr("\033[33m");
	else if (help->color == 'y')
		ft_putstr("\033[33m");
	else if (help->color == 'B')
		ft_putstr("\033[34m");
	else if (help->color == 'm')
		ft_putstr("\033[35m");
	else if (help->color == 'c')
		ft_putstr("\033[36m");
}
