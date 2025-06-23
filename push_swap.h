/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romargar <romargar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 13:35:28 by romargar          #+#    #+#             */
/*   Updated: 2025/06/23 13:35:29 by romargar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int		number;   // Original value
    int		index;    // Index used for sort
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;


void	free_remaining(char **output, int j);
char *ft_strncpy(char *dest, char *src, int n);
int	allocate_word(char **output, char *str, int start, int i, int j);
int	process_word(char **output, char *str, int *i, int *j);
int	word_count(char *str);
void	skip_spaces(char *str, int *i);
void	loop_the_word(char *str, int *i);
char	**ft_split(char *str);
int	is_duplicate(t_stack *stack, int number);
void	free_split(char **input);
t_stack	*parse_arguments(int argc, char *argv[]);
t_stack	*new_node(int value);
void	add_back(t_stack **stack, t_stack *new_node);
int		is_digit(char c);
void	error_exit(void);
int		is_valid_number(char *str);
int		check_overflow(long long result, int sign);
int		ft_atoi(char *str, int *overflow);
int		is_sorted(t_stack *stack);
void	free_stack(t_stack *stack);
void	push_node(t_stack **stack, t_stack *node);
t_stack	*pop(t_stack **stack);
void	sa(t_stack **a, int flag);
void	sb(t_stack **b, int flag);
void	ss(t_stack **a, t_stack **b, int flag);
void	pa(t_stack **a, t_stack **b, int flag);
void	pb(t_stack **a, t_stack **b, int flag);
void	ra(t_stack **a, int flag);
void	rb(t_stack **b, int flag);
void	rr(t_stack **a, t_stack **b, int flag);
void	rra(t_stack **a, int flag);
void	rrb(t_stack **b, int flag);
void	rrr(t_stack **a, t_stack **b, int flag);
void	sort_two(t_stack **a);
void	sort_three(t_stack **a);
int		find_min_value(t_stack *stack);
int		find_min_index(t_stack *stack);
int		stack_size(t_stack *a);
void	sort_four(t_stack **a, t_stack **b);
void	sort_five(t_stack **a, t_stack **b);
int		*stack_to_arr(t_stack *stack, int size);
int		get_index(int *arr, int size, int num);
void	sort_array(int *array, int size);
int		get_max_bits(t_stack *stack);
void	normalize_stack(t_stack *stack);
void	binary_radix_sort(t_stack **a, t_stack **b);
void	sort_stack(t_stack **stack_a, t_stack **stack_b, int size);
int		ft_sqrt(int number);
int		ft_cbrt(int number);
void	butterfly_sort(t_stack **a, t_stack **b);
int		ft_strncmp(char *s1, char *s2, int n);

# endif