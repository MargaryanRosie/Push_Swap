/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romargar <romargar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 13:35:23 by romargar          #+#    #+#             */
/*   Updated: 2025/06/23 14:39:06 by romargar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stack **stack_a, t_stack **stack_b, int size)
{
	normalize_stack(*stack_a);
	if (size == 2)
		sort_two(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size == 4)
		sort_four(stack_a, stack_b);
	else if (size == 5)
		sort_five(stack_a, stack_b);
	else
		butterfly_sort(stack_a, stack_b);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size;

	if (argc == 1)
		return (0);
	stack_b = NULL;
	stack_a = parse_arguments(argc, argv);
	if (!stack_a)
		error_exit();
	if (is_sorted(stack_a))
	{
		free_stack(stack_a);
		return (0);
	}
	size = stack_size(stack_a);
	sort_stack(&stack_a, &stack_b, size);
	free_stack(stack_a);
	return (0);
}
