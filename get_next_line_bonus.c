/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 23:30:44 by danbarbo          #+#    #+#             */
/*   Updated: 2023/11/02 20:01:06 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*read_fd(int fd, t_list **line)
{
	int		read_status;
	char	*line_part;
	char	*line_to_return;

	read_status = READ;
	line_part = NULL;
	line_to_return = NULL;
	while (read_status == READ)
	{
		line_part = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!line_part)
			return (NULL);
		ft_memset(line_part, '\0', BUFFER_SIZE + 1);
		read_status = read(fd, line_part, BUFFER_SIZE);
		if (read_status != FAIL)
			read_status = put_in_list(line, line_part);
		free(line_part);
		line_part = NULL;
	}
	if (read_status == FAIL)
		return (NULL);
	if (read_status == BUILD_STRING)
		line_to_return = build_line(line);
	return (line_to_return);
}

t_fd	*get_fd(int fd, t_fd **fd_list)
{
	t_fd	*aux;
	t_fd	*new_fd;

	aux = *fd_list;
	if (aux)
	{
		while (aux->next)
		{
			if (aux->fd == fd)
				return (aux);
			aux = aux->next;
		}
	}
	new_fd = (t_fd *) malloc(sizeof(t_fd));
	if (!new_fd)
		return (NULL);
	new_fd->fd = fd;
	new_fd->line = NULL;
	if (!(*fd_list))
		*fd_list = new_fd;
	else
		aux->next = new_fd;
	return (new_fd);
}

void	remove_fd(int fd, t_fd **fd_list)
{
	t_fd	*aux;
	t_fd	*prev;

	aux = *fd_list;
	prev = NULL;
	while (aux)
	{
		if (aux->fd == fd)
		{
			if (prev)
				prev->next = aux->next;
			else
				*fd_list = aux->next;
			free(aux);
			return ;
		}
		prev = aux;
		aux = aux->next;
	}
}

char	*get_next_line(int fd)
{
	char			*line_to_return;
	t_fd			*node_fd;
	// static t_list	*line;
	static t_fd		*fd_list;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	node_fd = get_fd(fd, &fd_list);
	if (!node_fd)				// Aqui tem que limpar tudo
		return (NULL);
	line_to_return = read_fd(fd, &node_fd->line);
	if (!line_to_return)
	{
		ft_lstclear(&node_fd->line);
		return (NULL);
	}
	if (!(node_fd->line))
		remove_fd(fd, &fd_list);
	return (line_to_return);
}
