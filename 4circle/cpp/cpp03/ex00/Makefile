# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/08 05:04:32 by idongmin          #+#    #+#              #
#    Updated: 2022/09/09 17:13:55 by idongmin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	ClapTrap
SRCS		= 	main.cpp ClapTrap.cpp
CPPFLAGS	= 	-std=c++98 -Wall -Wextra -Werror
CCP			=	c++
RM			=	rm -rf

all		: $(NAME)

$(NAME)	: $(SRCS)
	@$(CCP) $(CPPFLAGS) $(SRCS) -o $@

clean	:
	@$(RM) $(NAME)
	
fclean	: clean
	
re		: fclean all

.PHONY: all clean fclean re
