#include "ft_ls.h"

void		print_result(char **sorted_array, int *calc_columns_rows, char *dir)
{
	char	**for_print_array;
	int		i;
	int		j;
	int		for_start_in_array;
	int		sum;

	sum = sum_of_files_in_dir_non_all_flag(dir);
	for_print_array = arr_with_spaces(dir);
	if (calc_columns_rows[0] == sum)
	{
		ft_print_all_files(sorted_array, dir);
		free(calc_columns_rows);
		return ;
	}
	j = 0;
	for_start_in_array = -1;
	while (++for_start_in_array < calc_columns_rows[1])
	{
		i = 0;
		while ((i + for_start_in_array) < sum)
		{
			for_print_array[j++] = sorted_array[i + for_start_in_array];
			i += calc_columns_rows[1];
		}
		for_print_array[j - 1][max_len_of_word_in_array(save_dir_none_flags(dir)) - 1] = '\n';
	}
	ft_print_all_files(for_print_array, dir);
	free(calc_columns_rows);
}

void		ft_print_all_files(char **array, char *dir)
{
	int		count;
	size_t	len;
	int		max;

	max = sum_of_files_in_dir_non_all_flag(dir);
	len = max_len_of_word_in_array(save_dir_none_flags(dir));
	count = 0;
	while (count < max)
	{
		write(1, array[count], len);
		free(array[count]);
		count++;
	}
	free(array);
 }

void	print_all_in_dirs_none_opts(char **dirs, char **term, int errors)
{
	int i;
	int len_of_dirs;

	len_of_dirs = len_d_arr(dirs);
	if (!term)
	{
		print_result(sorted_array_with_files(arr_with_spaces("."), "."), \
			calc_rows_and_columns("."), ".");
		exit(1);
	}
	if (len_of_dirs > 1)
	{
		dirs = ft_qsort_mode(dirs, 0, len_of_dirs - 1);
		i = -1;
		while (dirs[++i] && i < len_of_dirs - 1)
		{

			write(1, dirs[i], ft_strlen(dirs[i]));
			write(1, ":\n", 2);
			print_result(sorted_array_with_files(arr_with_spaces(dirs[i]), dirs[i]),\
						 calc_rows_and_columns(dirs[i]), dirs[i]);
			write(1, "\n", 1);
		}
		write(1, dirs[i], ft_strlen(dirs[i]));
		write(1, ":\n", 2);
		print_result(sorted_array_with_files(arr_with_spaces(dirs[i]), dirs[i]),\
						 calc_rows_and_columns(dirs[i]), dirs[i]);
	}
	else if (len_of_dirs == 1 && errors)
	{
		write(1, dirs[0], ft_strlen(dirs[0]));
		write(1, ":\n", 2);
		print_result(sorted_array_with_files(arr_with_spaces(dirs[0]), dirs[0]),\
		 calc_rows_and_columns(dirs[0]), dirs[0]);
	}
	else if (len_of_dirs == 1)
		print_result(sorted_array_with_files(arr_with_spaces(dirs[0]), dirs[0]),\
		 calc_rows_and_columns(dirs[0]), dirs[0]);
	else
		exit(1);
}