#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

void	push_node(t_stack **stack, t_stack *node)
{
	if (!stack || !node)
		return ;

	node->next = *stack;
	if (*stack)
		(*stack)->prev = node;
	node->prev = NULL;
	*stack = node;
}

t_stack	*pop(t_stack **stack)
{
	t_stack	*top;

	if (!(*stack) || !stack)
		return NULL;
	top = *stack;
	*stack = top->next;
	if (*stack)
		(*stack)->prev = NULL;
	top->next = NULL;
	top->prev = NULL;
	return (top);
}


//top becomes buttom    

//[10] [20] [30]
//[20] [30] [10]

void	rotate(t_stack **stack)
{
	if(!(*stack) || !((*stack)->next))
		return ;
	
	t_stack *first_node = *stack;

	//to find the last node we need to go from first to last
	t_stack *last_node = *stack;

	while (last_node->next)
		last_node = last_node->next;
	
	//last node is already pointing to the last element
	*stack = first_node->next;
	(*stack)->prev = NULL;

	first_node->next = NULL;
	last_node->next = first_node;
	first_node->prev = last_node;
}


//reverse rotate, bottom becomes top

//[10] [20] [30]
//[30] [10] [20]


void reverse_rotate(t_stack **stack)
{
	if(!(*stack) || !((*stack)->next))
		return ;

	t_stack *first_node = *stack;
	t_stack *last_node = *stack;

	while (last_node->next)
		last_node = last_node->next;
	
	last_node->prev->next = NULL;
	last_node->prev = NULL;
	last_node->next = first_node;
	first_node->prev = last_node;

	*stack = last_node;
}