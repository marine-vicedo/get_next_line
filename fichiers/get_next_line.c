//#include "get_next_line.h"

/* size_t read (int fd, void *buf, size_t nbyte)
lit nbytes du file descriptor et stocke dans le buffer. elle debute avant le premier element du fichier.
elle renvoie le nombre de bytes qu'elle a reussi a lire, si elle arrive a la fin du file elle renvoie 0.
si erreur elle renvoie -1.
*/

#include "get_next_line.h"

char	*read_content(int fd, char *buffer, char *tmp, char *stash)
{
	int	index_read; //le contenu lu par read. stocke dans buffer
	
	index_read = 1;
	while (index_read > 0) // tant qu' index_read n'est pas arrive au bout du fd, il stocke nbyte dans buffer 
	{
		index_read = read(fd, buffer, BUFFER_SIZE);
		if (index_read == -1)
		{
			free (buffer);
			return (NULL);
		}
		buffer[index_read] = '\0'; //buffer[return de read] = buffer[nbytes]. On termine par '\0'
		tmp =  stash;
		if (tmp == NULL)
		{
			tmp = (char *)malloc(sizeof(char) * 1);//on laisse la place pour le '\0';
			tmp[0] = '\0';
		}
		stash = ft_strjoin(tmp, buffer);// on copie le contenu de buff dans str a la suite (strjoin)
		free (tmp);
		if (ft_search_newline(stash) == 1) // si on trouve \n on break et on cree la line
			break;
	}
	free (buffer);
	return (stash);
}	

char	*get_next_line(int fd)
{
	static 	char	*stash; //copie du buffer dans stash (notre reserve)
	char			*line; // ce qu'on retourne
	char			*tmp;
	char			*buffer;
	
	tmp = NULL;
	if (fd > 1023 || fd < 0 || BUFFER_SIZE <= 0) /* si fd < 0 pas de file descriptor, si erreur de valeur pour BUFFER_SIZE */
		return (NULL);
	buffer = malloc(sizeof(char)*(BUFFER_SIZE + 1));// +1 car \0
	if (!buffer)
		return (NULL);
	/*on copie le contenu du buffer dans str */
	stash = read_content(fd, buffer, tmp, stash);
	if (!stash)
		return (NULL);
	line = before_next_line(stash); // on sort la line
	//tmp = stash;
	stash = after_next_line(stash); // on cleane pour ne garder que ce qui a ete lu apres le \n	
	//str = coucou (\n ca va ?\0)
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