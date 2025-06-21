#include "../include/push_swap.h"

int	stack_size(t_stack *a)
{
	int	i;

	if (!a)
		return (0);
	i = 0;
	while (a)
	{
		i++;
		a = a->next;
	}
	return (i);
}

int	find_min_value(t_stack *stack)
{
	int	min;

	if (!stack)
		return (0);
	min = stack->number;
	stack = stack->next;
	while (stack)
	{
		if (stack->number < min)
			min = stack->number;
		stack = stack->next;
	}
	return (min);
}

int	find_min_index(t_stack *stack)
{
	int	i;
	int min;

	i = 0;
	min = find_min_value(stack);
	while (stack)
	{
		if (stack->number == min)
			return (i);
		stack = stack->next;
		i++;
	}
	return (i);
}

int	ft_sqrt(int number)
{
	int	i;

	i = 1;
	while (i < number)
	{
		if (i * i == number)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_cbrt(int number)
{
	int	i;

	i = 1;
	while (i < number)
	{
		if (i * i * i == number)
			return (i);
		i++;
	}
	return (-1);
}