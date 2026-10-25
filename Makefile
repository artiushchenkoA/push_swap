NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./inc
RM = rm -f

SRCS = main.c \
	lib/free_stack.c \
	lib/ft_atol.c \
	lib/ft_isdigit.c \
	lib/ft_split.c \
	lib/ft_strcmp.c \
	lib/stack_add_back.c \
	lib/stack_new_node.c \
	lib/stack_size.c \
	lib/find_max.c \
	lib/find_max_pos.c \
	lib/find_min_pos.c \
	lib/ft_putchar_fd.c \
	lib/ft_putendl_fd.c \
	lib/ft_putnbr_fd.c \
	lib/ft_putstr_fd.c \
	lib/is_sorted.c \
	lib/sort_array.c \
	lib/index.c \
	lib/disorder.c \
	lib/sorting.c \
	src/algorithms/adaptive.c \
	src/algorithms/bench.c \
	src/algorithms/medium.c \
	src/algorithms/quick.c \
	src/algorithms/simple.c \
	src/operations/push.c \
	src/operations/reverse.c \
	src/operations/rotate.c \
	src/operations/swap.c \
	src/parsing/parsing_argv.c \
	src/parsing/stack_check.c \
	src/parsing/parsing_flag.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
