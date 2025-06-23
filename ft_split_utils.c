/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romargar <romargar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 16:28:16 by romargar          #+#    #+#             */
/*   Updated: 2025/06/23 16:33:33 by romargar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

char	*ft_strncpy(char *dest, char *src, int n)
{
	int	i;

	i = 0;
	if (!dest || !src)
		return (NULL);
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	word_count(char *str)
{
	int	i;
	int	wc;

	i = 0;
	wc = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
			i++;
		if (str[i])
			wc++;
		while (str[i] && !(str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
			i++;
	}
	return (wc);
}

void	free_remaining(char **output, int k)
{
	while (k >= 0)
	{
		free(output[k]);
		k--;
	}
	free(output);
}

void	skip_whitespaces(char *str, int *i)
{
	while (str[*i] && (str[*i] == ' ' || str[*i] == '\t' || str[*i] == '\n'))
		(*i)++;
}
