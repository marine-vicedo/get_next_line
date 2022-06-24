/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 12:27:42 by mvicedo           #+#    #+#             */
/*   Updated: 2022/06/23 12:40:13 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_content(int fd, char *buffer, char *tmp, char *stash)
{
	int	index_read;

	index_read = 1;
	while (index_read > 0)
	{
		index_read = read(fd, buffer, BUFFER_SIZE);
		if (index_read == -1)
		{
			free (buffer);
			return (NULL);
		}
		buffer[index_read] = '\0';
		tmp = stash;
		if (tmp == NULL)
		{
			tmp = (char *)malloc(sizeof(char) * 1);
			tmp[0] = '\0';
		}
		stash = ft_strjoin(tmp, buffer);
		free (tmp);
		if (ft_search_newline(stash) == 1)
			break ;
	}
	free (buffer);
	return (stash);
}	

char	*get_next_line(int fd)
{
	static char		*stash;
	char			*line;
	char			*tmp;
	char			*buffer;

	tmp = NULL;
	if (fd > 1023 || fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	stash = read_content(fd, buffer, tmp, stash);
	if (!stash)
		return (NULL);
	line = before_next_line(stash);
	stash = after_next_line(stash);
	return (line);
}

/*int	main(void)
{
	int fd = open("file", O_RDONLY);

	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));

	return (0);
}*/