/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romargar <romargar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 16:18:40 by romargar          #+#    #+#             */
/*   Updated: 2025/06/23 16:27:06 by romargar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	process_the_word(char *str, char **output, int *i, int *k)
{
	int	j;
	int	len;

	j = *i;
	while (str[*i] && (str[*i] != ' ' && str[*i] != '\t' && str[*i] != '\n'))
		(*i)++;
	len = *i - j;
	if (len > 0)
	{
		output[*k] = (char *)malloc(sizeof(char) * (len + 1));
		if (!output[*k])
		{
			free_remaining(output, *k);
			return (0);
		}
		ft_strncpy(output[*k], &str[j], len);
		(*k)++;
	}
	return (1);
}

char	**ft_split(char *str)
{
	int		i;
	int		k;
	int		wc;
	char	**output;

	i = 0;
	k = 0;
	wc = word_count(str);
	output = malloc(sizeof(char *) * (wc + 1));
	if (!str || !output)
		return (NULL);
	while (str[i])
	{
		skip_whitespaces(str, &i);
		if (!process_the_word(str, output, &i, &k))
			return (NULL);
	}
	output[k] = NULL;
	return (output);
}
