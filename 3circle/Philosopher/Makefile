NAME	= philo

SRCS_DIR	=	src

SRCS		=	main.c error.c init_data.c init_philo.c philo.c util.c util2.c monitor.c

CC		=	gcc 
# CFLAGS	=	-Wall -Werror -Wextra

all		: $(NAME)
	@$(CC) $(CFLAGS) $(addprefix $(SRCS_DIR)/, $(SRCS:.c=.o)) -o $(NAME)

$(NAME): srcs

srcs: $(addprefix $(SRCS_DIR)/, $(SRCS:.c=.o))

%.o	:%.c
	$(CC) $(CFLAGS)  -c $< -o $@

clean	:
	@rm -rf $(addprefix $(SRCS_DIR)/, $(SRCS:.c=.o))

fclean	: clean
	@rm -rf	$(NAME)

re		: fclean all

.PHONY : all clean fclean re