#include "push_swap.h"

void	rra(t_stack **a, int flag)
{
	t_stack	*first_node;
	t_stack	*last_node;

	if (!(*a) || !((*a)->next))
		return ;
	first_node = *a;
	last_node = *a;
	while (last_node->next)
		last_node = last_node->next;
	if (last_node->prev)
		last_node->prev->next = NULL;
	last_node->prev = NULL;
	last_node->next = first_node;
	first_node->prev = last_node;
	*a = last_node;
	if (flag == 0)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, int flag)
{
	t_stack	*first_node;
	t_stack	*last_node;

	if (!(*b) || !((*b)->next))
		return ;
	first_node = *b;
	last_node = *b;
	while (last_node->next)
		last_node = last_node->next;
	if (last_node->prev)
		last_node->prev->next = NULL;
	last_node->prev = NULL;
	last_node->next = first_node;
	first_node->prev = last_node;
	*b = last_node;
	if (flag == 0)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b, int flag)
{
	rra(a, 1);
	rrb(b, 1);
	if (flag == 0)
		write(1, "rrr\n", 4);
}
