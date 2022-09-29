CFLAGS = -Wall -Wextra -Werror -Iinclude
CC = gcc

# brew info readline
# 인텔 맥 ( 클러스터 PC X )
# READLINE_LIB 	= -lreadline -L/usr/local/opt/readline/lib
# READLINE_INC	= -I/usr/local/opt/readline/include

# 인텔 맥 ( 클러스터 PC O )
READLINE_LIB 	= -lreadline -L /Users/$(USER)/.brew/opt/readline/lib
READLINE_INC	= -I /Users/$(USER)/.brew/opt/readline/include

# M1 맥 ( 클러스터 PC X )
# READLINE_LIB	= -lreadline -L/opt/homebrew/opt/readline/lib
# READLINE_INC	= -I/opt/homebrew/opt/readline/include

SRCS = srcs/main.c \
			srcs/parse/check_pipe.c \
			srcs/parse/get_input.c \
			srcs/parse/init.c \
			srcs/parse/signal.c \
			srcs/parse/key.c \
			srcs/parse/parse.c \
			srcs/parse/redir_file.c \
			srcs/parse/redir_utils.c \
			srcs/parse/redir.c \
			srcs/parse/store_envp.c \
			srcs/utils/error.c \
			srcs/utils/join.c \
			srcs/utils/split.c \
			srcs/ternel/change_struct.c \
			srcs/ternel/change_type.c \
			srcs/execute/execute.c \
			srcs/execute/here_doc.c \
			srcs/execute/pipe.c \
			srcs/execute/redirection.c \
			srcs/execute/tree.c \
			srcs/builtin/ft_echo.c \
			srcs/builtin/ft_pwd.c \
			srcs/builtin/ft_env.c \
			srcs/builtin/ft_exit.c \
			srcs/builtin/ft_unlink.c \
			srcs/builtin/ft_unset.c \
			srcs/builtin/ft_cd_err.c \
			srcs/builtin/ft_cd_home.c \
			srcs/builtin/ft_cd_util.c \
			srcs/builtin/ft_cd.c \
			srcs/builtin/ft_export_util2.c \
			srcs/builtin/ft_export_util.c \
			srcs/builtin/ft_export.c \
			srcs/parse/get_heredoc.c \
			srcs/ternel/ternel_utils.c \
			srcs/utils/ft_lstadd_back.c

LIBFT = libft/libft.a

NAME = minishell

OBJS = $(SRCS:.c=.o)

all:  $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(READLINE_INC) $(READLINE_LIB)

$(LIBFT):
	@make -C ./libft

%.o: %.c
	@$(CC) $(CFLAGS) $(READLINE_INC) -c $< -o $@

clean:
	@make clean -C libft/
	@rm -rf $(OBJS)

fclean: clean
	@make fclean -C libft/
	@rm -rf $(NAME) $(OBJS)

re : fclean all

.PHONY : fclean all
