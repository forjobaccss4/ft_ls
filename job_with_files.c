/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_with_files.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsarapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 11:12:39 by vsarapin          #+#    #+#             */
/*   Updated: 2018/03/15 11:12:41 by vsarapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	**looking_for_files(char **without_opts)
{
	struct stat	buf;
	int			i;
	t_lst		*save_reg_files;
	char		**split_reg_files;

	i = -1;
	save_reg_files = NULL;
	if (!without_opts)
		return (NULL);
	while (without_opts[++i])
	{
		if ((!stat(without_opts[i], &buf) && S_ISREG(buf.st_mode)) \
			|| !file_or_not(without_opts[i]))
			save_reg_files = joinmode_list(save_reg_files, without_opts[i]);
	}
	if (!save_reg_files)
		return (NULL);
	split_reg_files = splited_arr(save_reg_files);
	return (split_reg_files);
}

int		file_or_not(char *some_file)
{
	struct stat	buf;
	int			len;
	char		buf_read[PATH_MAX];

	if (!lstat(some_file, &buf) && S_ISLNK(buf.st_mode))
	{
		len = readlink(some_file, buf_read, sizeof(buf_read));
		buf_read[len] = '\0';
		if (file_or_not_helper(some_file, buf_read))
			return (1);
	}
	if (!lstat(some_file, &buf) && S_ISLNK(buf.st_mode))
	{
		len = readlink(some_file, buf_read, sizeof(buf_read));
		buf_read[len] = '\0';
		if (((!lstat(buf_read, &buf) && S_ISLNK(buf.st_mode)) &&
			(!stat(buf_read, &buf) && !S_ISDIR(buf.st_mode))) ||
			(stat(buf_read, &buf) && !S_ISDIR(buf.st_mode)))
			return (0);
	}
	return (1);
}

int		file_or_not_helper(char *some_file, char buf_read[PATH_MAX])
{
	struct stat	buf;
	int			i;
	char		*full_path;

	full_path = NULL;
	i = ft_strlen(some_file) + 1;
	while (some_file[--i] != '/' && i > 0)
	{
		if (i == 1)
		{
			full_path = f_path("/", buf_read);
			if (!stat(full_path, &buf))
			{
				free(full_path);
				return (1);
			}
		}
	}
	if (full_path)
		free(full_path);
	return (0);
}

int		l_file_or_not(char *no_opts_str)
{
	struct stat	buf;
	int			len;
	char		buf_read[PATH_MAX];
	char		full_path[PATH_MAX];

	if (no_opts_str[ft_strlen(no_opts_str) - 1] == '/')
	{
		ft_strncpy(full_path, no_opts_str, ft_strlen(no_opts_str) - 2);
		if (!lstat(full_path, &buf) && S_ISLNK(buf.st_mode))
		{
			len = readlink(no_opts_str, buf_read, sizeof(buf_read));
			buf_read[len] = '\0';
			if (!lstat(buf_read, &buf) && S_ISLNK(buf.st_mode))
				return (0);
			else if (!lstat(buf_read, &buf) && S_ISREG(buf.st_mode))
				return (0);
		}
	}
	if (!lstat(no_opts_str, &buf) && S_ISREG(buf.st_mode))
		return (0);
	if (!lstat(no_opts_str, &buf) && S_ISLNK(buf.st_mode))
		return (0);
	return (1);
}
