/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicedo <mvicedo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 12:20:47 by mvicedo           #+#    #+#             */
/*   Updated: 2022/06/24 15:54:43 by mvicedo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	unsigned int	i;

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
	str = (char *)malloc(sizeof(char) * (len + 1));
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
