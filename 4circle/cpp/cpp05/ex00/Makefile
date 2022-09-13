# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/13 17:02:18 by idongmin          #+#    #+#              #
#    Updated: 2022/09/13 17:02:39 by idongmin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	Bureaucrat
SRCS		= 	main.cpp Bureaucrat.cpp
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
