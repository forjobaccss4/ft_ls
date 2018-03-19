/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_in_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsarapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 11:07:19 by vsarapin          #+#    #+#             */
/*   Updated: 2018/03/15 11:07:24 by vsarapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	**remove_end_of_options(char **remove_from)
{
	int		i;
	t_lst	*save_string;

	save_string = NULL;
	if ((remove_from && !remove_from[0]) || !remove_from)
		return (NULL);
	if (!ft_strcmp(remove_from[0], "--"))
	{
		i = 1;
		while (remove_from[i])
		{
			save_string = joinmode_list(save_string, remove_from[i]);
			i++;
		}
		remove_from = splited_arr(save_string);
		return (remove_from);
	}
	return (remove_from);
}

char	**find_errors_in_input(char **cleared_string_from_opts)
{
	struct stat	buf;
	t_lst		*save_error_input;
	char		**splited_save_error_input;
	int			i;

	i = 0;
	if (!cleared_string_from_opts)
		return (NULL);
	save_error_input = NULL;
	while (cleared_string_from_opts[i])
	{
		if (stat(cleared_string_from_opts[i], &buf) &&
			lstat(cleared_string_from_opts[i], &buf))
			save_error_input = joinmode_list(save_error_input, \
				cleared_string_from_opts[i]);
		i++;
	}
	if (!save_error_input)
		return (NULL);
	splited_save_error_input = splited_arr(save_error_input);
	return (splited_save_error_input);
}

char	**rem_er_helper(char **found_errors, char **dirs, char **no_err_array)
{
	int i;
	int j;
	int same_strings;
	int count;

	count = 0;
	i = -1;
	while (dirs[++i])
	{
		j = -1;
		same_strings = 0;
		while (found_errors[++j])
		{
			if (!ft_strcmp(found_errors[j], dirs[i]))
				same_strings++;
		}
		if (!same_strings)
		{
			no_err_array[count] = ft_strdup(dirs[i]);
			count++;
		}
	}
	no_err_array[count] = 0;
	return (no_err_array);
}

char	**remove_errors(char **found_errors, char **dirs)
{
	char	**without_errors;
	char	**cpy_dirs;

	if (!found_errors)
	{
		cpy_dirs = copy_d_arr(dirs);
		return (cpy_dirs);
	}
	if (len_d_arr(dirs) == len_d_arr(found_errors))
		return (NULL);
	without_errors = (char**)malloc(sizeof(char*) * \
		((len_d_arr(dirs) - len_d_arr(found_errors)) + 1));
	without_errors = rem_er_helper(found_errors, dirs, without_errors);
	return (without_errors);
}

int		treatment_of_errors(char **string_from_term)
{
	char	**options;
	char	**found_err_in_input;
	char	**remove_opt;
	char	**cpy_term;

	cpy_term = copy_d_arr(string_from_term);
	options = valid_opt_or_not(find_possible_options(cpy_term));
	remove_opt = remove_opt_from_string_input(options, cpy_term);
	found_err_in_input = find_errors_in_input(remove_opt);
	free_double_array(options);
	if (!found_err_in_input)
	{
		free_double_array(remove_opt);
		free_double_array(cpy_term);
		return (0);
	}
	ft_qsort_mode(found_err_in_input, 0, len_d_arr(found_err_in_input) - 1);
	treatment_of_errors_help(found_err_in_input);
	free_double_array(found_err_in_input);
	free_double_array(remove_opt);
	free_double_array(cpy_term);
	return (1);
}
