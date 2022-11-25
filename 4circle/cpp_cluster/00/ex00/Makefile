# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/19 18:40:09 by idongmin          #+#    #+#              #
#    Updated: 2022/07/19 18:44:47 by idongmin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	megaphone
SRCS	= 	megaphone.cpp
FLAG	= 	-std=c++98 -Wall -Wextra -Werror
CC		=	c++
RM		=	rm -rf

all		: $(NAME)

$(NAME)	: $(SRCS)
	@$(CC) $(FLAG) $(SRCS) -o $@

clean	:
	@$(RM) $(NAME)
	
fclean	: clean
	
re		: fclean all

.PHONY: all clean fclean re
