#include "push_swap.h"


//i-ov flag em dnum vor haskana tpi te chtpi
void	sa(t_stack **a, int flag)
{
	t_stack	*first_node;
	t_stack	*second_node;

	if (!(*a) || !((*a)->next))
		return ;
	first_node = *a;
	second_node = first_node->next;
	first_node->next = second_node->next;
	if (second_node->next)
		second_node->next->prev = first_node;
	second_node->prev = NULL;
	second_node->next = first_node;
	first_node->prev = second_node;
	*a = second_node;
	if (flag == 0)
		write(1, "sa\n", 3);
}


void	sb(t_stack **b, int flag)
{
	t_stack	*first_node;
	t_stack	*second_node;

	if (!(*b) || !((*b)->next))
		return ;
	first_node = *b;
	second_node = first_node->next;
	first_node->next = second_node->next;
	if (second_node->next)
		second_node->next->prev = first_node;
	second_node->prev = NULL;
	second_node->next = first_node;
	first_node->prev = second_node;
	*b = second_node;
	if (flag == 0)
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a, 1);
	sb(b, 1);
	write(1, "ss\n", 3);
}


void	pa(t_stack **a, t_stack **b)
{
	t_stack	*popped_node;

	if (!(*b))
		return ;
	popped_node = pop(b);
	if (!popped_node)         //the stack was empty
		return ;
	push_node(a, popped_node);
	write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	printf("Executing pb function\n");
	t_stack	*popped_node;

	if (!(*a))
	{
		printf("a is empty\n");
		return ;
	}
	popped_node = pop(a);
	printf("popped_node value: %d\n", popped_node->number);
	if (!popped_node)
		return ;
	push_node(b, popped_node);
	write(1, "pb\n", 3);
}

