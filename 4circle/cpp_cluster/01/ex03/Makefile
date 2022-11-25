# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/04 16:29:30 by idongmin          #+#    #+#              #
#    Updated: 2022/09/06 11:52:03 by idongmin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	Weapon
SRCS	= 	main.cpp HumanA.cpp HumanB.cpp Weapon.cpp
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
