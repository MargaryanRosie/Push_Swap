#include "push_swap.h"

int	is_valid_number(char *str)
{
	int	i;
	int j;

	i = 0;
	while (str[i])
	{
		if (is_sign(str[i]))
		{
			if (str[i + 1] != '\0' && is_digit(str[i]))
			{
				j = 0;
				while (str[i] != ' ')
				{
					if (!is_digit(str[i]))
						return (0);
					j++;
				}
			}
		}
		i++;
	}
}

int main(int argc, char *argv[])
{
	is_valid_number
	return 0;
}
