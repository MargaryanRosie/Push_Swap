#include "../include/push_swap.h"

void	sort_two(t_stack **a)
{
	if ((*a)->number > (*a)->next->number)
		sa(a, 0);
}

void	sort_three(t_stack **a)
{
	t_stack	*k;
	t_stack	*n;

	k = (*a)->next;
	n = k->next;
	if ((*a)->number > k->number && (*a)->number > n->number)
	{
		ra(a, 0);
		if (!is_sorted(*a))
			sa(a, 0);
	}
	else if ((*a)->number < k->number && (*a)->number < n->number)          //[1 3 2]    [1 2 3]
	{
		rra(a, 0);
		if (!is_sorted(*a))
			sa(a, 0);
	}
	else           //[2 1 3]   or [2 3 1]
	{
		if (k->number > (*a)->number && k->number > n->number)     //max is second
			rra(a, 0);
		else if (n->number > (*a)->number && n->number > k->number)
			sa(a, 0);                                                  //max is third
	}
}


void	sort_four(t_stack **a, t_stack **b)
{
	int	i;
	int	rotations;

	if (!a ||!(*a) || !b)
		return ;
	//ete kesic poqr e indexy, ra(), ete kesic mec rra()
	i = find_min_index(*a);
	if (i <= stack_size(*a)/2)
	{
		while (i > 0)
		{
			ra(a, 0);
			i--;
		}
	}
	else
	{
		rotations = stack_size(*a) - i;
		while (rotations > 0)
		{
			rra(a, 0);
			rotations--;
		}
	}
	pb(a, b);
	sort_three(a);
	pa(a, b);
}