/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsarapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 15:51:47 by vsarapin          #+#    #+#             */
/*   Updated: 2018/03/15 15:51:49 by vsarapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		opts_with_files(char **opts, char **files, int trigger)
{
	int		counter;

	counter = -1;
	while (opts[++counter])
	{
		if (!ft_strcmp(opts[counter], "l") && !trigger)
		{
			print_long_format_files(files, ".");
			trigger++;
		}
	}
	counter = -1;
	while (opts[++counter])
	{
		if (!ft_strcmp(opts[counter], "1") && !trigger)
		{
			print_one_opt(files, opts);
			trigger++;
		}
	}
	return (trigger);
}

int		valid_flags(char **flags, int i)
{
	int j;

	j = 1;
	while (flags[i][j])
	{
		if (flags[i][j] == 'a' || flags[i][j] == 'l' \
			|| flags[i][j] == 'r' || flags[i][j] == 'R' \
			|| flags[i][j] == 't' || flags[i][j] == '1')
			j++;
		else
		{
			error_mes_of_nonval_opt(flags[i][j]);
			free_double_array(flags);
			exit(1);
		}
	}
	return (0);
}

int		coinc_helper(char **remove_from)
{
	int i;

	i = 0;
	while (remove_from[i] && remove_from[i][0] == '-' \
		&& remove_from[i][1] != '\0'\
		&& ft_strcmp(remove_from[i], "--"))
		i++;
	return (i);
}
