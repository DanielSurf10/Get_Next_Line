/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:34:01 by danbarbo          #+#    #+#             */
/*   Updated: 2023/11/15 16:45:10 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

// int	need_to_read(t_list *line)
// {
// 	int	i;
//
// 	i = 0;
// 	while (line)
// 	{
// 		i++;
// 		if (line->content == '\n')
// 			return (BUILD_STRING);
// 		line = line->next;
// 	}
// 	return (READ);
// }

char	*build_line(t_list **line)
{
	int		i;
	int		line_size;
	char	*line_to_return;
	t_list	*aux;

	i = 0;
	if (*line == NULL)
		return (NULL);
	line_size = ft_lst_next_line_size(*line);
	line_to_return = (char *) malloc(line_size + 1);
	if (!line_to_return)
		return (NULL);
	line_to_return[line_size] = '\0';
	while (i < line_size)
	{
		aux = *line;
		line_to_return[i] = (*line)->content;
		*line = (*line)->next;
		free(aux);
		i++;
	}
	aux = NULL;
	return (line_to_return);
}

int	put_in_list(t_list **line, char *line_part, int size_readed)
{
	int	i;
	int	status_node_creation;
	int	return_status;

	i = 0;
	return_status = READ;
	if (!line_part)
		return (FAIL);
	if (size_readed == 0)
		return (BUILD_STRING);
	while (i < size_readed)
	{
		status_node_creation = ft_lstadd_back(line, line_part[i]);
		if (status_node_creation == FAIL)
			return (FAIL);
		if (line_part[i] == '\n')
			return_status = BUILD_STRING;
		i++;
	}
	return (return_status);
}
