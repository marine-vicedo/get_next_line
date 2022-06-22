#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char	*get_next_line(int fd);
size_t 	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
int    ft_search_newline(char *s);
char	*before_next_line(char *stash);
char	*after_next_line(char *tmp);

#endif