#include "ft_ls.h"

void	cheking_variants(char **string_from_term)
{
	char 	**opts = dlt_repeated_symbols_opts(minus_from_opts(string_from_term));
	char 	**no_opts_string = remove_opt_from_string_input(opts, string_from_term);
	char 	**dirs = looking_for_dirs(remove_errors(find_errors_in_input(no_opts_string), no_opts_string));
	char 	**files = looking_for_files(\
							remove_opt_from_string_input(opts, string_from_term));
	int i = treatment_of_errors(string_from_term);
	if ((!opts && !dirs && !files) || (!opts && dirs && !files))
		print_all_in_dirs_none_opts(dirs, string_from_term, i);
}