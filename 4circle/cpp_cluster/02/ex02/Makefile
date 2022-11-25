# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/08 01:20:47 by idongmin          #+#    #+#              #
#    Updated: 2022/09/08 01:20:54 by idongmin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	a.out
SRCS	= 	main.cpp Fixed.cpp
FLAG	= 	-std=c++98 -Wall -Wextra -Werror
CXX		=	c++
RM		=	rm -rf

all		: $(NAME)

$(NAME)	: $(SRCS)
	@$(CXX) $(FLAG) $(SRCS) -o $@

clean	:
	@$(RM) $(NAME)

fclean	: clean
	
re		: fclean all

.PHONY: all clean fclean re
