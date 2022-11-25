# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dongmlee <dongmlee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/06 12:22:06 by idongmin          #+#    #+#              #
#    Updated: 2022/09/07 16:10:39 by dongmlee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	harlFilter
SRCS	= 	main.cpp Harl.cpp
FLAG	= 	-std=c++98 -Wall -Wextra -Werror
CXX		=	c++
RM		=	rm -rf

all		: $(NAME)

$(NAME)	: $(SRCS)
	$(CXX) $(FLAG) $(SRCS) -o $@

clean	:
	@$(RM) $(NAME)
	
fclean	: clean
	
re		: fclean all

.PHONY: all clean fclean re
