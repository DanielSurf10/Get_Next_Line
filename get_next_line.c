/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 23:30:44 by danbarbo          #+#    #+#             */
/*   Updated: 2023/10/31 14:24:16 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_lstadd_back(t_list **lst, char c)
{
	t_list	*new;
	t_list	*aux;

	new = malloc(sizeof(t_list));
	if (!new)
		return (-1);
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
	return (0);
}

char	*build_line(t_list **line, size_t line_size)
{
	size_t	i;
	t_list	*aux;
	char	*line_to_return;

	line_to_return = (char *) malloc(line_size + 1);
	if (!line_to_return)
		return (NULL);
	line_to_return[line_size] = '\0';

	i = 0;
	while (i < line_size)
	{
		line_to_return[i] = (*line)->content;
		aux = *line;
		*line = (*line)->next;
		free(aux);
		i++;
	}

	return (line_to_return);
}

int	put_in_list(t_list **line, char *line_part)
{
	size_t	i;
	size_t	line_size;
	int		node;

	i = 0;
	line_size = 0;
	node = 0;
	while (i < BUFFER_SIZE && !node)
	{
		node = ft_lstadd_back(line, line_part[i]);
		if (line_part[i] == '\n')
			line_size = i + 1;
		i++;
	}
	if (node == -1)	// Tratar quando acontecer isso
		return (-1);
	return (line_size);
}

char	*get_next_line(int fd)
{
	size_t			i;
	size_t			line_size;
	char			*line_part;
	char			*line_to_return;
	static t_list	*line;

	i = 0;
	line_size = 0;
	line_part = (char *) malloc(BUFFER_SIZE + 1);
	line_part[BUFFER_SIZE] = '\0';
	read(fd, line_part, BUFFER_SIZE);

	line_size = put_in_list(&line, line_part);
	line_to_return = build_line(&line, line_size);
	if (!line_to_return)	// Tratar quando acontecer isso
		return (NULL);

	return (line_to_return);
}
