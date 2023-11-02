/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:21:11 by danbarbo          #+#    #+#             */
/*   Updated: 2023/11/02 20:09:46 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main()
{
	int		fd1;
	int		fd2;
	char	*line1;
	char	*line2;

	fd1 = open("file3.txt", O_RDONLY);
	fd2 = open("file3.txt", O_RDONLY);

	line1 = get_next_line(fd1);
	line2 = get_next_line(fd2);
	printf("line2 = %s\n", line2);
	free(line2);
	line2 = get_next_line(fd2);

	while (line1 || line2)
	{
		printf("line1 = %s\n", line1);
		printf("line2 = %s\n", line2);
		free(line1);
		free(line2);
		line1 = get_next_line(fd1);
		line2 = get_next_line(fd2);
	}
	return (0);
}
