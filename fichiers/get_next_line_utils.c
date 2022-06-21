#include "get_next_line.h"

size_t ft_strlen(const char *s)
{
    unsigned int i;

    i = 0;
    while (s[i])
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
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1)); // + 1 pour le '/0'
	if (str == 0)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		str[j] = s2[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}

char    *ft_strchr(const char *s, int c)
{
    unsigned int    i;
	
    i = 0;
    while (s[i]) // different de null-byte
    {
        if(s[i] == (char)c)
            return ((char *)&s[i]);
        i++;
    }
   if(s[i] == (char)c) // if s[i] == '\0' car on doit retourner le null sinon segfault
        return ((char *)&s[i]);
    return (NULL); // pas return 0
}

char	*before_next_line(char *str)
{
	char	*dest;
	int		i;

	i = 0;
	while (*str && str[i] != '\n')
		i++;
	dest = malloc(sizeof(char *) * (i + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (str[i] != '\n')
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*after_next_line(char *tmp)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	while (*tmp && tmp[i] != '\n')
		i++;
	dest = malloc(sizeof(char *) * (ft_strlen(tmp) - i + 1));
	if (!dest)
		return (NULL);
	j = 0;
	while (tmp[i] != '\0')
	{
		dest[j] =  tmp[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest);	
	
}