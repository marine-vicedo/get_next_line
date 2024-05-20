/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 12:20:51 by mvicedo           #+#    #+#             */
/*   Updated: 2022/06/27 15:48:04 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_search_newline(char *s)
{
	unsigned int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_getline(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	if (!stash || stash[0] == '\0')
		return (NULL);
	line = malloc(sizeof(char) * ft_strlen(stash) + 1);
	if (!line)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_save_stash(char *stash)
{
	char	*save;
	int		i;
	int		j;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\0')
		return (free (stash), NULL);
	if (stash[i])
		i++;
	save = malloc(sizeof(char) * ((ft_strlen(stash + i) + 1)));
	if (!save)
	{
		free (stash);
		return (NULL);
	}
	j = 0;
	while (stash[i] != '\0')
		save[j++] = stash[i++];
	save[j] = '\0';
	free (stash);
	return (save);
}

char	*get_next_line(int fd)
{
	static char		*stash[FOPEN_MAX];
	char			*line;
	char			*buffer;
	int				i_read;

	i_read = 1;
	buffer = NULL;
	if (fd > 1024 || fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (i_read > 0 && (ft_search_newline(stash[fd]) == 0))
	{
		i_read = read(fd, buffer, BUFFER_SIZE);
		if (i_read == -1)
			return (free (buffer), NULL);
		buffer[i_read] = '\0';
		stash[fd] = ft_strjoin(stash[fd], buffer);
	}
	free (buffer);
	line = ft_getline(stash[fd]);
	stash[fd] = ft_save_stash(stash[fd]);
	return (line);
}
