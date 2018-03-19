/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_end.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsarapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 11:12:53 by vsarapin          #+#    #+#             */
/*   Updated: 2018/03/15 11:12:57 by vsarapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		right_distance_h_links(char **content_of_dir, char *dir)
{
	struct stat		buf;
	int				max_len_of_size;
	int				counter;
	char			*for_check_file;

	max_len_of_size = 0;
	counter = -1;
	while (content_of_dir[++counter])
	{
		for_check_file = f_path(dir, content_of_dir[counter]);
		lstat(for_check_file, &buf);
		if (max_len_of_size < ft_intlen(buf.st_nlink))
			max_len_of_size = ft_intlen(buf.st_nlink);
		free(for_check_file);
	}
	return (max_len_of_size);
}

t_lst	*l_dirs(char **no_opts_str)
{
	int			counter;
	t_lst		*save_for_split;

	save_for_split = NULL;
	counter = -1;
	if (!no_opts_str)
		return (NULL);
	while (no_opts_str[++counter])
	{
		if (!dir_or_not(no_opts_str[counter]))
			save_for_split = joinmode_list(save_for_split, \
				no_opts_str[counter]);
	}
	return (save_for_split);
}

t_lst	*l_files(char **no_opts_str)
{
	int			counter;
	t_lst		*save_for_split;

	save_for_split = NULL;
	counter = -1;
	if (!no_opts_str)
		return (NULL);
	while (no_opts_str[++counter])
	{
		if (!l_file_or_not(no_opts_str[counter]))
			save_for_split = joinmode_list(save_for_split, \
				no_opts_str[counter]);
	}
	return (save_for_split);
}

int		dir_or_not(char *no_opts_str)
{
	struct stat	buf;
	int			len;
	char		buf_read[PATH_MAX];
	char		full_path[PATH_MAX];

	if (no_opts_str[ft_strlen(no_opts_str) - 1] == '/')
	{
		ft_strncpy(full_path, no_opts_str, ft_strlen(no_opts_str) - 1);
		if (!lstat(full_path, &buf) && S_ISDIR(buf.st_mode))
			return (0);
		if (!lstat(full_path, &buf) && S_ISLNK(buf.st_mode))
		{
			len = readlink(no_opts_str, buf_read, sizeof(buf_read));
			buf_read[len] = '\0';
			if (!lstat(buf_read, &buf) && S_ISDIR(buf.st_mode))
				return (0);
		}
	}
	if (!lstat(no_opts_str, &buf) && S_ISDIR(buf.st_mode))
		return (0);
	return (1);
}

void	files_case(char **dirs, char **files, char **opts, int err)
{
	int			counter;
	static int	trigger;

	return_t_r_array(kind_of_srt(opts), files, ".");
	counter = -1;
	trigger = opts_with_files(opts, files, trigger);
	while (opts[++counter])
	{
		trigger = files_output_flags(opts, files, trigger);
		trigger = files_output_flags_cont(opts, files, trigger);
		if (dirs)
		{
			return_t_r_array(kind_of_srt(opts), dirs, ".");
			if (first_case(dirs, files, opts, err))
				sec_case(dirs, files, opts, err);
			return ;
		}
	}
	if (first_case(dirs, files, opts, err))
		sec_case(dirs, files, opts, err);
	return ;
}
