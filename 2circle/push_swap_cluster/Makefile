NAME	= push_swap
CHECKER	= checker

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
AR		= ar rcs
RM		= rm -f

CHECKER_SRC	=	checker.c\

CHECKER_OBJ	=	checker.o\

PUSHSWAP_SRC	=	pushswap.c \

PUSHSWAP_OBJ	=	pushswap.o \

SRCS	=	src/r.c \
			src/rr.c \
			src/ps.c \
			src/checker_r.c \
			src/checker_rr.c \
			src/checker_ps.c \
			src/display.c \
			check/main_func.c \
			check/atoi_revised.c \
			check/argv_check.c \
			check/overlap_check.c \
			sort/Ta_to_b.c \
			sort/Ba_to_b.c \
			sort/Tb_to_a.c \
			sort/Bb_to_a.c \
			sort/sort_handler.c \
			sort/sort_Ta_three.c \
			sort/sort_Ba_three.c \
			sort/sort_Tb_three.c \
			sort/sort_Bb_three.c \
			sort/sort_element_two.c \
			sort/short_element_handler.c \


OBJ		=	r.o \
			rr.o \
			ps.o \
			checker_r.o \
			checker_rr.o \
			checker_ps.o \
			display.o \
			main_func.o \
			atoi_revised.o \
			argv_check.o \
			overlap_check.o \
			Ta_to_b.o \
			Ba_to_b.o \
			Tb_to_a.o \
			Bb_to_a.o \
			sort_handler.o \
			sort_Ta_three.o \
			sort_Ba_three.o \
			sort_Tb_three.o \
			sort_Bb_three.o \
			sort_element_two.o \
			short_element_handler.o \

OBJS	= $(SRCS:.c=.o)

PUSHSWAP_OBJ	= $(PUSHSWAP_SRC:.c=.o)

CHECKER_OBJ	= $(CHECKER_SRC:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c $< -I.

$(NAME) : $(OBJS)

all : $(NAME)
	@cd linkedlist && make all
	@cd lib && make all
	@$(CC) $(CFLAGS) $(SRCS) $(PUSHSWAP_SRC) lib/dongmlee.a linkedlist/linkedlist.a -o $(NAME)
	@$(CC) $(CFLAGS) $(SRCS) $(CHECKER_SRC) lib/dongmlee.a linkedlist/linkedlist.a -o $(CHECKER)

clean:
	@cd linkedlist && make clean
	@cd lib && make clean
	@$(RM) $(OBJ) 
	@$(RM) $(PUSHSWAP_OBJ)
	@$(RM) $(CHECKER_OBJ)


fclean: clean
	@cd linkedlist && make fclean
	@cd lib && make fclean
	@$(RM) $(NAME)
	@$(RM) $(CHECKER)

re: fclean all

.PHONY : all clean fclean re