/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsarapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 11:15:25 by vsarapin          #+#    #+#             */
/*   Updated: 2018/03/15 11:15:30 by vsarapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		**loop_for_print_res(char **sorted_array, int *calc_columns_rows)
{
	int		for_start_in_array;
	int		j;
	int		i;
	char	**print_array;
	int		sum;

	print_array = NULL;
	for_start_in_array = -1;
	j = 0;
	sum = sum_of_files(sorted_array);
	print_array = (char**)malloc(sizeof(char*) * (sum + 1));
	print_array[sum] = 0;
	while (++for_start_in_array < calc_columns_rows[1])
	{
		i = 0;
		while ((i + for_start_in_array) < sum)
		{
			print_array[j++] = \
			ft_strdup(sorted_array[i + for_start_in_array]);
			i += calc_columns_rows[1];
		}
		print_array[j - 1][max_len_of_word_in_array(sorted_array) - 9] = '\n';
	}
	return (print_array);
}

void		print_result(char **sorted_array, int *calc_columns_rows, char *dir)
{
	char	**for_print_array;
	int		sum;

	for_print_array = NULL;
	if (!sorted_array)
	{
		ft_print_all_files(NULL, dir);
		return ;
	}
	sum = sum_of_files(sorted_array);
	if (calc_columns_rows[0] == sum)
	{
		ft_print_all_files(sorted_array, dir);
		return ;
	}
	for_print_array = loop_for_print_res(sorted_array, calc_columns_rows);
	ft_print_all_files(for_print_array, dir);
	free_double_array(for_print_array);
}

void		ft_print_all_files_helper(char *dir)
{
	DIR		*open;
	char	*perm_denied;
	int		i;

	if ((open = opendir(dir)))
	{
		closedir(open);
		return ;
	}
	i = ft_strlen(dir) + 1;
	while (dir[--i] != '/' && i > 0)
	{
		if (i == 1)
		{
			write(1, "ls: ", 4);
			perror(dir);
			return ;
		}
	}
	perm_denied = ft_strdup(&dir[i + 1]);
	write(1, "ls: ", 4);
	perror(perm_denied);
	free(perm_denied);
}

void		ft_print_all_files(char **array, char *dir)
{
	int		count;
	size_t	len;
	int		max;

	max = sum_of_files(array);
	len = max_len_of_word_in_array(array);
	if (!max && len == 1)
	{
		ft_print_all_files_helper(dir);
		return ;
	}
	count = -1;
	while (++count < max)
		write(1, array[count], len - 8);
}

void		none_opts(char **dirs, char **opts, char **files, int err)
{
	int	len_of_dirs;

	len_of_dirs = len_d_arr(dirs);
	if (len_of_dirs > 1)
		for_len_more_one(dirs, opts, len_of_dirs);
	else if (len_of_dirs == 1 && err)
		len_dir_one_have_err(dirs, opts);
	else if (len_of_dirs == 1 && files)
		len_dir_one_have_files(dirs, opts);
	else if (len_of_dirs == 1)
		len_dir_one(dirs, opts);
}
