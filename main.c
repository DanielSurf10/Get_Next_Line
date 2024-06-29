/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:27:33 by danbarbo          #+#    #+#             */
/*   Updated: 2024/06/27 18:47:45 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

char	*get_next_line(int fd);

int main()
{
	int		fd = open("a", O_RDONLY);
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (line)
			printf("%s", line);
		else
			printf("(null)\n");
		if (!line)
			break;
		free(line);
	}

// 	line = get_next_line(fd);
// 	if (line)
// 		printf("%s", line);
// 	else
// 		printf("(null)\n");
//
// 	close(fd);
// 	line = get_next_line(fd);
// 	if (line)
// 		printf("%s", line);
// 	else
// 		printf("(null)\n");

	return (0);
}
