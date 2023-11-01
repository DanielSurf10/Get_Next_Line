/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 23:30:44 by danbarbo          #+#    #+#             */
/*   Updated: 2023/11/01 19:26:19 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	index_for(t_list *line, char c)
{
	int	i;

	i = 0;
	while (line)
	{
		i++;
		if (line->content == c)
			return (i);
		line = line->next;
	}
	if (c == '\0')
		return (i);
	return (-1);
}

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

char	*build_line(t_list **line)
{
	int		i;
	int		line_size;
	t_list	*aux;
	char	*line_to_return;

	line_size = index_for(*line, '\n');
	if (line_size == -1)
		line_size = index_for(*line, '\0');
	line_to_return = (char *) malloc(line_size + 1);
	if (!line_to_return)
		return (NULL);
	line_to_return[line_size] = '\0';

	i = 0;
	while (i < line_size)
	{
		aux = *line;
		line_to_return[i] = (*line)->content;
		*line = (*line)->next;
		free(aux);
		i++;
	}

	return (line_to_return);
}

int	put_in_list(t_list **line, char *line_part)
{
	int	i;
	int	node;
	int	has_new_line_or_end;

	i = 0;
	has_new_line_or_end = 0;
	while (line_part[i] != '\0')
	{
		node = ft_lstadd_back(line, line_part[i]);
		if (node == -1)	// Tratar quando acontecer isso
			return (-1);
		if (line_part[i] == '\n')
			has_new_line_or_end = 1;
		i++;
	}
	if (node == -1)	// Tratar quando acontecer isso
		return (-1);
	if (line_part[i] == '\0')
		has_new_line_or_end = 1;
	return (has_new_line_or_end);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*mem;

	i = 0;
	if (!s)
		return (s);
	mem = (char *) s;
	while (i < n)
	{
		mem[i] = c;
		i++;
	}
	return (s);
}

char	*get_next_line(int fd)
{
	int				i;
	int				line_size;
	int				read_return;
	char			*line_part;
	char			*line_to_return;
	static t_list	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	i = 0;
	line_size = index_for(line, '\n');
	read_return = 1;
	line_to_return = NULL;
	line_part = NULL;
	if (line_size == -1)
		line_size = 0;
	while (line_size == 0 && read_return > 0)
	{
		line_part = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!line_part)
			return (NULL);
		ft_memset(line_part, '\0', BUFFER_SIZE + 1);
		read_return = read(fd, line_part, BUFFER_SIZE);
		if (read_return <= 0)
			break ;
		line_size = put_in_list(&line, line_part);
		if (line_size == -1)	// Tratar quando acontecer isso
			return (NULL);
		free(line_part);
		line_part = NULL;
		i++;
	}
	if (line_part)
		free(line_part);
	if (read_return > 0 && line_size != -1)
		line_to_return = build_line(&line);
	if (!line_to_return)	// Tratar quando acontecer isso
		return (NULL);
	return (line_to_return);
}
