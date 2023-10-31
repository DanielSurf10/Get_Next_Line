/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:27:30 by danbarbo          #+#    #+#             */
/*   Updated: 2023/10/31 14:58:57 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

int main() {
	int fd;
	int	lido;
	char line[BUFFER_SIZE + 1];
	line[BUFFER_SIZE] = '\0';

	fd = open("file1.txt", O_RDONLY);

	lido = read(fd, line, BUFFER_SIZE);
	printf("Line read: %d %s\n", lido, line);

	close(fd);
	return 0;
}
