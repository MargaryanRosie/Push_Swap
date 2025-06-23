/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romargar <romargar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 13:32:26 by romargar          #+#    #+#             */
/*   Updated: 2025/06/23 13:32:28 by romargar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index(int *arr, int size, int num)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == num)
			return (i);
		i++;
	}
	return (-1);
}

void	normalize_stack(t_stack *stack)
{
	int	*arr;
	int	size;

	size = stack_size(stack);
	arr = stack_to_arr(stack, size);
	sort_array(arr, size);
	while (stack)
	{
		stack->index = get_index(arr, size, stack->number);
		stack = stack->next;
	}
	free(arr);
}