/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:25:18 by danbarbo          #+#    #+#             */
/*   Updated: 2024/07/19 11:04:37 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *str, int chr)
{
	int	i = 0;

	while (str && str[i])
	{
		if (str[i] == chr)
			return (str + i);
		i++;
	}
	return (NULL);
}

int	ft_strlen(char *str)
{
	int	i = 0;

	while (str && str[i])
		i++;

	return (i);
}

void	ft_strcpy(char *dest, char *src)
{
	int	i = 0;

	if (!src || !dest)
		return ;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}

	dest[i] = '\0';
}

char	*ft_strdup(char *str)
{
	char	*new_str = malloc(ft_strlen(str) + 1);

	ft_strcpy(new_str, str);

	return (new_str);
}

char	*ft_strjoin(char *str1, char *str2)
{
	int		str1_len = ft_strlen(str1);
	int		str2_len = ft_strlen(str2);
	char	*new_str = malloc(str1_len + str2_len + 1);

	ft_strcpy(new_str, str1);
	ft_strcpy(new_str + str1_len, str2);

	free(str1);
	return (new_str);
}

char	*get_next_line(int fd)
{
	if (BUFFER_SIZE < 1)
		return (NULL);

	int			chars_readed;
	int			to_copy;
	static char	buf[BUFFER_SIZE + 1];
	char		*newline;
	char		*line;

	if (fd < 0)
	{
		buf[0] = '\0';
		return (NULL);
	}

	line = ft_strdup(buf);
	while (!(newline = ft_strchr(line, '\n')) && (chars_readed = read(fd, buf, BUFFER_SIZE)))
	{
		buf[chars_readed] = '\0';
		line = ft_strjoin(line, buf);
	}
	if (ft_strlen(line) == 0)
	{
		free(line);
		return (NULL);
	}

	if (newline)
	{
		to_copy = newline - line + 1;
		ft_strcpy(buf, newline + 1);
	}
	else
	{
		buf[0] = '\0';
		to_copy = ft_strlen(line);
	}
	line[to_copy] = '\0';

	return (line);
}
