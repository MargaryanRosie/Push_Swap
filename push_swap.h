#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>


typedef struct s_stack
{
	int				number;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;


int		word_count(char *str);
void	free_remaining(char **output, int j);
char 	*ft_strncpy(char *dest, char *src, int n);
int		allocate_word(char **output, char *str, int start, int i, int j);
int		process_word(char **output, char *str, int *i, int *j);
void	skip_spaces(char *str, int *i);
void	loop_the_word(char *str, int *i);
char	**ft_split(char *str);

#endif