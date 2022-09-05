# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/05 03:29:51 by idongmin          #+#    #+#              #
#    Updated: 2022/09/05 10:52:27 by idongmin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	Replace
SRCS	= 	main.cpp
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
