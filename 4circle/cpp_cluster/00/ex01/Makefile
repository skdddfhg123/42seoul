# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/04 10:38:13 by idongmin          #+#    #+#              #
#    Updated: 2022/09/04 11:24:40 by idongmin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	phonebook
SRCS	=	main.cpp phonebook.cpp
FLAG	= 	-std=c++98 -Wall -Wextra -Werror
CC		=	c++
RM		=	rm -rf

all		=	$(NAME)

$(NAME)	:	$(SRCS)
	@$(CC) $(FLAG) $(SRCS) -o $@

clean	:
	@$(RM) $(NAME)

fclean	:	clean

re		:	fclean all

.PHONY: all clean fclean re