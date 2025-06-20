#include "../include/push_swap.h"

int	is_duplicate(t_stack *stack, int number)
{
	while (stack)
	{
		if (stack->number == number)
			return (1);             //duplicate found
		else
			stack = stack->next;
	}
	return (0);
}

t_stack	*parse_arguments(int argc, char *argv[])
{
	t_stack	*stack;
	char	**inputs;
	int		i;
	int		j;
	int		number;

	stack = NULL;
	i = 1;
	while (i < argc)
	{
		inputs = ft_split(argv[i]);
		if (!inputs)
		{
			free_stack(stack);
			error_exit();
		}
		j = 0;
		while (inputs[j])
		{
			if (!is_valid_number(inputs[j]))
			{
				free_stack(stack);
				error_exit();
			}
			number = ft_atoi(inputs[j]);
			if (is_duplicate(stack, number))
			{
				free_stack(stack);
				error_exit();
			}
			add_back(&stack, new_node(number));          //if *stack is NULL, this is handled in add_back function
			j++;
		}
		free_split(inputs);
		i++;
	}
	return (stack);
}

// int	main(int argc, char *argv[])
// {
// 	t_stack	*stack_a;
// 	t_stack *stack_b;

// 	stack_b = NULL;

// 	stack_a = parse_arguments(argc, argv);
// 	if (!stack_a)
// 	{
// 		printf("error");
// 		exit(1);
// 	}
// 	//sort_two(&stack_a);
// 	//sort_three(&stack_a);
// 	// int min = find_min_value(stack_a);
// 	// int min_index = find_min_index(stack_a);
// 	// printf("min: %d\n", min);
// 	// printf("min index: %d\n", min_index);
// 	//sort_four(&stack_a, &stack_b);
// 	sort_five(&stack_a, &stack_b);
// 	t_stack *a = stack_a;
// 	while (stack_a)
// 	{
// 		printf("%d\n", stack_a->number);
// 		stack_a = stack_a->next;
// 	}
// 	free_stack(a);
// 	a = NULL;
// 	return (0);
// }