/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danbarbo <danbarbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:21:08 by danbarbo          #+#    #+#             */
/*   Updated: 2023/10/27 00:37:53 by danbarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

char	*get_next_line(int fd);		// Prototype

MU_TEST(test_gnl_first_line)
{
	//ARRANGE
	int		fd = open("test.txt", O_RDONLY);
	char	*expected_result = "Lorem ipsum dolor sit amet, consectetur adipiscing elit.\n";
	char	*actual_result;
	int		is_equal;

	//ACT
	actual_result = get_next_line(fd);

	//ASSERT
	is_equal = strcmp(expected_result, actual_result);
	close(fd);
	free(actual_result);
	mu_assert_int_eq(0, is_equal);
}

MU_TEST(test_gnl_second_line)
{
	//ARRANGE
	int		fd = open("test.txt", O_RDONLY);
	char	*expected_result = "Aenean hendrerit fringilla libero vel euismod.\n";
	char	*actual_result;
	int		is_equal;

	//ACT
	actual_result = get_next_line(fd);

	//ASSERT
	is_equal = strcmp(expected_result, actual_result);
	close(fd);
	free(actual_result);
	mu_assert_int_eq(0, is_equal);
}

MU_TEST_SUITE(ft_gnl_test_suite)
{
	MU_RUN_TEST(test_gnl_first_line);
	MU_RUN_TEST(test_gnl_second_line);
}

int main(int argc, char *argv[]) {
	(void) argc;
	(void) argv;
	MU_RUN_SUITE(ft_gnl_test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
