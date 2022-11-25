# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dongmlee <dongmlee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/16 22:27:38 by dongmlee          #+#    #+#              #
#    Updated: 2022/09/16 22:46:30 by dongmlee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	Iter
SRCS		= 	main.cpp
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