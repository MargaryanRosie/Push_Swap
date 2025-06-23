/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romargar <romargar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 13:36:03 by romargar          #+#    #+#             */
/*   Updated: 2025/06/23 14:35:48 by romargar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	is_valid_number(char *str)
{
	int	i;

	if (!str || !str[0])
		return (0);
	i = 0;
	if (!str || str[0] == '\0')
		return (0);
	if (str[i] == '+' || str[i] == '-')
	{
		if (!str[i + 1])
			return (0);
		i++;
	}
	while (str[i])
	{
		if (!is_digit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_overflow(long long result, int sign)
{
	if ((sign == 1 && result > 2147483647)
		|| (sign == -1 && - result < -2147483648))
		return (1);
	return (0);
}

int	ft_atoi(char *str, int *overflow)
{
	int			i;
	int			sign;
	long long	result;

	i = 0;
	sign = 1;
	result = 0;
	*overflow = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		result = result * 10 + (str[i] - '0');
		if (check_overflow(result, sign))
		{
			*overflow = check_overflow(result, sign);
			break ;
		}
		i++;
	}
	return ((int)(result * sign));
}
