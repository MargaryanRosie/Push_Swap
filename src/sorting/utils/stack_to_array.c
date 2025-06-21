#include "../include/push_swap.h"

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

// int	main(int argc, char *argv[])
// {
// 	t_stack	*stack_a;
// 	int		*arr;
// 	int size;

// 	stack_a = parse_arguments(argc, argv);
// 	if (!stack_a)
// 	{
// 		printf("error");
// 		exit(1);
// 	}
// 	size = stack_size(stack_a);
// 	arr = stack_to_arr(stack_a, size);
// 	sort_array(arr, size);
// 	int i = 0;
// 	while (i < size)
// 	{
// 		printf("%d\n", arr[i]);
// 		i++;
// 	}
// 	free_stack(stack_a);
// 	free(arr);
// 	return (0);
// }