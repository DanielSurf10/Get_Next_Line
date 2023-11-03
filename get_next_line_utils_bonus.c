/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:34:01 by danbarbo          #+#    #+#             */
/*   Updated: 2023/11/03 19:56:26 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	if (!line_part)
		return (FAIL);
	if (line_part[0] == '\0')
		return (BUILD_STRING);
	while (line_part[i] != '\0')
	{
		status_node_creation = ft_lstadd_back(line, line_part[i]);
		if (status_node_creation == FAIL)
			return (FAIL);
		if (line_part[i] == '\n')
			has_new_line = 1;
		i++;
	}
	if (has_new_line)
		return (BUILD_STRING);
	return (READ);
}

void	remove_fd(int fd, t_fd **fd_list)
{
	t_fd	*aux;
	t_fd	*prev;

	aux = *fd_list;
	prev = NULL;
	while (aux)
	{
		if (aux->fd == fd || fd == -1)
		{
			if (prev)
				prev->next = aux->next;
			else
				*fd_list = aux->next;
			ft_lstclear(&aux->content);
			free(aux);
			return ;
		}
		prev = aux;
		aux = aux->next;
	}
}
