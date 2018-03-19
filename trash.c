/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsarapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 11:16:02 by vsarapin          #+#    #+#             */
/*   Updated: 2018/03/15 11:16:05 by vsarapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		files_output_flags(char **opts, char **files, int trigg)
{
	int			*rows_cols;
	char		**sorted;

	rows_cols = calc_rows_and_columns_for_files(files);
	sorted = sorted_array_with_files(files);
	if (trigg)
	{
		free_double_array(sorted);
		free(rows_cols);
		return (1);
	}
	trigg = files_output_hlp(sorted, rows_cols, trigg, opts);
	if (!trigg)
		free_double_array(sorted);
	free(rows_cols);
	return (trigg);
}

int		files_output_flags_cont(char **opt, char **fls, int trg)
{
	int			*rows_cols;
	char		**sorted;

	rows_cols = calc_rows_and_columns_for_files(fls);
	sorted = sorted_array_with_files(fls);
	if (trg)
	{
		free_double_array(sorted);
		free(rows_cols);
		return (1);
	}
	trg = files_with_flags_hlp_cn(sorted, rows_cols, trg, opt);
	if (!trg)
		free_double_array(sorted);
	free(rows_cols);
	return (trg);
}

void	print_no_l_opt_tr_one(char **for_print, char *dir)
{
	int		*rows_cols;
	char	**sorted;

	rows_cols = calc_rows_and_columns_for_files(for_print);
	sorted = sorted_array_with_files(for_print);
	write(1, "\n", 1);
	write(1, dir, ft_strlen(dir));
	write(1, ":\n", 2);
	print_result(sorted, rows_cols, dir);
	free(rows_cols);
	free_double_array(for_print);
	free_double_array(sorted);
}

void	print_no_l_opt_tr_zero(char **for_print, char *dir)
{
	DIR		*open;
	int		*rows_cols;
	char	**sorted;

	rows_cols = calc_rows_and_columns_for_files(for_print);
	sorted = sorted_array_with_files(for_print);
	if (!(open = opendir(dir)))
	{
		ft_print_all_files_helper(dir);
		free(rows_cols);
		free_double_array(for_print);
		return ;
	}
	closedir(open);
	if (for_print && for_print[0])
	{
		print_files_after_errors(sorted, rows_cols);
		free(rows_cols);
		free_double_array(for_print);
	}
}

void	for_len_more_one_help(char **dirs, char **opts, int counter)
{
	char	**print_arr;
	char	**sorted_arr;
	int		*rows_cols;

	write(1, dirs[counter], ft_strlen(dirs[counter]));
	write(1, ":\n", 2);
	print_arr = save_dir_none_flags(dirs[counter], kind_of_srt(opts));
	sorted_arr = sorted_array_with_files(print_arr);
	rows_cols = calc_rows_and_columns(dirs[counter], opts);
	print_result(sorted_arr, rows_cols, dirs[counter]);
	free_double_array(print_arr);
	free_double_array(sorted_arr);
	free(rows_cols);
}
