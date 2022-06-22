#include "get_next_line.h"

size_t ft_strlen(const char *s)
{
    unsigned int i;

    i = 0;
    while (s && s[i])
        i++;
    return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	/*if (!s1 || !s2)
		return (NULL);*/
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1)); // + 1 pour le '/0'
	if (str == NULL)
		return (NULL);
	while (s1 && s1[i] != '\0')
	{
		str[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2 && s2[i] != '\0')
	{
		str[j] = s2[i];
		i++;
		j++;
	}
	str[j] = '\0';
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
	char	*dest;
	int		i;

	i = 0;
	if (!stash || stash[i] == '\0')
		return (NULL);
	while (stash[i] && stash[i] != '\n') //on avance jusqu'au \n
		i++;
	dest = malloc(sizeof(char) * i + 2); // i + 2 pour laisser la place pour le \n et pour le \0
	if (!dest)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n') //on copie jusqu'au \n
	{
		dest[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		dest[i++] = '\n';
	dest[i] = '\0';
	return (dest);
}

char	*after_next_line(char *stash)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	if (!stash)
		return (NULL);
	while (stash[i] && stash[i] != '\n') //on avance jusqu'au \n (avant \n)
		i++;
	if (stash[i] == '\0')
	{
		free (stash);
		return (NULL);
	}
	dest = malloc(sizeof(char) * ((ft_strlen(stash) - i) + 1));
	if (!dest)
		return (NULL);
	j = 0;
	i++;//on passe le \n
	while (stash[i] != '\0')
		dest[j++] =  stash[i++];
	dest[j] = '\0';
	free (stash);
	return (dest);		
}