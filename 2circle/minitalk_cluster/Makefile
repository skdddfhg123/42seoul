CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

all:
	@cd f_printf && make all
	@cd libft && make all
	@$(CC) $(CFLAGS) server.c f_printf/libftprintf.a libft/libft.a -o server
	@$(CC) $(CFLAGS) client.c f_printf/libftprintf.a libft/libft.a -o client

clean:
	@cd f_printf && make clean
	@cd libft && make clean
	@$(RM) server
	@$(RM) client

fclean: clean
	@cd f_printf && make fclean
	@cd libft && make fclean

re: fclean all

.PHONY : all clean fclean re