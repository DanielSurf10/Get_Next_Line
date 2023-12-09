/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshingai <cshingai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:22:45 by cshingai          #+#    #+#             */
/*   Updated: 2023/12/09 02:19:22 by cshingai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 16
# endif

# include <stdlib.h>
# include <unistd.h>

int		ft_strlen(const char *str);
char	*ft_strdup(char *c);
char	*ft_strchr(char *str, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_read_line(char *remainder, int fd);
char	*ft_build_line(char *line);
char	*get_after_first_newline(char *remainder);
char	*get_next_line(int fd);

#endif
