#include "push_swap.h"

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
		if (str[i] != ' ' && !(str[i] >= 9 && str[i] <= 13))
			wc++;
		while (str[i] && str[i] != ' ' && !(str[i] >= 9 && str[i] <= 13))
			i++;
	}
	return (wc);
}

void	skip_spaces(char *str, int *i)
{
	while (str[*i] && (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13)))
		(*i)++;
}

void	loop_the_word(char *str, int *i)
{
	while (str[*i] && str[*i] != ' ' && !(str[*i] >= 9 && str[*i] <= 13))
		(*i)++;
}

char	**ft_split(char *str)
{
	int		i;
	char	**output;
	int		start;
	int		wc;
	int		j;

	if (!str)
		return (NULL);
	wc = word_count(str);
	output = (char **)malloc(sizeof(char *) * (wc + 1));
	if (!output)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		skip_spaces(str, &i);
		if(!process_word(output, str, &i, &j))
			return (NULL);
	}
	output[wc] = NULL;
	return (output);
}


int main()
{
	char str[] = "hello world aha che";
	char **output = ft_split(str);

	int i = 0;
	while (output[i])
	{
		printf("%s\n", output[i]);
		i++;
	}
	return 0;
}