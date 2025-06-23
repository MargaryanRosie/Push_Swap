/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romargar <romargar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 13:35:04 by romargar          #+#    #+#             */
/*   Updated: 2025/06/23 14:40:20 by romargar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

void	push_node(t_stack **stack, t_stack *node)
{
	if (!stack || !node)
		return ;
	node->next = *stack;
	if (*stack)
		(*stack)->prev = node;
	node->prev = NULL;
	*stack = node;
}

t_stack	*pop(t_stack **stack)
{
	t_stack	*top;

	if (!(*stack) || !stack)
		return (NULL);
	top = *stack;
	*stack = top->next;
	if (*stack)
		(*stack)->prev = NULL;
	top->next = NULL;
	top->prev = NULL;
	return (top);
}
