# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: romargar <romargar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/23 13:32:22 by romargar          #+#    #+#              #
#    Updated: 2025/06/23 16:28:04 by romargar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude

SRC = operations_2.c \
	operations_utils.c \
	operations.c \
	operations_1.c \
	stack_node.c \
	validation.c \
	check_if_sorted.c \
	free.c \
	ft_split.c \
	ft_split_utils.c \
	parse_arguments.c \
	sort_small_input.c \
	sorting_utils.c \
	stack_to_array.c \
	normalize_stack.c \
	sort_big_with_butterfly.c \
	push_swap.c

BONUS_SRC = ft_split.c \
	ft_split_utils.c \
	parse_arguments.c \
	validation.c \
	check_if_sorted.c \
	ft_strncmp.c \
	get_next_line.c get_next_line_utils.c \
	operations_2.c \
	operations_utils.c \
	operations.c \
	operations_1.c \
	free.c \
	stack_node.c \
	checker.c \
	sorting_utils.c

OBJ = $(SRC:.c=.o)

BONUS_OBJ = $(BONUS_SRC:.c=.o)
     
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(BONUS_NAME): $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) -o $(BONUS_NAME)  

bonus: $(BONUS_NAME)               

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus