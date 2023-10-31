/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 23:30:44 by danbarbo          #+#    #+#             */
/*   Updated: 2023/10/31 15:34:49 by danbarbo         ###   ########.fr       */
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

void	*ft_lstadd_back(t_list **lst, char c)
{
	t_list	*new;
	t_list	*aux;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = c;
	new->next = NULL;
	if (!(*lst))
		*lst = new;
	else
	{
		aux = *lst;
		while (aux->next)
			aux = aux->next;
		aux->next = new;
	}
	return (new);
}

char	*get_next_line(int fd)
{
	size_t			i;
	char			*line_part;
	static t_list	*line;

	line_part = (char *) malloc(BUFFER_SIZE + 1);
	line_part[BUFFER_SIZE] = '\0';

	line = ft_lstadd_back(&line, line_part[0]);
	while (i < BUFFER_SIZE)
	{
		line = ft_lstadd_back(&line, line_part[i]);
		i++;
	}



	// read(fd, line, BUFFER_SIZE);
	// line_part = ft_strchr(line, '\n');
	// line_part[1] = '\0';
	// return (line);
}
