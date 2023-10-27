/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 23:30:44 by danbarbo          #+#    #+#             */
/*   Updated: 2023/10/27 00:13:02 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != (char) c && s[i] != '\0')
		i++;
	if (s[i] == '\0' && c != '\0')
		return (NULL);
	return ((char *) s + i);
}

char	*get_next_line(int fd)
{
	// size_t		i;
	char		*a;
	static char	*line;

	// i = 0;
	if (!line)
	{
		line = malloc(BUFFER_SIZE + 1);
		line[BUFFER_SIZE] = '\0';
	}
	read(fd, line, BUFFER_SIZE);
	a = ft_strchr(line, '\n');
	a[1] = '\0';
	return (line);
}
