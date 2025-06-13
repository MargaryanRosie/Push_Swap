#include "push_swap.h"

t_stack	*new_node(int value)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	new_node->number = value;
	new_node->next = NULL;
	return (new_node);
}


void	add_back(t_stack **stack, t_stack *new_node)
{
	t_stack	*last_node;

	if (*stack == NULL)
	{
		*stack = new_node;
		return ;
	}
	last_node = *stack;
	while (last_node->next)
		last_node = last_node->next;
	last_node->next = new_node;
	new_node->prev = last_node;
	new_node->next = NULL;
}