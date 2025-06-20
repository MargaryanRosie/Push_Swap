NAME = push_swap
CC = cc
S = -g3 -fsanitize=address
CFLAGS = -Wall -Wextra -Werror -Iinclude

SRC = src/stack_operations/operations_2.c \
	src/stack_operations/operations_utils.c \
	src/stack_operations/operations.c \
	src/stack_operations/stack_node.c \
	src/validation/validation.c \
	src/sorting/check_if_sorted.c \
	src/free.c \
	src/ft_split.c \
	src/ft_split_utils.c \
	src/parse_arguments.c \
	src/sorting/sort_small_input.c \
	src/sorting/sorting_utils.c

OBJ = $(SRC:.c=.o)
     
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(S) $(CFLAGS) $(OBJ) -o $(NAME)                

%.o: %.c
	$(CC) $(S) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re