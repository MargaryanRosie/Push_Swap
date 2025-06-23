/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_with_butterfly.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romargar <romargar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 13:35:38 by romargar          #+#    #+#             */
/*   Updated: 2025/06/23 14:37:52 by romargar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_position(t_stack **b, int index)
{
	t_stack	*tmp;
	int		pos;

	tmp = *b;
	pos = 0;
	while (tmp)
	{
		if (tmp->index == index)
			return (pos);
		pos++;
		tmp = tmp->next;
	}
	return (-1);
}

static void	push_back(t_stack **a, t_stack **b)
{
	int	max_index;
	int	pos;

	while (*b)
	{
		max_index = stack_size(*b) - 1;
		pos = find_position(b, max_index);
		if ((*b)->index == max_index)
			pa(a, b, 0);
		else if (pos <= stack_size(*b) / 2)
		{
			while ((*b)->index != max_index)
				rb(b, 0);
			pa(a, b, 0);
		}
		else
		{
			while ((*b)->index != max_index)
				rrb(b, 0);
			pa(a, b, 0);
		}
	}
}

static int	define_chunk_size(int size)
{
	int	chunk_count;
	int	chunk_size;

	if (size > 5 && size <= 100)
		chunk_count = 5;
	else if (size <= 500)
		chunk_count = 14;
	else
		chunk_count = 25;
	chunk_size = size / chunk_count;
	if (chunk_size == 0)
		chunk_size = 1;
	return (chunk_size);
}

void	butterfly_sort(t_stack **a, t_stack **b)
{
	int	next_expected;
	int	chunk_size;
	int	current_index;

	next_expected = 0;
	chunk_size = define_chunk_size(stack_size(*a));
	while (*a)
	{
		current_index = (*a)->index;
		if (current_index <= next_expected)
		{
			pb(a, b, 0);
			rb(b, 0);
			next_expected++;
		}
		else if (current_index <= next_expected + chunk_size)
		{
			pb(a, b, 0);
			next_expected++;
		}
		else
			ra(a, 0);
	}
	push_back(a, b);
}
