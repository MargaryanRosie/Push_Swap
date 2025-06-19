#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>


typedef struct s_stack
{
	int				number;
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
int	is_digit(char c);
void	error_exit(void);
int	is_valid_number(char *str);
void	check_overflow(long result, int sign);
int	ft_atoi(char *str);
int	is_sorted(t_stack *stack);
void	free_stack(t_stack *stack);
void	push_node(t_stack **stack, t_stack *node);
t_stack	*pop(t_stack **stack);
void	sa(t_stack **a, int flag);
void	sb(t_stack **b, int flag);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a, int flag);
void	rb(t_stack **b, int flag);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a, int flag);
void	rrb(t_stack **b, int flag);
void	rrr(t_stack **a, t_stack **b);

#endif