/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_build_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:21:08 by danbarbo          #+#    #+#             */
/*   Updated: 2023/11/02 14:33:45 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

char	*build_line(t_list **line);

int	ft_lstsize(t_list *lst)
{
	size_t	i;
	t_list	*aux;

	i = 0;
	aux = lst;
	while (aux)
	{
		i++;
		aux = aux->next;
	}
	return (i);
}

int	ft_lstadd_back(t_list **lst, char c)
{
	t_list	*new;
	t_list	*aux;

	new = malloc(sizeof(t_list));
	if (!new)
		return (-1);
	new->content = c;
	new->next = NULL;
	if (!(*lst))
		*lst = new;
	else
	{
		aux = *lst;
		while (aux->next)
			aux = aux->next;
		aux->next = new;
	}
	return (0);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*aux1;
	t_list	*aux2;

	if (lst)
	{
		aux1 = *lst;
		while (aux1)
		{
			aux2 = aux1->next;
			free(aux1);
			aux1 = aux2;
		}
		*lst = NULL;
	}
}

int	ft_lst_next_line_size(t_list *lst)
{
	int		i;
	t_list	*aux;

	i = 0;
	aux = lst;
	while (aux)
	{
		i++;
		if (aux->content == '\n')
			return (i);
		aux = aux->next;
	}
	return (i);
}

int	put_in_list(t_list **line, char *line_part)
{
	int	i;
	int	status_node_creation;
	int	has_new_line;

	i = 0;
	has_new_line = 0;
	// if (!line_part)		// Não sei se é necessário
	// 	return (FAIL);
	if (line_part[0] == '\0')
		return (BUILD_STRING);
	while (line_part[i] != '\0')
	{
		status_node_creation = ft_lstadd_back(line, line_part[i]);
		if (status_node_creation == FAIL)	// Tratar quando acontecer isso
			return (FAIL);
		if (line_part[i] == '\n')
			has_new_line = 1;
		i++;
	}
	if (has_new_line)
		return (BUILD_STRING);
	return (READ);
}

MU_TEST(test_input_a_return_a)
{
	//ARRANGE
	char	*input = "a";
	char	*expected_result = "a";
	char	*actual_result;
	int		is_equal;
	t_list	*line = NULL;
	put_in_list(&line, input);

	//ACT
	actual_result = build_line(&line);

	//ASSERT
	is_equal = strcmp(expected_result, actual_result);
	free(actual_result);
	ft_lstclear(&line);
	mu_assert_int_eq(0, is_equal);
}

MU_TEST(test_input_string_with_new_line)
{
	//ARRANGE
	char	*input = "abcd\naaa";
	char	*expected_result = "abcd\n";
	char	*actual_result;
	int		is_equal;
	t_list	*line = NULL;
	put_in_list(&line, input);

	//ACT
	actual_result = build_line(&line);

	//ASSERT
	is_equal = strcmp(expected_result, actual_result);
	free(actual_result);
	ft_lstclear(&line);
	mu_assert_int_eq(0, is_equal);
}

MU_TEST(test_input_string_with_only_new_line_character)
{
	//ARRANGE
	char	*input = "\n";
	char	*expected_result = "\n";
	char	*actual_result;
	int		is_equal;
	t_list	*line = NULL;
	put_in_list(&line, input);

	//ACT
	actual_result = build_line(&line);

	//ASSERT
	is_equal = strcmp(expected_result, actual_result);
	free(actual_result);
	ft_lstclear(&line);
	mu_assert_int_eq(0, is_equal);
}

MU_TEST(test_input_empty_string)
{
	//ARRANGE
	char	*input = "";
	char	*expected_result = NULL;
	char	*actual_result;
	int		is_equal;
	t_list	*line = NULL;
	put_in_list(&line, input);

	//ACT
	actual_result = build_line(&line);

	//ASSERT
	is_equal = expected_result == actual_result;
	free(actual_result);
	ft_lstclear(&line);
	mu_assert_int_eq(1, is_equal);
}

MU_TEST_SUITE(ft_test_suite)
{
	MU_RUN_TEST(test_input_a_return_a);
	MU_RUN_TEST(test_input_string_with_new_line);
	MU_RUN_TEST(test_input_string_with_only_new_line_character);
	MU_RUN_TEST(test_input_empty_string);
}

int main(int argc, char *argv[]) {
	(void) argc;
	(void) argv;
	MU_RUN_SUITE(ft_test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
