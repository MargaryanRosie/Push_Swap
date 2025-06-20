#include "../include/push_swap.h"

//for using radix sort we first need to know the max bits, this means we find the max number and compute the bits
//and as we converted the stack to indexes, we do all these with the indexes

int	get_max_bits(t_stack *stack)
{
	int	max;
	int	i;

	max = 0;
	while (stack)
	{
		if (stack->index > max)
			max = stack->index;
		stack = stack->next;
	}
	i = 0;
	while ((max >> i) != 0)
		i++;
	return (i);
}

// int	main(int argc, char *argv[])
// {
// 	t_stack	*stack_a;

// 	stack_a = parse_arguments(argc, argv);
// 	if (!stack_a)
// 	{
// 		printf("error");
// 		exit(1);
// 	}
// 	int max_bits = get_max_bits(stack_a);
// 	printf("%d\n", max_bits);
// 	t_stack *a = stack_a;
// 	while (stack_a)
// 	{
// 		printf("%d\n", stack_a->number);
// 		stack_a = stack_a->next;
// 	}
// 	free_stack(a);
// 	return (0);
// }

