NAME = push_swap
CC = cc
CFLAGS = -g3 -fsanitize=address -Wall -Wextra -Werror -Iinclude

SRC = src/stack_operations/operations_2.c \
	src/stack_operations/operations_utils.c \
	src/stack_operations/operations.c \
	src/stack_operations/stack_node.c \
	src/validation/validation.c \
	src/sorting/sort/check_if_sorted.c \
	src/free.c \
	src/ft_split.c \
	src/ft_split_utils.c \
	src/parse_arguments.c \
	src/sorting/sort/sort_small_input.c \
	src/sorting/sort/sorting_utils.c \
	src/sorting/utils/stack_to_array.c \
	src/sorting/utils/normalize_stack.c

OBJ = $(SRC:.c=.o)
     
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)                

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re