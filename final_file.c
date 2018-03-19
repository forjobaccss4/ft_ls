/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsarapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 11:09:38 by vsarapin          #+#    #+#             */
/*   Updated: 2018/03/15 11:09:44 by vsarapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		first_case(char **dirs, char **files, char **opts, int err)
{
	if ((len_d_arr(dirs) == 1) && (files && files[0]) && !err)
	{
		write(1, "\n", 1);
		write(1, dirs[0], ft_strlen(dirs[0]));
		write(1, ":\n", 2);
		opts_dirs(opts, dirs, err);
		return (0);
	}
	else if ((len_d_arr(dirs) > 1) && err && !files)
	{
		opts_dirs(opts, dirs, err);
		return (0);
	}
	else if ((len_d_arr(dirs) > 1) && err && (files && files[0]))
	{
		write(1, "\n", 1);
		opts_dirs(opts, dirs, err);
		return (0);
	}
	return (1);
}

void	sec_case(char **dirs, char **files, char **opts, int err)
{
	if ((len_d_arr(dirs) > 1) && !err && (files && files[0]))
	{
		write(1, "\n", 1);
		opts_dirs(opts, dirs, err);
		return ;
	}
	else if ((len_d_arr(dirs) > 1) && err)
	{
		opts_dirs(opts, dirs, err);
		return ;
	}
	else if ((len_d_arr(dirs) == 1) && err)
	{
		write(1, "\n", 1);
		opts_dirs(opts, dirs, err);
		return ;
	}
}

void	for_dev_dir_major(char *fullpath, char **content_of_dir, char *dir)
{
	struct stat	buf;
	int			len;
	int			counter;
	char		*for_check_file;

	len = 0;
	counter = -1;
	while (content_of_dir[++counter])
	{
		for_check_file = f_path(dir, content_of_dir[counter]);
		lstat(for_check_file, &buf);
		if (len < ft_intlen(buf.st_rdev >> 24 & 0xff))
			len = ft_intlen(buf.st_rdev >> 24 & 0xff);
		free(for_check_file);
	}
	lstat(fullpath, &buf);
	write(1, "   ", 3);
	write(1, "                    ", \
		(len - ft_intlen(buf.st_rdev >> 24 & 0xff)));
	ft_putnbr(buf.st_rdev >> 24 & 0xff);
	write(1, ",", 1);
}

void	for_dev_dir_minor(char *fullpath, char **content_of_dir, char *dir)
{
	struct stat	buf;
	int			len;
	int			counter;
	char		*for_check_file;

	len = 0;
	counter = -1;
	while (content_of_dir[++counter])
	{
		for_check_file = f_path(dir, content_of_dir[counter]);
		lstat(for_check_file, &buf);
		if (len < ft_intlen(buf.st_rdev & 0xffffff))
			len = ft_intlen(buf.st_rdev & 0xffffff);
		free(for_check_file);
	}
	lstat(fullpath, &buf);
	write(1, "                    ", (len - ft_intlen(buf.st_rdev & 0xffffff)));
	ft_putnbr(buf.st_rdev & 0xffffff);
	write(1, " ", 1);
}

char	*remove_l_if_one(char *opts_str)
{
	size_t	i;
	char	final_opts_str[PATH_MAX];
	char	*new_opts;

	i = ft_strlen(opts_str);
	new_opts = NULL;
	while (opts_str[--i] && (i > 0))
	{
		if (opts_str[i] == '1')
		{
			new_opts = rem_l_end(opts_str, final_opts_str, new_opts);
			free(opts_str);
			return (new_opts);
		}
		if (opts_str[i] == 'l')
			break ;
	}
	return (opts_str);
}
