/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_all_work_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsarapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 10:56:38 by vsarapin          #+#    #+#             */
/*   Updated: 2018/03/15 10:56:46 by vsarapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	**dirs_opts(char **opts, char **no_opts_string, char **rem)
{
	int		counter;
	t_lst	*dirs_for_split;
	char	**dirs;

	counter = -1;
	if (!opts)
	{
		dirs = looking_for_dirs(rem);
		return (dirs);
	}
	while (opts[++counter])
	{
		if (!ft_strcmp(opts[counter], "l"))
		{
			dirs_for_split = l_dirs(no_opts_string);
			dirs = splited_arr(dirs_for_split);
			return (dirs);
		}
	}
	dirs = looking_for_dirs(rem);
	return (dirs);
}

char	**files_opts(char **opts, char **no_opts_string)
{
	int		counter;
	t_lst	*files_for_split;
	char	**files;

	counter = -1;
	if (!opts)
	{
		files = looking_for_files(no_opts_string);
		return (files);
	}
	while (opts[++counter])
	{
		if (!ft_strcmp(opts[counter], "l"))
		{
			files_for_split = l_files(no_opts_string);
			files = splited_arr(files_for_split);
			return (files);
		}
	}
	files = looking_for_files(no_opts_string);
	return (files);
}

void	all_cases(char **opts, char **drs, char **fls, int err)
{
	char	*directory;

	directory = ".";
	if (!opts)
		no_opts(drs, fls, opts, err);
	else if (opts && (!drs || !drs[0]) && (!fls || !fls[0]) && !err)
		pars_opts(opts, directory, kind_of_srt(opts));
	else if (opts && drs && (!fls || !fls[0]) && (!err || err))
		opts_dirs(opts, drs, err);
	else
		files_case(drs, fls, opts, err);
}

void	no_opts(char **dirs, char **files, char **opts, int errors)
{
	int		*rows_columns;

	rows_columns = calc_rows_and_columns_for_files(files);
	if (files && dirs && (!errors || errors))
	{
		print_files_after_errors(sorted_array_with_files(files), rows_columns);
		write(1, "\n", 1);
		none_opts(dirs, opts, files, errors);
	}
	if (files && !dirs)
		print_files_after_errors(sorted_array_with_files(files), rows_columns);
	if ((!files && dirs) || (!files && !dirs))
		none_opts(dirs, opts, files, errors);
	free(rows_columns);
}

void	opts_dirs(char **opts, char **dirs, int err)
{
	int		from_zero;
	int		till_this;

	from_zero = -1;
	till_this = len_d_arr(dirs);
	if (till_this == 1 && err)
	{
		write(1, dirs[0], ft_strlen(dirs[0]));
		write(1, ":\n", 2);
	}
	return_t_r_array(kind_of_srt(opts), dirs, ".");
	if (till_this > 1)
	{
		write(1, dirs[0], ft_strlen(dirs[0]));
		write(1, ":\n", 2);
	}
	while (++from_zero < till_this)
		pars_opts(opts, dirs[from_zero], kind_of_srt(opts));
}
