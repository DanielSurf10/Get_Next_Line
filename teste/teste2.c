/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:21:11 by danbarbo          #+#    #+#             */
/*   Updated: 2023/10/31 19:37:38 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main()
{
	int	fd;
	char	*line;

	fd = open("files/41_no_nl", O_RDONLY);

	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}

	return (0);
}
