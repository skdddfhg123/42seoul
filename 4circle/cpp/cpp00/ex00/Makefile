NAME	=	megaphone
SRCS	= 	megaphone.cpp
FLAG	= 	-std=c++98 -Wall -Wextra -Werror
CC		=	c++
RM		=	rm -rf

all		: $(NAME)

$(NAME)	: $(SRCS)
	@$(CC) $(FLAG) $(SRCS) -o $@

clean	:
	@$(RM) $(NAME)
	
fclean	: clean
	
re		: fclean all

.PHONY: all clean fclean re
