#include "ft_ls.h"

void	cheking_variants(char **string_from_term)
{
	char 	**opts;
	char 	**no_opts_string;
	char 	**dirs;
	char 	**files;
	int 	errors;

	opts = NULL;
	no_opts_string = NULL;
	dirs = NULL;
	files = NULL;
	opts = dlt_repeated_symbols_opts(minus_from_opts(string_from_term));
	no_opts_string = remove_opt_from_string_input(opts, string_from_term);
	errors = treatment_of_errors(string_from_term);
	if (for_l_case(opts, no_opts_string, errors, string_from_term))
		exit (0);
	dirs = looking_for_dirs(remove_errors(\
		find_errors_in_input(no_opts_string), no_opts_string));
	files = looking_for_files(\
							remove_opt_from_string_input(opts, string_from_term));
	all_cases(opts, dirs, files, string_from_term, errors);
}

void	all_cases(char **opts, char **drs, char **fls, char **term, int err)
{
	if (!opts)
		no_opts(drs, fls, term, opts, err);
	else if (opts && !drs && !fls && err)
	{
		free_double_arrays(term, opts, drs, fls);
		exit(0);
	}
	else if (opts && (!drs || !drs[0]) && (!fls || !fls[0]) && !err)
		pars_opts(opts, ".", kind_of_srt(opts));
	else if (opts && drs && (!fls || !fls[0]) && !err)
		opts_dirs(opts, drs);
	else
		files_case(drs, fls, term, opts, err);
}

void	no_opts(char **dirs, char **files, char **term, char **opts, int errors)
{
	char 	**free_arr_with_spaces;
	int 	*rows_columns;

	free_arr_with_spaces = arr_with_spaces(files);
	rows_columns = calc_rows_and_columns_for_files(files);
	if (files && dirs)
	{
		print_files_after_errors(sorted_array_with_files(files,
			free_arr_with_spaces), rows_columns);
		write(1, "\n", 1);
		none_opts(dirs, opts, files,  term, errors);
	}
	if (files && !dirs)
	{
		print_files_after_errors(sorted_array_with_files(files,
			free_arr_with_spaces), rows_columns);
	}
	if (!files && dirs)
		none_opts(dirs, opts, files,  term, errors);
	if (!files && !dirs)
		none_opts(dirs, opts, files,  term, errors);
	free_double_arrays(term, opts, dirs, files);
}

void	opts_dirs(char **opts, char **dirs)
{
	int 	from_zero;
	int 	till_this;

	from_zero = -1;
	till_this = len_d_arr(dirs);
	return_t_r_array(kind_of_srt(opts), dirs, ".");
	if (till_this > 1)
	{
		write(1, dirs[0], ft_strlen(dirs[0]));
		write(1, ":\n", 2);
	}
	while (++from_zero < till_this)
		pars_opts(opts, dirs[from_zero], kind_of_srt(opts));
}

int 	for_l_case(char **opts, char **no_opts_string, int err, char **term)
{
	int 	counter;
	char 	*dirs_for_split;
	char 	*files_for_split;
	char 	**dirs;
	char 	**files;

	counter = -1;
	dirs_for_split = NULL;
	files_for_split = NULL;
	if (!opts)
		return (0);
	while (opts[++counter])
	{
		if (!ft_strcmp(opts[counter], "l"))
		{
			dirs_for_split = l_dirs(no_opts_string);
			files_for_split = l_files(no_opts_string);
			dirs = ft_strsplit(dirs_for_split, '\n');
			files = ft_strsplit(files_for_split, '\n');
			all_cases(opts, dirs, files, term, err);
			free_double_arrays(term, opts, dirs, files);
			return (1);
		}
	}
	return (0);
}


















