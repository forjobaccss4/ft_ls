#include "ft_ls.h"

char	*pars_opts(char **opts, char *directory, int kind_of_sort)
{
	int		i;

	i = -1;
	if (!ft_strcmp(opts[0], "R"))
		dirwalk(directory, opts, kind_of_sort);
	else
		make_other_flags(directory, opts, kind_of_sort);
	return (NULL);
}

void 	make_other_flags(char *dir, char **opts, int sort)
{
	static int 	first_or_not;
	int			counter;
	char		**for_print_arr;

	counter = -1;
	for_print_arr = NULL;
	while (opts[++counter])
	{
		if (!ft_strcmp(opts[counter], "R"))
		{
			if (for_print_arr)
				free_double_array(for_print_arr);
				for_print_arr = save_dir_none_flags(dir, sort);
		}
		else if (!ft_strcmp(opts[counter], "a"))
		{
			if (for_print_arr)
				free_double_array(for_print_arr);
			for_print_arr = for_a_arr(dir, sort);
		}
		else if (!ft_strcmp(opts[counter], "l"))
		{
			if (!for_print_arr)
				for_print_arr = save_dir_none_flags(dir, sort);
		}
		else if (!for_print_arr)
			for_print_arr = save_dir_none_flags(dir, sort);
	}
	print_flag(opts, for_print_arr, dir, first_or_not, sort);
	first_or_not = 1;
}

void	print_flag(char **opts, char **print, char *dir, int trigger, int sort)
{
	int 	counter;
	int		long_or_not;

	counter = -1;
	long_or_not = 0;
	while (opts[++counter])
		if (!ft_strcmp(opts[counter], "l"))
			long_or_not++;
		if (long_or_not)
			print_l_opt(print, dir, trigger, sort);
		else
			print_no_l_opt(print, dir, trigger, opts);
}
