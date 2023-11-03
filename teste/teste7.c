/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:21:11 by danbarbo          #+#    #+#             */
/*   Updated: 2023/11/03 20:30:41 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main()
{
	int		fd[2048];
	char	*line[2048];
	int		i = 0;
	int		lines = 0;

	while (i < 2048)
		fd[i++] = open("file2.txt", O_RDONLY);

	// line[0] = get_next_line(fd[0]);
	line[0] = (char *) 1;

	while (lines < 10)
	{
		i = 0;
		while (i < 2048)
		{
			line[i] = get_next_line(fd[i]);
			printf("%d = %s", fd[i], line[i]);
			free(line[i]);
			i++;
		}
		lines++;
	}
	return (0);
}
