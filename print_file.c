#include "ft_ls.h"

char		**loop_for_print_res(char **sorted_array, int *calc_columns_rows)
{
	int		for_start_in_array;
	int 	j;
	int 	i;
	char	**for_print_array;
	int		sum;
	
	for_start_in_array = -1;
	j = 0;
	sum = sum_of_files(sorted_array);
	for_print_array = arr_with_spaces(sorted_array);
	while (++for_start_in_array < calc_columns_rows[1])
	{
		i = 0;
		while ((i + for_start_in_array) < sum)
		{
			for_print_array[j++] = sorted_array[i + for_start_in_array];
			i += calc_columns_rows[1];
		}
		for_print_array[j - 1][max_len_of_word_in_array(sorted_array) - 9] = '\n';
	}
	return (for_print_array);
}

void		print_result(char **sorted_array, int *calc_columns_rows, char *dir, char **opts)
{
	char	**for_print_array;
	int		sum;

	if (!sorted_array)
	{
		ft_print_all_files(NULL, dir);
		return ;
	}
	sum = sum_of_files(sorted_array);
	for_print_array = arr_with_spaces(sorted_array);
	if (calc_columns_rows[0] == sum)
	{
		ft_print_all_files(sorted_array, dir);
		free(calc_columns_rows);
		return ;
	}
	for_print_array = loop_for_print_res(sorted_array, calc_rows_and_columns(dir, opts));
	ft_print_all_files(for_print_array, dir);
	free(calc_columns_rows);
}

void		ft_print_all_files_helper(char *dir)
{
	DIR 	*open;
	char	*perm_denied;
	int 	i;

	if ((open = opendir(dir)))
	{
		closedir(open);
		return ;
	}
	i = ft_strlen(dir) + 1;
	while (dir[--i] != '/' && i > 0)
	{
		if (i == 1)
		{
			write(1, "ls: ", 4);
			perror(dir);
			return ;
		}
	}
	perm_denied = ft_strdup(&dir[i + 1]);
	write(1, "ls: ", 4);
	perror(perm_denied);
	free(perm_denied);
}

void		ft_print_all_files(char **array, char *dir)
{
	int		count;
	size_t	len;
	int		max;

	max = sum_of_files(array);
	len = max_len_of_word_in_array(array);
	if (!max && len == 1)
	{
		ft_print_all_files_helper(dir);
		return ;
	}
	count = -1;
	while (++count < max)
	{
		write(1, array[count], len - 8);
		free(array[count]);
	}
	free(array);
}

void	for_len_more_one(char **dirs, char **opts, int len_of_dirs)
{
	int i;

	dirs = ft_qsort_mode(dirs, 0, len_of_dirs - 1);
	i = -1;
	while (dirs[++i] && i < len_of_dirs - 1)
	{
		write(1, dirs[i], ft_strlen(dirs[i]));
		write(1, ":\n", 2);
		print_result(sorted_array_with_files(save_dir_none_flags(dirs[i], kind_of_srt(opts)), \
			arr_with_spaces(save_dir_none_flags(dirs[i], kind_of_srt(opts)))),\
			calc_rows_and_columns(dirs[i], opts), dirs[i], opts);
		write(1, "\n", 1);
	}
	write(1, dirs[i], ft_strlen(dirs[i]));
	write(1, ":\n", 2);
	print_result(sorted_array_with_files(save_dir_none_flags(dirs[i], kind_of_srt(opts)), \
		arr_with_spaces(save_dir_none_flags(dirs[i], kind_of_srt(opts)))),\
		calc_rows_and_columns(dirs[i], opts), dirs[i], opts);
}

void	none_opts(char **dirs, char **opts, char **files, char **term, int err)
{
	int 	len_of_dirs;

	len_of_dirs = len_d_arr(dirs);
	if (!term)
	{
		print_result(sorted_array_with_files(save_dir_none_flags(".", kind_of_srt(opts)),
			arr_with_spaces(save_dir_none_flags(".", kind_of_srt(opts)))),
		calc_rows_and_columns(".", opts), ".", opts);
		exit(0);
	}
	if (len_of_dirs > 1)
		for_len_more_one(dirs, opts, len_of_dirs);
	else if (len_of_dirs == 1 && err)
	{
		write(1, dirs[0], ft_strlen(dirs[0]));
		write(1, ":\n", 2);
		print_result(sorted_array_with_files(save_dir_none_flags(dirs[0], kind_of_srt(opts)), \
			arr_with_spaces(save_dir_none_flags(dirs[0], kind_of_srt(opts)))),\
			calc_rows_and_columns(dirs[0], opts), dirs[0], opts);
	}
	else if (len_of_dirs == 1 && files)
	{
		write(1, dirs[0], ft_strlen(dirs[0]));
		write(1, ":\n", 2);
		print_result(sorted_array_with_files(save_dir_none_flags(dirs[0], kind_of_srt(opts)), \
			arr_with_spaces(save_dir_none_flags(dirs[0], kind_of_srt(opts)))),\
			calc_rows_and_columns(dirs[0], opts), dirs[0], opts);
	}
	else if (len_of_dirs == 1)
		print_result(sorted_array_with_files(save_dir_none_flags(dirs[0], kind_of_srt(opts)), \
			arr_with_spaces(save_dir_none_flags(dirs[0], kind_of_srt(opts)))),\
		 calc_rows_and_columns(dirs[0], opts), dirs[0], opts);
}
