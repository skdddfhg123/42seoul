# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dongmlee <dongmlee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/06 11:28:57 by idongmin          #+#    #+#              #
#    Updated: 2022/09/07 15:17:00 by dongmlee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	Zombie
SRCS	= 	main.cpp Zombie.cpp ZombieHorde.cpp
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
