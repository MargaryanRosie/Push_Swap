#include "push_swap.h"

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

void	exit_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	check_overflow(long result, int sign)
{
	if ((sign == 1 && result > 2147483647) || (sign == -1 && -result < -2147483648))
		exit_error();
}

int	is_valid_input(char *s)
{
	if (!s || s[0] == '\0')
		return (0);
	return (1);
}


int	take_sign(char *s, int *i)
{
	int	sign;

	sign = 1;
	while (s[*i] == ' ' || (s[*i] >= 9 && s[*i] <= 13))
		(*i)++;
	if (s[*i] == '-' || s[*i] == '+')
	{
		if (s[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

int	ft_atoi(char *s)
{
	int		i;
	int		sign;
	long	result;                 //skzbum long vor heto inti overflowi pahov stugem
	
	if (!is_valid_input(s))
		exit_error();
	i = 0;
	sign = take_sign(s, &i);
	result = 0;

	while (s[i])
	{
		if (!is_digit(s[i]))
			exit_error();
		result = result * 10 + (s[i] - '0');
		check_overflow(result, sign);
		i++;
	}
	return ((int)(result * sign));
}