#include "push_swap.h"

//take the input and store it in the stack;


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
	int		number;

	if (argc == 2)
		inputs = ft_split(argv[1]);
	else
		inputs = &argv[1];
	i = 0;
	stack = NULL;
	while (inputs[i])
	{
		if (!is_valid_number(inputs[i]))
			error_exit();
		number = ft_atoi(inputs[i]);
		if (is_duplicate(stack, number))              //if stack is NULL, returns 0
			error_exit();
		add_back(&stack, new_node(number));          //if *stack is NULL, this is handled in add_back function
		i++;	
	}
	//if input was allocated by ft_split
	if (argc == 2)
		free_split(inputs);
	return (stack);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;

	stack_a = parse_arguments(argc, argv);
	if (!stack_a)
		error_exit();
	if (is_sorted(stack_a))
	{
		free_stack(stack_a);
		return (0);
	}
	i = 1;
	t_stack	*a = stack_a;
	while (a)
	{
		printf("Before popping\nin stack_a\nvalue %d: %d\n", i, a->number);
		a = a->next;
		i++;
	}
	stack_b = NULL;
	pb(&stack_a, &stack_b);
	i = 1;
	while (stack_a)
	{
		printf("in stack_a\nvalue %d: %d\n", i, stack_a->number);
		stack_a = stack_a->next;
		i++;
	}
	printf("\n");
	i = 1;
	while (stack_b)
	{
		printf("in stack_b\nvalue %d: %d\n", i, stack_b->number);
		stack_b = stack_b->next;
		i++;
	}
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}