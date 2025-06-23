/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romargar <romargar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 13:32:15 by romargar          #+#    #+#             */
/*   Updated: 2025/06/23 15:21:20 by romargar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5

# endif

# include <fcntl.h>
# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
int		find_newline(char *str);
char	*ft_strjoin(char *str1, char *str2);
char	*ft_strchr(const char *str, int c);
size_t	ft_strlen(const char *str);
char	*extract_line(char *str);
char	*get_remaining(char *str);
char	*ft_strdup(const char *s);

#endif