# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/11 12:44:44 by idongmin          #+#    #+#              #
#    Updated: 2022/09/11 12:44:56 by idongmin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	Frag
SRCS		= 	main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp
CPPFLAGS	= 	-std=c++98 -Wall -Wextra -Werror
CXX			=	c++
RM			=	rm -rf

all		: $(NAME)

$(NAME)	: $(SRCS)
	@$(CXX) $(CPPFLAGS) $(SRCS) -o $@

clean	:
	@$(RM) $(NAME)

fclean	: clean

re		: fclean all

.PHONY: all clean fclean re
