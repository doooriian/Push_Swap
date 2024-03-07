NAME	= push_swap

CC		= clang

CFLAGS	= -Wall -Wextra -Werror -g3

RM		= rm -f

SRC		= srcs/algo/init_a_to_b.c srcs/algo/init_b_to_a.c srcs/algo/sort_stacks_utils.c srcs/algo/sort_stacks.c srcs/algo/tiny_sort.c \
		  srcs/commands/push.c srcs/commands/rev_rotate.c srcs/commands/rotate.c srcs/commands/swap.c \
		  srcs/push_swap/error_free.c srcs/push_swap/main.c srcs/push_swap/split.c srcs/push_swap/stack_init.c srcs/push_swap/stack_utils.c

OBJ		= $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re