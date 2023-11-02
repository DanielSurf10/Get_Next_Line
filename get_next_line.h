/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 23:31:21 by danbarbo          #+#    #+#             */
/*   Updated: 2023/11/02 17:07:18 by danbarbo         ###   ########.fr       */
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

// Macros for build_line and need_to_read functions

# ifndef FAIL
#  define FAIL -1			// Se deu ruim, com algum malloc
# endif							// ou o fd é inválido
									// Aí limpa tudo daquele fd e retorna NULL
# ifndef READ
#  define READ 0			// Se precisa ler mais
# endif

# ifndef BUILD_STRING
#  define BUILD_STRING 1	// Se não precisa ler mais e é para construir a string
# endif

# ifndef FINISH
#  define FINISH 2			// Se não precisa ler mais e não é para construir a string
# endif

typedef struct s_list
{
	char			content;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
int		ft_lstadd_back(t_list **lst, char c);
int		ft_lst_next_line_size(t_list *lst);

#endif
