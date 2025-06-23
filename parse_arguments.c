/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romargar <romargar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 13:35:17 by romargar          #+#    #+#             */
/*   Updated: 2025/06/23 15:33:00 by romargar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_duplicate(t_stack *stack, int number)
{
	while (stack)
	{
		if (stack->number == number)
			return (1);
		else
			stack = stack->next;
	}
	return (0);
}

static void	validation(char **inputs, int *number, int j, t_stack **stack)
{
	int	overflow;

	if (!is_valid_number(inputs[j]))
	{
		free_split(inputs);
		free_stack(*stack);
		error_exit();
	}
	*number = ft_atoi(inputs[j], &overflow);
	if (overflow)
	{
		free_split(inputs);
		free_stack(*stack);
		error_exit();
	}
	if (is_duplicate(*stack, *number))
	{
		free_split(inputs);
		free_stack(*stack);
		error_exit();
	}
}

static void	handle_input(char **inputs, t_stack **stack)
{
	int	j;
	int	number;

	j = 0;
	if (inputs[j] == NULL)
	{
		free_split(inputs);
		free_stack(*stack);
		error_exit();
	}
	while (inputs[j])
	{
		validation(inputs, &number, j, stack);
		add_back(stack, new_node(number));
		j++;
	}
	free_split(inputs);
}

t_stack	*parse_arguments(int argc, char *argv[])
{
	t_stack	*stack;
	char	**inputs;
	int		i;

	stack = NULL;
	i = 1;
	while (i < argc)
	{
		inputs = ft_split(argv[i]);
		if (!inputs)
		{
			printf("split returns NULL");
			free_stack(stack);
			error_exit();
		}
		handle_input(inputs, &stack);
		i++;
	}
	return (stack);
}
