/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_and_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsarapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 11:15:02 by vsarapin          #+#    #+#             */
/*   Updated: 2018/03/15 11:15:06 by vsarapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	if_empty_term(char **opts)
{
	char	**print_arr;
	char	**sorted_arr;
	int		*rows_cols;

	print_arr = save_dir_none_flags(".", kind_of_srt(opts));
	sorted_arr = sorted_array_with_files(print_arr);
	rows_cols = calc_rows_and_columns(".", opts);
	print_result(sorted_arr, rows_cols, ".");
	free_double_array(opts);
	free_double_array(sorted_arr);
	free_double_array(print_arr);
	free(rows_cols);
	return ;
}

void	len_dir_one_have_err(char **dirs, char **opts)
{
	char	**print_arr;
	char	**sorted_arr;
	int		*rows_cols;

	print_arr = save_dir_none_flags(dirs[0], kind_of_srt(opts));
	sorted_arr = sorted_array_with_files(print_arr);
	rows_cols = calc_rows_and_columns(dirs[0], opts);
	write(1, dirs[0], ft_strlen(dirs[0]));
	write(1, ":\n", 2);
	print_result(sorted_arr, rows_cols, dirs[0]);
	free_three_arrays(opts, sorted_arr, dirs);
	free(rows_cols);
	exit(0);
}

void	len_dir_one_have_files(char **dirs, char **opts)
{
	char	**print_arr;
	char	**sorted_arr;
	int		*rows_cols;

	print_arr = save_dir_none_flags(dirs[0], kind_of_srt(opts));
	sorted_arr = sorted_array_with_files(print_arr);
	rows_cols = calc_rows_and_columns(dirs[0], opts);
	write(1, dirs[0], ft_strlen(dirs[0]));
	write(1, ":\n", 2);
	print_result(sorted_arr, rows_cols, dirs[0]);
	free_three_arrays(opts, sorted_arr, dirs);
	free(rows_cols);
	exit(0);
}

void	len_dir_one(char **dirs, char **opts)
{
	char	**print_arr;
	char	**sorted_arr;
	int		*rows_cols;

	print_arr = save_dir_none_flags(dirs[0], kind_of_srt(opts));
	sorted_arr = sorted_array_with_files(print_arr);
	rows_cols = calc_rows_and_columns(dirs[0], opts);
	print_result(sorted_arr, rows_cols, dirs[0]);
	free_three_arrays(opts, sorted_arr, dirs);
	free(rows_cols);
	exit(0);
}

void	for_len_more_one(char **dirs, char **opts, int len_of_dirs)
{
	int		counter;

	counter = -1;
	while (dirs[++counter] && counter < len_of_dirs - 1)
	{
		for_len_more_one_help(dirs, opts, counter);
		write(1, "\n", 1);
	}
	for_len_more_one_help(dirs, opts, counter);
	free_double_array(opts);
	free_double_array(dirs);
	exit(0);
}
