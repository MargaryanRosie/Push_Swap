#include "push_swap.h"

//top becomes buttom    

//[10] [20] [30]
//[20] [30] [10]

void	ra(t_stack **a, int flag)
{
	t_stack	*first_node;
	t_stack	*last_node;

	if(!(*a) || !((*a)->next))
		return ;
	first_node = *a;
	//to find the last node we need to go from first to last
	last_node = *a;
	while (last_node->next)
		last_node = last_node->next;
	//last node is already pointing to the last element
	*a = first_node->next;
	(*a)->prev = NULL;
	first_node->next = NULL;
	last_node->next = first_node;
	first_node->prev = last_node;
	if (flag == 0)
		write(1, "ra\n", 3);
}


void	rb(t_stack **b, int flag)
{
	t_stack	*first_node;
	t_stack	*last_node;

	if(!(*b) || !((*b)->next))
		return ;
	first_node = *b;
	//to find the last node we need to go from first to last
	last_node = *b;
	while (last_node->next)
		last_node = last_node->next;
	//last node is already pointing to the last element
	*b = first_node->next;
	(*b)->prev = NULL;
	first_node->next = NULL;
	last_node->next = first_node;
	first_node->prev = last_node;
	if (flag == 0)
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a, 1);
	rb(b, 1);
	write(1, "r\n", 3);
}