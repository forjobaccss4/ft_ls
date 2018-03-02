#include "ft_ls.h"

char	**for_a_arr(char *dir, int sort)
{
	DIR		*open;
	char	**for_splitted_array;

	if (!(open = opendir(dir)))
		return (NULL);
	for_splitted_array = read_names_for_a(open);
	return_t_r_array(sort, for_splitted_array, dir);
	closedir(open);
	return (for_splitted_array);
}

char	**read_names_for_a(DIR *descriptor)
{
	struct dirent	*read;
	char			*array;
	char			**splited;

	array = NULL;
	splited = NULL;
	while ((read = readdir(descriptor)))
		array = joinmode_helper(array, read->d_name);
	splited = ft_strsplit(array, '\n');
	free(array);
	return (splited);
}

void	print_no_l_opt(char	**for_print, char *dir, int trigger, char **opts)
{
	if (!trigger)
		print_files_after_errors(sorted_array_with_files(for_print,
			arr_with_spaces(for_print)),
	calc_rows_and_columns_for_files(for_print));
	if (trigger)
	{
		write (1, "\n", 1);
		write(1, dir, ft_strlen(dir));
		write(1, ":\n", 2);
		print_result(sorted_array_with_files(for_print,
			arr_with_spaces(for_print)),
		calc_rows_and_columns_for_files(for_print), dir, opts);
	}
}
