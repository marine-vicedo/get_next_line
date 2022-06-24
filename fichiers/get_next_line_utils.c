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
	int		len;

	i = 0;
	len = ft_strlen(stash) + ft_strlen(buffer);
	str = (char *)malloc(sizeof(char) * (len + 1)); // + 1 pour le '/0'
	if (str == NULL)
		return (NULL);
	while (stash && stash[i] != '\0')//au premier passage stash = NULL donc on saute cette loop
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
