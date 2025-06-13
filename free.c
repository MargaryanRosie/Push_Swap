#include "push_swap.h"

void	free_split(char **input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		free(input[i]);
		i++;
	}
	free(input);
}

void	free_stack(t_stack *stack)     //the whole linked list
{
	t_stack *tmp;

	while(stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}