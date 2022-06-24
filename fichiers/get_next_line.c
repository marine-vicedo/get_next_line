/* size_t read (int fd, void *buf, size_t nbyte)
lit nbytes du file descriptor et stocke dans le buffer. elle debute avant le premier element du fichier.
elle renvoie le nombre de bytes qu'elle a reussi a lire, si elle arrive a la fin du file elle renvoie 0.
si erreur elle renvoie -1.
*/

#include "get_next_line.h"
#include "stdio.h"

int    ft_search_newline(char *s)
{
    unsigned int    i;
	
    i = 0;
	if (!s)
		return (0);
    while (s[i]) // different de null-byte
    {
        if(s[i] == '\n')
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
	while (stash[i] && stash[i] != '\n') //on copie jusqu'au \n
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[i++] = '\n';
	printf("getline = %s", line);
	line[i] = '\0';//on null termine la line
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
	printf("y a quoi dans la save : %s", save);
	save[j] = '\0';
	free (stash);
	return (save);
}


char	*get_next_line(int fd)
{
	static 	char	*stash; //copie du buffer dans stash static (notre reserve)
	char			*line; // ce qu'on retourne
	char			*buffer;
	int				i_read;

	i_read = 1;//on initialise a 1 pour pouvoir entrer dans le boucle
	buffer = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1) /* si fd < 0 pas de file, si erreur de valeur pour BUFFER_SIZE, si erreur de lecture de read( != 0) */
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));// on alloue la taille du buffer +1 car \0
	if (!buffer)
		return (NULL);
	while (i_read > 0 && (ft_search_newline(stash) == 0)) // tant qu' i_read n'est pas arrive au bout du fd, il stocke nbyte dans buffer && si on trouve \n on break et on cree la line
	{
		i_read = read(fd, buffer, BUFFER_SIZE);// i_read = return de read a chaque passage
		printf("buffer : %s  |   ", buffer);
		if (i_read == -1)
			return (NULL);
		buffer[i_read] = '\0'; //buffer[return de read] equivaut a buffer[nbytes]. On termine par '\0' la chaine buffer
		printf("stash : %s   |  ", stash);
		stash = ft_strjoin(stash, buffer);// on copie le contenu de buff dans stash a la suite (strjoin)
		printf("apres strjoin, stash vaut  : %s    |   ", stash);
	}
	free (buffer);//on free le buffer car plus besoin
	line = ft_getline(stash); // on sort la line
	//printf("y a quoi dans la line : %s", line);
	//printf("y a quoi dans la stash : %s", stash);
	stash = ft_save_stash(stash); // on cleane pour ne garder que ce qui a ete lu apres le \n
	return (line);
}

int	main(void)
{
	int fd = open("file", O_RDONLY);

	printf("Premier passage\n");
	printf(" | final : %s", get_next_line(fd));
	printf("Nouveau passage\n");
	printf(" | final : %s", get_next_line(fd));
	printf("Nouveau passage\n");
	printf(" | final : %s", get_next_line(fd));
	printf("Nouveau passage\n");
	printf(" | final : %s", get_next_line(fd));

	return (0);
}