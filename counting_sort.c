#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	counting_sort(int *arr, int size)                //[1, 2, 2, 3, 3, 4, 8]
{
	int	i;
	int	max;
	int	*count;
	int *output;

	max = arr[0];
	i = 1;
	while (i < size)
	{
		if (arr[i] > max)
			max = arr[i];
		i++;
	}

	count = (int*)malloc(sizeof(int) * (max + 1));
	if (!count)
        return;
	i = 0;
	while (i <= max)
	{
		count[i] = 0;
		i++;
	}
	
	i = 0;
	while (i < size)
	{
		count[arr[i]]++;
		i++;
	}
	//stex count[i]-n elementi qanakn e parunakum
	//culminative sum-ic heto parunakum e ed elementin havasar kam poqreri qanaky
	i = 1;
	while (i <= max)
	{
		count[i] = count[i] + count[i - 1];             //count[3] tells how many elements are <=3
		i++;
	}
	output = (int *)malloc(size * sizeof(int));
	if (!output) {
		printf("Memory allocation failed\n");
		free(count);
		return ;
	}
	i = size - 1;
	while (i >= 0)
	{
		output[count[arr[i]] - 1] = arr[i];
		count[arr[i]]--;
		i--;
	}
	i++;
	while (i < size)
	{
		arr[i] = output[i];
		i++;
	}
	free(output);
	free(count);
}

int main()
{
	int arr[] = {56, 3, 1, 23, 12, 0};
	counting_sort(arr, 6);
	int i = 0;
	while (i < 6)
	{
		printf("%d\n", arr[i]);
		i++;
	}
	return (0);
}