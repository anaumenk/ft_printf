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

NAME = libftprintf.a
O_FILES =  objects/*.o

all: $(NAME)

$(NAME): object
	@make -C srcs
	@make -C libft
	@ar rc $(NAME) $(O_FILES)

object:
	@mkdir -p objects

clean:
	@make clean -C libft
	@make clean -C srcs
	@rm -rf objects

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: clean all fclean re