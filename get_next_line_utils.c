/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:03:53 by cshingai          #+#    #+#             */
/*   Updated: 2023/12/09 02:06:28 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *str, int c)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if (str[index] == (unsigned char) c)
			return ((char *) &str[index]);
		index++;
	}
	if ((unsigned char) c == str[index])
		return ((char *) &str[index]);
	return (NULL);
}

char	*ft_strdup(char *str)
{
	int		index;
	int		size_str;
	char	*temp;

	index = 0;
	size_str = ft_strlen(str);
	temp = malloc((size_str + 1) * sizeof(char));
	while (str[index] != '\0')
	{
		temp[index] = str[index];
		index++;
	}
	temp[index] = '\0';
	return (temp);
}

int	ft_strlen(const char *str)
{
	int	index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		idx1;
	int		idx2;
	int		size_new_line;
	char	*new_line;

	idx1 = -1;
	idx2 = -1;
	size_new_line = ft_strlen(s1) + ft_strlen(s2);
	new_line = malloc((size_new_line + 1) * sizeof(char));
	while (s1[++idx1] != '\0')
		new_line[idx1] = s1[idx1];
	while (s2[++idx2] != '\0')
		new_line[idx1 + idx2] = s2[idx2];
	new_line[idx1 + idx2] = '\0';
	free((void *) s1);
	return (new_line);
}
