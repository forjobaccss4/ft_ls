/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_with_dirs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsarapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 11:10:13 by vsarapin          #+#    #+#             */
/*   Updated: 2018/03/15 11:10:17 by vsarapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	**looking_for_dirs(char **without_opts)
{
	struct stat	buf;
	int			i;
	t_lst		*save_dirs;
	char		**split_dirs;

	i = -1;
	save_dirs = NULL;
	if (!without_opts)
		return (NULL);
	while (without_opts[++i])
	{
		if (!stat(without_opts[i], &buf) && S_ISDIR(buf.st_mode))
			save_dirs = joinmode_list(save_dirs, without_opts[i]);
	}
	if (!save_dirs)
		return (NULL);
	split_dirs = splited_arr(save_dirs);
	return (split_dirs);
}

char	**save_dir_none_flags(char *dir, int sort)
{
	DIR		*open;
	t_lst	*read_array;
	char	**for_splitted_array;

	if (!(open = opendir(dir)))
		return (NULL);
	read_array = read_names(open);
	for_splitted_array = splited_arr(read_array);
	closedir(open);
	return_t_r_array(sort, for_splitted_array, dir);
	return (for_splitted_array);
}

t_lst	*read_names(DIR *descriptor)
{
	struct dirent	*read;
	t_lst			*array;

	array = NULL;
	while ((read = readdir(descriptor)))
	{
		if (!ft_strcmp(read->d_name, ".") || !ft_strcmp(read->d_name, "..") \
				|| read->d_name[0] == '.')
			continue ;
		array = joinmode_list(array, read->d_name);
	}
	return (array);
}
