/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romargar <romargar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 13:35:53 by romargar          #+#    #+#             */
/*   Updated: 2025/06/23 14:36:15 by romargar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_node(int value)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->number = value;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

void	add_back(t_stack **stack, t_stack *new_node)
{
	t_stack	*last_node;

	if (!new_node)
		return ;
	if (*stack == NULL)
	{
		*stack = new_node;
		return ;
	}
	last_node = *stack;
	while (last_node->next)
		last_node = last_node->next;
	last_node->next = new_node;
	new_node->prev = last_node;
}
