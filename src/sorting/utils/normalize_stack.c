#include "../include/push_swap.h"

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

//replace each number with its index in the sorted version
void	normalize_stack(t_stack *stack)
{
	int	*arr;
	int	size;

	size = stack_size(stack);
	arr = stack_to_arr(stack, size);

	sort_array(arr, size);   //sortavorvaci index-nern em vercnum, stanum em nuyn stack-i indexed stacky
	while (stack)
	{
		stack->index = get_index(arr, size, stack->number);
		stack = stack->next;
	}
	free(arr);
}



/*
for example if the input is [50 -10 90 5]
we sort the array
[-10 5 50 90]
indexes are 0 1 2 3 

for each node in the stack i insert the index according to the number
so the indexed stack will be [ 2 0 3 1 ]
*/