#include "ft_ls.h"

void		ft_print_all_array_with_files(char **files)
{
	int		count;
	size_t	len;
	int		max;

	max = len_d_arr(files);
	len = ft_strlen(files[0]);
	count = 0;
	while (count < max)
	{
		write(1, files[count], len);
		free(files[count]);
		count++;
	}
	free(files);
 }

void		print_files_after_errors(char **srtd_fls, int *calc_cols_rows_for_fls)
{
	int		i;
	int		j;
	int		for_start_in_array;
	int		sum;
	char	**for_print_array;
	
	sum = len_d_arr(srtd_fls);
	if (calc_cols_rows_for_fls[0] == sum)
	{
		ft_print_all_array_with_files(srtd_fls);
		free(calc_cols_rows_for_fls);
		return ;
	}
	for_print_array = arr_with_spaces(srtd_fls);
	j = 0;
	for_start_in_array = -1;
	while (++for_start_in_array < calc_cols_rows_for_fls[1])
	{
		i = 0;
		while ((i + for_start_in_array) < sum)
		{
			for_print_array[j++] = srtd_fls[i + for_start_in_array];
			i += calc_cols_rows_for_fls[1];
		}
		for_print_array[j - 1][max_len_of_word_in_array(srtd_fls) - 9] = '\n';
	}
	ft_print_all_array_with_files(for_print_array);
	free(calc_cols_rows_for_fls);
}
