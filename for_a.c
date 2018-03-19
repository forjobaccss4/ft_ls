/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsarapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 10:56:02 by vsarapin          #+#    #+#             */
/*   Updated: 2018/03/15 10:56:11 by vsarapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	**for_a_arr(char *dir, int sort)
{
	DIR		*open;
	char	**for_splitted_array;

	if (!(open = opendir(dir)))
		return (NULL);
	for_splitted_array = read_names_for_a(open);
	return_t_r_array(sort, for_splitted_array, dir);
	closedir(open);
	return (for_splitted_array);
}

char	**read_names_for_a(DIR *descriptor)
{
	struct dirent	*read;
	t_lst			*array;
	char			**splited;

	array = NULL;
	splited = NULL;
	while ((read = readdir(descriptor)))
		array = joinmode_list(array, read->d_name);
	splited = splited_arr(array);
	return (splited);
}

void	print_no_l_opt(char **for_print, char *dir, int trigger)
{
	if (!trigger)
		print_no_l_opt_tr_zero(for_print, dir);
	if (trigger)
		print_no_l_opt_tr_one(for_print, dir);
}

void	ft_print_one_flag(char **array, char *dir, int trg)
{
	int count;

	count = -1;
	if (!trg)
		print_one_flag_trg_zero(array, dir, count);
	if (trg)
		print_one_flag_trg_one(array, dir, count);
}

void	print_one_opt(char **fls, char **opts)
{
	int counter;

	counter = -1;
	if (fls && fls[0])
	{
		return_t_r_array(kind_of_srt(opts), fls, ".");
		while (fls[++counter])
		{
			ft_putstr(fls[counter]);
			write(1, "\n", 1);
		}
	}
}
