/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 23:30:44 by danbarbo          #+#    #+#             */
/*   Updated: 2023/11/02 17:24:31 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

int	ft_lst_next_line_size(t_list *lst)
{
	int		i;
	t_list	*aux;

	i = 0;
	aux = lst;
	while (aux)
	{
		i++;
		if (aux->content == '\n')
			return (i);
		aux = aux->next;
	}
	return (i);
}

int	ft_lstadd_back(t_list **lst, char c)
{
	t_list	*new;
	t_list	*aux;

	new = malloc(sizeof(t_list));
	if (!new)
		return (FAIL);
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

int	need_to_read(t_list *line)
{
	int	i;

	i = 0;
	while (line)
	{
		i++;
		if (line->content == '\n')
			return (BUILD_STRING);
		line = line->next;
	}
	return (READ);
}

char	*build_line(t_list **line)
{
	int		i;
	int		line_size;
	char	*line_to_return;
	t_list	*aux;

	if (*line == NULL)
		return (NULL);
	line_size = ft_lst_next_line_size(*line);
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
	int	status_node_creation;
	int	has_new_line;

	i = 0;
	has_new_line = 0;
	// if (!line_part)		// Não sei se é necessário
	// 	return (FAIL);
	if (line_part[0] == '\0')
		return (BUILD_STRING);
	while (line_part[i] != '\0')
	{
		status_node_creation = ft_lstadd_back(line, line_part[i]);
		if (status_node_creation == FAIL)	// Tratar quando acontecer isso
			return (FAIL);
		if (line_part[i] == '\n')
			has_new_line = 1;
		i++;
	}
	if (has_new_line)
		return (BUILD_STRING);
	return (READ);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*aux1;
	t_list	*aux2;

	if (lst)
	{
		aux1 = *lst;
		while (aux1)
		{
			aux2 = aux1->next;
			free(aux1);
			aux1 = aux2;
		}
		*lst = NULL;
	}
}

char	*get_next_line(int fd)
{
	int				read_status;
	char			*line_part;
	char			*line_to_return;
	static t_list	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_status = need_to_read(line);
	line_to_return = NULL;
	line_part = NULL;			// Talvez eu tire isso
	while (read_status == READ)
	{
		line_part = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!line_part)
			return (NULL);
		ft_memset(line_part, '\0', BUFFER_SIZE + 1);
		read_status = read(fd, line_part, BUFFER_SIZE);
		if (read_status != FAIL)
			read_status = put_in_list(&line, line_part);
		free(line_part);
		line_part = NULL;
	}
	if (read_status != FAIL && read_status == BUILD_STRING)
		line_to_return = build_line(&line);
	if (!line_to_return || read_status == FAIL)	// Tratar quando acontecer isso
	{
		ft_lstclear(&line);
		return (NULL);
	}
	return (line_to_return);
}
