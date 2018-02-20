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

SWITCH =        \033[
STYLE_NORMAL =  $(SWITCH)0m
STYLE_BOLD =    $(SWITCH)1m
COLOR_YELLOW =  $(SWITCH)93m
COLOR_GREEN =   $(SWITCH)34m
COLOR_RED =     $(SWITCH)31m

C_FILES =  ft_printf.c findout.c flags.c for_cC.c for_idD.c for_oOuU.c \
for_Sls.c for_sp.c for_xX.c unicode.c

O_FILES = ft_printf.o findout.o flags.o for_cC.o for_idD.o for_oOuU.o \
for_Sls.o for_sp.o for_xX.o unicode.o

FLAGS = -Wall -Wextra -Werror

all: $(addprefix ../objects/,$(O_FILES))
../objects/%.o: %.c
	@echo "$(STYLE_BOLD)$(COLOR_GREEN) $< has been compiled.$(STYLE_NORMAL)"
	@gcc -c $(FLAGS) $<  -I ../includes -o $@ 

clean:
	@echo "$(STYLE_BOLD)$(COLOR_RED)All the object files (ft_printf)\
	have been deleted.$(STYLE_NORMAL)"
	@rm -rf $(addprefix ../objects/,$(O_FILES))

fclean: clean
	@echo "$(STYLE_BOLD)$(COLOR_RED)$(NAME) has been deleted.$(STYLE_NORMAL)"

re: fclean all

.PHONY: clean all fclean re