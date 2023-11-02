/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 23:31:21 by danbarbo          #+#    #+#             */
/*   Updated: 2023/11/02 18:49:27 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 16
# endif

typedef enum e_status
{
	FAIL = -1,
	READ,
	BUILD_STRING,
	FINISH
}	t_status;

typedef struct s_list
{
	char			content;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
int		ft_lstadd_back(t_list **lst, char c);
int		ft_lst_next_line_size(t_list *lst);
void	*ft_memset(void *s, int c, size_t n);
void	ft_lstclear(t_list **lst);
char	*read_fd(int fd, t_list **line);
int		need_to_read(t_list *line);
char	*build_line(t_list **line);
int		put_in_list(t_list **line, char *line_part);

#endif
