/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:49:02 by cshingai          #+#    #+#             */
/*   Updated: 2023/12/09 02:17:49 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	char		*line_to_return;
	char		*full_line;
	static char	*remainder;

	if (!remainder)
		remainder = ft_strdup("");
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(remainder);
		remainder = NULL;
		return (NULL);
	}
	full_line = ft_read_line(remainder, fd);
	line_to_return = ft_build_line(full_line);
	remainder = get_after_first_newline(full_line);
	free(full_line);
	if (*line_to_return == '\0' && *remainder == '\0')
	{
		free(line_to_return);
		free(remainder);
		remainder = NULL;
		return (NULL);
	}
	return (line_to_return);
}

char	*ft_read_line(char *line, int fd)
{
	char	*temp_buffer;
	int		chars_readed;

	chars_readed = 1;
	temp_buffer = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	while (chars_readed != 0 && ft_strchr(line, '\n') == NULL)
	{
		chars_readed = read(fd, temp_buffer, BUFFER_SIZE);
		temp_buffer[chars_readed] = '\0';
		line = ft_strjoin(line, temp_buffer);
	}
	free(temp_buffer);
	return (line);
}

char	*ft_build_line(char *line)
{
	int		i;
	int		size_new_line;
	char	*new_line;

	i = 0;
	size_new_line = 0;
	while (line[size_new_line] != '\0' && line[size_new_line] != '\n')
		size_new_line++;
	if (line[size_new_line] == '\n')
		size_new_line += 1;
	new_line = (char *) malloc((size_new_line + 1) * sizeof(char));
	while (i < size_new_line)
	{
		new_line[i] = line[i];
		i++;
	}
	new_line[i] = '\0';
	return (new_line);
}

char	*get_after_first_newline(char *line)
{
	int		i;
	char	*remainder_after_new_line;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i += 1;
	remainder_after_new_line = ft_strdup(line + i);
	return (remainder_after_new_line);
}
