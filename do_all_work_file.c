#include "ft_ls.h"

void	cheking_variants(char **string_from_term)
{
	char 	**opts = dlt_repeated_symbols_opts(minus_from_opts(string_from_term));
	char 	**fresh_ostatok = remove_opt_from_string_input(opts, string_from_term);
	treatment_of_errors(string_from_term);
	char 	**dirs = looking_for_dirs(remove_errors(find_errors_in_input(fresh_ostatok), fresh_ostatok));
	char 	**files = looking_for_files(\
							remove_opt_from_string_input(opts, string_from_term));
	if ((!opts && !dirs && !files) || (!opts && dirs && !files))
		print_all_in_dirs_none_opts(dirs, string_from_term);
}