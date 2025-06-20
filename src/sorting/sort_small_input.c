#include "../include/push_swap.h"

void	sort_two(t_stack **a)
{
	if ((*a)->number > (*a)->next->number)
		sa(a, 0);
}

void	sort_three(t_stack **a)
{
	int	f;
	int	s;
	int	t;

	f = (*a)->number;
	s = (*a)->next->number;
	t = (*a)->next->next->number;
	if (f > s && s < t && f < t)
		sa(a, 0);
	else if (f > s && s > t && f > t)
	{
		sa(a, 0);
		rra(a, 0);
	}
	else if (f > s && s < t && f > t)
		ra(a, 0);
	else if (f < s && s > t && f < t)
	{
		sa(a, 0);
		ra(a, 0);
	}
	else if (f < s && s > t && f > t)
		rra(a, 0);
}




void	sort_four(t_stack **a, t_stack **b)
{
	int	i;

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
		i = stack_size(*a) - i;
		while (i > 0)
		{
			rra(a, 0);
			i--;
		}
	}
	pb(a, b);
	sort_three(a);
	pa(a, b);
}

void	sort_five(t_stack **a, t_stack **b)
{
	int	i;

	i = find_min_index(*a);
	printf("min index: %d\n", i);
	if (i <= stack_size(*a) / 2)
	{
		while (i > 0)
		{
			ra(a, 0);
			printf("after ra(): %d\n", (*a)->number);
			i--;
		}
	}
	else
	{
		i = stack_size(*a) - i;
		while (i > 0)
		{
			rra(a, 0);
			printf("after rra(): %d\n", (*a)->number);
			i--;
		}
	}
	pb(a, b);
	printf("after pb(): a: %d\nb: %d\n", (*a)->number, (*b)->number);
	sort_four(a, b);
	printf("after sort four: a: %d\nb: %d\n", (*a)->number, (*b)->number);
	pa(a, b);
	//pa(a, b);
}