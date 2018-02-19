# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anaumenk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/05 13:21:36 by anaumenk          #+#    #+#              #
#    Updated: 2018/02/05 13:21:38 by anaumenk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SWITCH =        \033[
ST_NORM =   $(SWITCH)0m
COLOR_GREEN =   $(SWITCH)42m
COLOR_RED =     $(SWITCH)41m
COLOR_SGREEN = $(SWITCH)35m
NAME = libftprintf.a
O_FILES =  objects/*.o

all: $(NAME)

$(NAME): object
	@make -C srcs
	@make -C libft
	@ar rc $(NAME) $(O_FILES)
	@echo "$(STYLE_BOLD)$(COLOR_GREEN) libftprintf has been compiled.$(ST_NORM)"
	@echo "$(STYLE_BOLD)$(COLOR_SGREEN) GOOD LUCK!!!"

object:
	@mkdir -p objects

clean:
	@make clean -C libft
	@make clean -C srcs
	@rm -rf objects
	@echo "$(STYLE_BOLD)$(COLOR_RED)DIR objects have been deleted.$(ST_NORM)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(STYLE_BOLD)$(COLOR_RED)$(NAME) has been deleted.$(ST_NORM)"

re: fclean all

.PHONY: clean all fclean re