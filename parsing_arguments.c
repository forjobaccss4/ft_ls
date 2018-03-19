/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_arguments.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsarapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 11:14:20 by vsarapin          #+#    #+#             */
/*   Updated: 2018/03/15 11:14:51 by vsarapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		**find_possible_options(char **string_from_term)
{
	int		i;
	t_lst	*save_options;
	char	**splited_save_options;

	i = 0;
	save_options = NULL;
	splited_save_options = NULL;
	if (!string_from_term)
		return (NULL);
	while (string_from_term[i] \
		&& string_from_term[i][0] == '-' \
		&& string_from_term[i][1] != '\0' \
		&& ft_strcmp(string_from_term[i], "--") != 0)
	{
		save_options = joinmode_list(save_options, string_from_term[i]);
		i++;
	}
	if (!save_options)
		return (NULL);
	splited_save_options = splited_arr(save_options);
	return (splited_save_options);
}

void		error_mes_of_nonval_opt(char c)
{
	write(2, "ls: illegal option -- ", 22);
	write(2, &c, 1);
	write(2, "\n", 1);
	write(2, "usage: ls [-Ralrt1] [file ...]\n", 31);
}

char		**valid_opt_or_not(char **possible_options)
{
	int i;

	i = -1;
	if (possible_options)
	{
		while (possible_options[++i])
		{
			if (!valid_flags(possible_options, i))
				continue ;
		}
	}
	return (possible_options);
}

char		**coinc_in_double_array(char **remove_this_opts, char **remove_from)
{
	t_lst	*return_this;
	char	**returned;
	char	**copy_returned;
	int		i;

	return_this = NULL;
	if (!remove_from)
		return (NULL);
	if (!remove_this_opts)
	{
		copy_returned = copy_d_arr(remove_from);
		return (copy_returned);
	}
	i = coinc_helper(remove_from);
	if (!remove_from[i])
		return (NULL);
	while (remove_from[i])
	{
		return_this = joinmode_list(return_this, remove_from[i]);
		i++;
	}
	returned = splited_arr(return_this);
	return (returned);
}

char		**remove_opt_from_string_input(char **poss_opt, char **term)
{
	char	**string_with_end_of_opt;
	char	**split_save_string;

	string_with_end_of_opt = NULL;
	split_save_string = NULL;
	string_with_end_of_opt = coinc_in_double_array(poss_opt, term);
	split_save_string = remove_end_of_options(string_with_end_of_opt);
	return (split_save_string);
}
