/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:21:11 by danbarbo          #+#    #+#             */
/*   Updated: 2023/11/06 16:06:12 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

#define MAXFDS 4096

int	main()
{
	int		fd[MAXFDS];
	char	*line;
	int		i = 0;
	int		lines = 0;

	while (i < MAXFDS)
		fd[i++] = open("file2.txt", O_RDONLY);

	i = 0;
	// line = get_next_line(fd[0]);
	// line[0] = (char *) 1;

	while (lines < 18)
	{
		while (i < MAXFDS)
		{
			line = get_next_line(fd[i]);
			printf("%d = %s", fd[i], line);
			free(line);
			i++;
		}
		i = 0;
		lines++;
	}
	return (0);
}
