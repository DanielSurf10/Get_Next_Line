/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:21:11 by danbarbo          #+#    #+#             */
/*   Updated: 2023/11/02 15:07:15 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main()
{
	int	fd;
	char	*line;

	fd = open("file2.txt", O_RDONLY);

	line = get_next_line(fd);
	printf("%s\n", line);
	free(line);
	close(fd);
	fd = open("file2.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s\n", line);
	free(line);

	return (0);
}
