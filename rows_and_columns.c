#include "ft_ls.h"

int					calc_in_one_line_or_columns(char *dir)
{
	size_t			res;
	double			min_cols;
	size_t			result;
	int 			sum;
	unsigned long 	max;

	max = max_len_of_word_in_array(save_dir_none_flags(dir));
	sum = sum_of_files_in_dir_non_all_flag(dir);
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

int			*calc_rows_and_columns(char *dir)
{
	int		*ret_cals_rows;
	int		sum;
	int		rows;
	int		calc_columns;

	calc_columns = calc_in_one_line_or_columns(dir);
	sum = sum_of_files_in_dir_non_all_flag(dir);
	if (calc_columns)
		rows = sum / calc_columns;/* DELENIE NA 0*/
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
