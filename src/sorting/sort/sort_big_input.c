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

void	binary_radix_sort(t_stack **a, t_stack **b)
{
	//arden hamarum enq vor stack a-n normalize arac e
	int	size;
	int	max_bits;
	int	i;
	int	j;

	size = stack_size(*a);
	max_bits = get_max_bits(*a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			//1- y ...001 e, mnacacy zroyanum en
			if ((((*a)->index >> i) & 1) == 0)            //if the least significant bit is 0, we push it to stack B
				pb(a, b);
			else                                          //if the lsb is 1, we just rotate it in the stack a
				ra(a, 0);
			j++;
		}
		while (*b)                  //we push back the elements of b
			pa(a, b);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack *stack_b;              //push_nodei mej e stack_b- i NULL y handle anelu pahy

	stack_b = NULL;
	stack_a = parse_arguments(argc, argv);
	if (!stack_a)
	{
		printf("error");
		exit(1);
	}
	normalize_stack(stack_a);    //we initialize the indexes in stack a
	int max_bits = get_max_bits(stack_a);
	printf("max bits: %d\n", max_bits);
	binary_radix_sort(&stack_a, &stack_b);
	t_stack *a = stack_a;
	while (stack_a)
	{
		printf("indexes: %d\n", stack_a->index);
		printf("numbers: %d\n", stack_a->number);
		stack_a = stack_a->next;
	}
	free_stack(a);
	return (0);
}

