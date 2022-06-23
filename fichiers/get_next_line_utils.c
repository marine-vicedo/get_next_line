#include "get_next_line.h"

size_t ft_strlen(const char *s)
{
    unsigned int i;

    i = 0;
    while (s && s[i])
        i++;
    return (i);
}

char	*ft_strjoin(char *stash, char *buffer)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(stash) + ft_strlen(buffer) + 1)); // + 1 pour le '/0'
	if (str == NULL)
		return (NULL);
	while (stash && stash[i] != '\0')
	{
		str[i] = stash[i];
		i++;
	}
	j = 0;
	while (buffer && buffer[j] != '\0')
		str[i++] = buffer[j++];
	str[i] = '\0';
	free (stash);
	return (str);
}

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

char	*before_next_line(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	if (!stash)
		return (NULL);
	line = malloc(sizeof(char) * ft_strlen(stash) + 1); 
	if (!line)
		return (NULL);
	while (stash[i]) //on copie jusqu'au \n
	{
		line[i] = stash[i];
		i++;
		if (stash[i - 1] == '\n')
			break ;
	}
	//if (stash[i] == '\n') //si on est arrive au /n, on met le \n
		//line[i++] = '\n';
	line[i] = '\0';//on null termine la line
	if (line[0] == '\0')
	{
		free (line);
		return (NULL);
	}
	return (line);
	//free (line);
}

char	*after_next_line(char *stash)
{
	char	*line;
	int		i;
	int		j;

 	i = 0;
	/*if (!stash == NULL)
		free (stash);
	else
			return (NULL);
	}*/
	while (stash[i] && stash[i] != '\n') //on avance jusqu'au \n (avant \n)
		i++;
	if (stash[i])
		i++;
	line = malloc(sizeof(char) * ((ft_strlen(stash + i) + 1)));
	if (!line)
	{
			free (stash);
			return (NULL);
	}
	j = 0;
	/* i++; *///on passe le \n
	while (stash[i] != '\0')
		line[j++] = stash[i++];
	line[j] = '\0';
	free (stash);
	return (line);
}