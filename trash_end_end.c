/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash_end_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsarapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 13:18:41 by vsarapin          #+#    #+#             */
/*   Updated: 2018/03/16 13:18:48 by vsarapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	first_func(char **term)
{
	char	**opts;
	char	**no_opts_string;
	char	**find_err;
	char	**rem_errors;
	int		err;

	opts = dlt_repeated_symbols_opts(minus_from_opts(term));
	no_opts_string = remove_opt_from_string_input(opts, term);
	find_err = find_errors_in_input(no_opts_string);
	rem_errors = remove_errors(find_err, no_opts_string);
	if (!term || (!ft_strcmp(term[0], "--") && len_d_arr(term) == 1))
	{
		if_empty_term(opts);
		free_d_arr(opts, no_opts_string, find_err, rem_errors);
		exit(0);
	}
	err = second_func_(opts, term, find_err, rem_errors);
	third_func(opts, rem_errors, term, err);
	free_double_array(find_err);
	free_double_array(no_opts_string);
	free_double_array(rem_errors);
	free_double_array(opts);
	return ;
}

int		second_func_(char **opts, char **term, char **fi, char **rem)
{
	char	**dirs;
	char	**files;
	char	**no;
	int		errors;

	no = remove_opt_from_string_input(opts, term);
	errors = treatment_of_errors(term);
	dirs = dirs_opts(opts, no, rem);
	files = files_opts(opts, no);
	if (opts && !dirs && !files)
	{
		if (errors)
		{
			free_d_arr(term, opts, fi, rem);
			free_three_arrays(no, dirs, files);
			exit(1);
		}
	}
	free_three_arrays(no, dirs, files);
	return (errors);
}

void	third_func(char **opts, char **rem, char **term, int errors)
{
	char	**no_opts_string;
	char	**dirs;
	char	**files;

	opts = dlt_repeated_symbols_opts(minus_from_opts(term));
	no_opts_string = remove_opt_from_string_input(opts, term);
	dirs = dirs_opts(opts, no_opts_string, rem);
	files = files_opts(opts, no_opts_string);
	all_cases(opts, dirs, files, errors);
	free_double_array(no_opts_string);
	free_double_array(dirs);
	free_double_array(files);
	free_double_array(opts);
}
