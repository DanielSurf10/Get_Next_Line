/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_put_in_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:21:08 by danbarbo          #+#    #+#             */
/*   Updated: 2023/11/02 13:27:15 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int	put_in_list(t_list **line, char *line_part);

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

char	*build_line(t_list **line)
{
	int		i;
	int		line_size;
	t_list	*aux;
	char	*line_to_return;

	line_size = ft_lstsize(*line);
	line_to_return = (char *) malloc(line_size + 1);
	line_to_return[line_size] = '\0';

	i = 0;
	while (i < line_size)
	{
		aux = *line;
		line_to_return[i] = (*line)->content;
		*line = (*line)->next;
		free(aux);
		i++;
	}

	return (line_to_return);
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

MU_TEST(test_input_a_return_a)
{
	//ARRANGE
	char	*input = "a";
	char	*expected_result = "a";
	char	*actual_result;
	int		is_equal;
	t_list	*line = NULL;

	//ACT
	put_in_list(&line, input);

	//ASSERT
	actual_result = build_line(&line);
	is_equal = strcmp(expected_result, actual_result);
	free(actual_result);
	ft_lstclear(&line);
	mu_assert_int_eq(0, is_equal);
}

MU_TEST(test_input_aaa_return_aaa)
{
	//ARRANGE
	char	*input = "aaa";
	char	*expected_result = "aaa";
	char	*actual_result;
	int		is_equal;
	t_list	*line = NULL;

	//ACT
	put_in_list(&line, input);

	//ASSERT
	actual_result = build_line(&line);
	is_equal = strcmp(expected_result, actual_result);
	free(actual_result);
	ft_lstclear(&line);
	mu_assert_int_eq(0, is_equal);
}

MU_TEST(test_status_need_to_read_again)
{
	//ARRANGE
	char	*input = "aaa";
	char	*expected_result = "aaa";
	char	*actual_result;
	int		is_equal;
	int		return_value;
	int		return_value_expected = READ;
	t_list	*line = NULL;

	//ACT
	return_value = put_in_list(&line, input);

	//ASSERT
	actual_result = build_line(&line);
	is_equal = strcmp(expected_result, actual_result);
	free(actual_result);
	ft_lstclear(&line);
	mu_assert_int_eq(return_value_expected, return_value);
}

MU_TEST(test_status_no_need_to_read_again)
{
	//ARRANGE
	char	*input = "aaa\naaa";
	char	*expected_result = "aaa";
	char	*actual_result;
	int		is_equal;
	int		return_value;
	int		return_value_expected = BUILD_STRING;
	t_list	*line = NULL;

	//ACT
	return_value = put_in_list(&line, input);

	//ASSERT
	actual_result = build_line(&line);
	is_equal = strcmp(expected_result, actual_result);
	free(actual_result);
	ft_lstclear(&line);
	mu_assert_int_eq(return_value_expected, return_value);
}

MU_TEST(test_input_string_with_new_line)
{
	//ARRANGE
	char	*input = "\n";
	char	*expected_result = "\n";
	char	*actual_result;
	int		is_equal;
	int		return_value;
	int		return_value_expected = BUILD_STRING;
	t_list	*line = NULL;

	//ACT
	return_value = put_in_list(&line, input);

	//ASSERT
	actual_result = build_line(&line);
	is_equal = strcmp(expected_result, actual_result);
	free(actual_result);
	ft_lstclear(&line);
	mu_assert_int_eq(return_value_expected, return_value);
}

MU_TEST(test_input_string_with_2_new_line)
{
	//ARRANGE
	char	*input = "\n\n";
	char	*expected_result = "\n\n";
	char	*actual_result;
	int		is_equal;
	int		return_value;
	int		return_value_expected = BUILD_STRING;
	t_list	*line = NULL;

	//ACT
	return_value = put_in_list(&line, input);

	//ASSERT
	actual_result = build_line(&line);
	is_equal = strcmp(expected_result, actual_result);
	free(actual_result);
	ft_lstclear(&line);
	mu_assert_int_eq(return_value_expected, return_value);
}

MU_TEST(test_input_empty_string_return_null)
{
	//ARRANGE
	char	*input = "";
	char	*expected_result = NULL;
	char	*actual_result;
	int		is_equal;
	int		return_value;
	int		return_value_expected = FINISH;
	t_list	*line = NULL;

	//ACT
	return_value = put_in_list(&line, input);

	//ASSERT
	actual_result = build_line(&line);
	is_equal = actual_result == expected_result;
	free(actual_result);
	ft_lstclear(&line);
	mu_assert_int_eq(return_value_expected, return_value);
}

MU_TEST_SUITE(ft_test_suite)
{
	MU_RUN_TEST(test_input_a_return_a);
	MU_RUN_TEST(test_input_aaa_return_aaa);
	MU_RUN_TEST(test_status_need_to_read_again);
	MU_RUN_TEST(test_status_no_need_to_read_again);
	MU_RUN_TEST(test_input_string_with_new_line);
	MU_RUN_TEST(test_input_string_with_2_new_line);
	MU_RUN_TEST(test_input_empty_string_return_null);
}

int main(int argc, char *argv[]) {
	(void) argc;
	(void) argv;
	MU_RUN_SUITE(ft_test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
