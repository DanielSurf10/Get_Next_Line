/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:21:11 by danbarbo          #+#    #+#             */
/*   Updated: 2023/11/02 16:15:24 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main()
{
	int	fd;
	char	*line;

	fd = open("file3.txt", O_RDONLY);

	// while ((line = get_next_line(fd)))
	// {
	// 	printf("%s\n", line);
	// 	free(line);
	// }

	line = get_next_line(fd);
	printf("%s\n", line);
	free(line);
	
	line = get_next_line(fd);
	printf("%s\n", line);
	free(line);

	return (0);
}
