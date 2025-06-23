/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_to_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romargar <romargar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 13:35:58 by romargar          #+#    #+#             */
/*   Updated: 2025/06/23 14:36:04 by romargar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*stack_to_arr(t_stack *stack, int size)
{
	int	*array;
	int	i;

	if (!stack)
		return (NULL);
	array = (int *)malloc(sizeof(int) * size);
	if (!array)
		return (NULL);
	i = 0;
	while (stack)
	{
		array[i] = stack->number;
		stack = stack->next;
		i++;
	}
	return (array);
}

void	sort_array(int *array, int size)
{
	int	i;
	int	j;
	int	tmp;
	int	min_index;

	i = 0;
	while (i < size)
	{
		min_index = i;
		j = i + 1;
		while (j < size)
		{
			if (array[j] < array[min_index])
				min_index = j;
			j++;
		}
		if (array[i] > array[min_index])
		{
			tmp = array[i];
			array[i] = array[min_index];
			array[min_index] = tmp;
		}
		i++;
	}
}
