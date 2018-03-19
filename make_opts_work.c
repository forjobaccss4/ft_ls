/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_opts_work.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsarapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 11:13:19 by vsarapin          #+#    #+#             */
/*   Updated: 2018/03/15 11:13:22 by vsarapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*pars_opts(char **opts, char *directory, int kind_of_sort)
{
	int		i;

	i = -1;
	if (!ft_strcmp(opts[0], "R") || (opts[1] && !ft_strcmp(opts[1], "R")))
		dirwalk(directory, opts, kind_of_sort);
	else
		make_other_flags(directory, opts, kind_of_sort);
	return (NULL);
}

void	make_other_flags(char *dir, char **opts, int sort)
{
	static int	first_or_not;
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
		else if (!ft_strcmp(opts[counter], "1"))
		{
			if (for_print_arr)
				free_double_array(for_print_arr);
			for_print_arr = save_dir_none_flags(dir, sort);
		}
		else
			for_print_arr = make_flags_contin(dir, opts, for_print_arr, sort);
	}
	prnt_flg(opts, for_print_arr, dir, first_or_not);
	first_or_not = 1;
}

char	**make_flags_contin(char *dir, char **opts, char **arr, int sort)
{
	int			counter;

	counter = -1;
	while (opts[++counter])
	{
		if (!ft_strcmp(opts[counter], "a"))
		{
			if (arr)
				free_double_array(arr);
			arr = for_a_arr(dir, sort);
		}
		else if (!ft_strcmp(opts[counter], "l"))
		{
			if (!arr)
				arr = save_dir_none_flags(dir, sort);
		}
		else if (!arr)
			arr = save_dir_none_flags(dir, sort);
	}
	return (arr);
}

void	prnt_flg(char **opt, char **ar, char *dir, int trg)
{
	int		counter;
	int		long_or_not;
	int		srt;

	srt = kind_of_srt(opt);
	counter = -1;
	long_or_not = 0;
	while (opt[++counter])
	{
		if (!ft_strcmp(opt[counter], "l"))
			long_or_not++;
		if (!ft_strcmp(opt[counter], "1"))
			long_or_not = 2;
	}
	if (long_or_not == 1 || long_or_not == 3)
		print_l_opt(ar, dir, trg, srt);
	else if (long_or_not == 2)
		ft_print_one_flag(ar, dir, trg);
	else
		print_no_l_opt(ar, dir, trg);
}
