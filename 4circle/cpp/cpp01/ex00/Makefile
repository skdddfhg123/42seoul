# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/06 11:18:51 by idongmin          #+#    #+#              #
#    Updated: 2022/09/06 11:19:13 by idongmin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	Zombie
SRCS	= 	main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
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
