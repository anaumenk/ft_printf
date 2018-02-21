# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anaumenk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/14 14:23:25 by anaumenk          #+#    #+#              #
#    Updated: 2018/02/14 14:23:27 by anaumenk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C_FILES =  ft_printf.c findout.c flags.c for_c.c for_id.c for_ou.c \
for_big_s_ls.c for_sp.c for_x.c unicode.c for_n.c

O_FILES = ft_printf.o findout.o flags.o for_c.o for_id.o for_ou.o \
for_big_s_ls.o for_sp.o for_x.o unicode.o for_n.o

FLAGS = -Wall -Wextra -Werror

all: $(addprefix ../objects/,$(O_FILES))
../objects/%.o: %.c
	@gcc -c $(FLAGS) $<  -I ../includes -o $@ 

clean:
	@rm -rf $(addprefix ../objects/,$(O_FILES))

fclean: clean

re: fclean all

.PHONY: clean all fclean re