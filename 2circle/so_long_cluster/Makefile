NAME	= so_long

SRCS_DIR	=	src

SRCS		=	main.c \
				error.c \
				map.c \
				map_check.c \
				map_check2.c \
				insert.c \
				draw.c \
				move.c \

MLX		=	mlx
MLX_LIB	= 	libmlx.a
CC		=	gcc 
CFLAGS	=	-Wall -Werror -Wextra
CLIB	=	-lmlx -framework OpenGL -framework Appkit -framework OpenCL

all		: $(NAME)
	@cd lib && make all
	@make -C $(MLX)
	@$(CC) $(CFLAGS) -L $(MLX) $(CLIB) $(addprefix $(SRCS_DIR)/, $(SRCS:.c=.o)) $(MLX)/$(MLX_LIB) lib/dongmlee.a -o $(NAME)

$(NAME): srcs

srcs: $(addprefix $(SRCS_DIR)/, $(SRCS:.c=.o))

%.o	:%.c
	$(CC) $(CFLAGS)  -c $< -o $@

clean	:
	@cd lib && make clean
	@cd $(MLX) && make clean
	@rm -rf $(addprefix $(SRCS_DIR)/, $(SRCS:.c=.o))

fclean	: clean
	@cd lib && make fclean
	@rm -rf	$(NAME)

re		: fclean all

.PHONY : all clean fclean re