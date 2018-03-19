/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_rec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsarapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 11:09:22 by vsarapin          #+#    #+#             */
/*   Updated: 2018/03/15 11:10:50 by vsarapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		*dirwalk(char *path, char **opts, int kind_of_sort)
{
	char		**returned_arr;

	returned_arr = NULL;
	free_double_array(returned_arr);
	if ((len_d_arr(opts) >= 1 && !ft_strcmp(opts[0], "a")) \
		|| (len_d_arr(opts) >= 2 && !ft_strcmp(opts[1], "a"))  \
		|| (len_d_arr(opts) >= 3 && !ft_strcmp(opts[2], "a")))
		returned_arr = for_a_arr(path, kind_of_sort);
	else
		returned_arr = save_dir_none_flags(path, kind_of_sort);
	if ((returned_arr && !returned_arr[0]) || !returned_arr)
	{
		make_other_flags(path, opts, kind_of_sort);
		return (path);
	}
	return_t_r_array(kind_of_sort, returned_arr, path);
	make_other_flags(path, opts, kind_of_sort);
	find_dirs(returned_arr, path, opts, kind_of_sort);
	free_double_array(returned_arr);
	return (NULL);
}

char		*f_path(char *path, char *d_name)
{
	char		fpath[PATH_MAX];
	char		*returned;

	ft_strcpy(fpath, path);
	if (fpath[ft_strlen(path + 1)] != '/')
	{
		fpath[ft_strlen(path)] = '/';
	}
	fpath[ft_strlen(path) + 1] = '\0';
	ft_strcat(fpath, d_name);
	returned = ft_strdup(fpath);
	return (returned);
}

char		*f_path_for_r(char *path, char *d_name)
{
	char		fpath[PATH_MAX];
	char		*returned;

	ft_strcpy(fpath, path);
	fpath[ft_strlen(path)] = '/';
	fpath[ft_strlen(path) + 1] = '\0';
	ft_strcat(fpath, d_name);
	returned = ft_strdup(fpath);
	return (returned);
}

void		find_dirs(char **opn_arr, char *path, char **opts, int srt)
{
	char		*fullpath;
	struct stat sb;
	char		*buf_read;
	int			i;

	i = -1;
	while (opn_arr[++i])
	{
		if (!ft_strcmp(opn_arr[i], ".") || !ft_strcmp(opn_arr[i], ".."))
			continue ;
		fullpath = f_path_for_r(path, opn_arr[i]);
		buf_read = (char*)malloc(sizeof(char) * (ft_strlen(fullpath)));
		if ((stat(fullpath, &sb) == -1) || (!lstat(fullpath, &sb) &&
			readlink(fullpath, buf_read, ft_strlen(fullpath)) > 0))
		{
			free(buf_read);
			free(fullpath);
			continue ;
		}
		free(buf_read);
		if (S_ISDIR(sb.st_mode))
			dirwalk(fullpath, opts, srt);
		free(fullpath);
	}
}
