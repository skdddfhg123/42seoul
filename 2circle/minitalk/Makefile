CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

all:
	@cd ft_printf && make all
	@cd libft && make all
	@$(CC) $(CFLAGS) server.c ft_printf/libftprintf.a libft/libft.a -o server
	@$(CC) $(CFLAGS) client.c ft_printf/libftprintf.a libft/libft.a -o client

clean:
	@cd ft_printf && make clean
	@cd libft && make clean
	@$(RM) server
	@$(RM) client

fclean: clean
	@cd ft_printf && make fclean
	@cd libft && make fclean

re: fclean all

.PHONY : all clean fclean re