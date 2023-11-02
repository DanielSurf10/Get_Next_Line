/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_in_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:27:46 by danbarbo          #+#    #+#             */
/*   Updated: 2023/11/02 14:21:49 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
