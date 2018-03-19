/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rows_and_columns.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsarapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 11:15:48 by vsarapin          #+#    #+#             */
/*   Updated: 2018/03/15 11:15:54 by vsarapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			calc_in_one_line_or_columns(char *dir, char **opts)
{
	size_t			res;
	double			min_cols;
	size_t			result;
	int				sum;
	char			**for_max;

	for_max = save_dir_none_flags(dir, kind_of_srt(opts));
	sum = sum_of_files_in_dir_non_all_flag(dir);
	min_cols = sum / 2.00;
	result = min_cols;
	res = size_of_screen() / max_len_of_word_in_array(for_max);
	result = (min_cols + 0.5 >= (result + 1)) ? (result + 1) : min_cols;
	if (res > result)
		res = result;
	if (size_of_screen() < max_len_of_word_in_array(for_max))
	{
		free_double_array(for_max);
		return ('1');
	}
	if ((max_len_of_word_in_array(for_max) * sum) <= size_of_screen())
		res = sum;
	free_double_array(for_max);
	return (res);
}

int			*calc_rows_and_columns(char *dir, char **opts)
{
	int		*ret_cals_rows;
	int		sum;
	int		rows;
	int		calc_columns;

	calc_columns = calc_in_one_line_or_columns(dir, opts);
	sum = sum_of_files_in_dir_non_all_flag(dir);
	if (calc_columns)
		rows = sum / calc_columns;
	ret_cals_rows = (int*)malloc(sizeof(int) * 2);
	ret_cals_rows[0] = calc_columns;
	if (calc_columns == sum)
	{
		ret_cals_rows[1] = 1;
		return (ret_cals_rows);
	}
	if ((sum - (rows * (calc_columns - 1))) > rows)
	{
		ret_cals_rows[1] = (rows + 1);
		return (ret_cals_rows);
	}
	ret_cals_rows[1] = rows;
	return (ret_cals_rows);
}

int			calc_columns_for_files(char **files)
{
	size_t			res;
	double			min_cols;
	size_t			result;
	int				sum;
	unsigned long	max;

	max = max_len_of_word_in_array(files);
	sum = len_d_arr(files);
	min_cols = sum / 2.00;
	result = min_cols;
	res = size_of_screen() / max;
	if ((min_cols + 0.5) >= (result + 1))
		result = result + 1;
	else
		result = min_cols;
	if (res > result)
		res = result;
	if (size_of_screen() < max)
	{
		res = 1;
		return (res);
	}
	if ((max * sum) <= size_of_screen())
		res = sum;
	return (res);
}

int			*calc_rows_and_columns_for_files(char **files)
{
	int		*ret_cals_rows;
	int		sum;
	int		rows;
	int		calc_columns;

	calc_columns = calc_columns_for_files(files);
	sum = len_d_arr(files);
	if (calc_columns)
		rows = sum / calc_columns;
	ret_cals_rows = (int*)malloc(sizeof(int) * 2);
	ret_cals_rows[0] = calc_columns;
	if (calc_columns == sum)
	{
		ret_cals_rows[1] = 1;
		return (ret_cals_rows);
	}
	if ((sum - (rows * (calc_columns - 1))) > rows)
	{
		ret_cals_rows[1] = (rows + 1);
		return (ret_cals_rows);
	}
	ret_cals_rows[1] = rows;
	return (ret_cals_rows);
}
