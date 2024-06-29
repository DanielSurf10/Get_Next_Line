/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:25:18 by danbarbo          #+#    #+#             */
/*   Updated: 2024/06/27 19:10:20 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

char	*ft_strdup(char *str)
{
	int		i = 0;
	int		size = 0;
	char	*new_str;

	while (str && str[size])
		size++;

	if (!str || size == 0)
		return (NULL);

	new_str = malloc(size + 1);

	while (str[i])
	{
		new_str[i] = str[i];
		i++;
	}

	new_str[i] = '\0';

	return (new_str);
}

int	has_new_line(char *str)
{
	int	i = 0;

	while (str && str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}

	return (0);
}

char	*get_resto(char *line)
{
	int		i = 0;
	char	*new_str = NULL;

	if (!line)
		return (NULL);

	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;

	if (line[i])
		new_str = ft_strdup(line + i);

	return (new_str);
}

void	ft_strjoin_until_new_line(char **dest, char *src)
{
	int		i;
	int		i_src;
	int		size = 0;
	char	*old_str = *dest;
	char	*new_str;

	i = 0;
	while (old_str && old_str[i])
		i++;
	size += i;

	i = 0;
	while (src && src[i] && src[i] != '\n')
		i++;
	if (src[i] == '\n')
		i++;
	size += i;

	if (size == 0)
		return ;

	new_str = malloc(size + 1);

	i = 0;
	while (old_str && old_str[i])
	{
		new_str[i] = old_str[i];
		i++;
	}

	i_src = 0;
	while (src && i < size)
	{
		new_str[i] = src[i_src];
		i++;
		i_src++;
	}

	new_str[size] = '\0';

	if (*dest)
		free(*dest);
	*dest = new_str;

}

char	*get_next_line(int fd)
{
	int			caracteres_lidos;
	char		*line;
	char		*line_to_return = NULL;
	static char	*resto;

	if (fd < 0 || read(fd, NULL, 0) < 0 || BUFFER_SIZE < 1)
	{
		free(resto);
		resto = NULL;
		return (NULL);
	}
	else if (has_new_line(resto))
	{
		ft_strjoin_until_new_line(&line_to_return, resto);
		line = get_resto(resto);
		free(resto);
		resto = line;
	}
	else
	{
		line_to_return = ft_strdup(resto);
		free(resto);
		resto = NULL;

		line = malloc(BUFFER_SIZE + 1);

		while (1)
		{
			caracteres_lidos = read(fd, line, BUFFER_SIZE);
			line[caracteres_lidos] = '\0';

			if (caracteres_lidos > 0)
				ft_strjoin_until_new_line(&line_to_return, line);

			if (caracteres_lidos < BUFFER_SIZE || has_new_line(line))
				break;
		}

		if (caracteres_lidos >= 0)
			resto = get_resto(line);
		else if (line_to_return)
		{
			free(line_to_return);
			line_to_return = NULL;
		}

		free(line);
	}

	return (line_to_return);
}
