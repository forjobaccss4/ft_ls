/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paddings_l.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsarapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 11:13:08 by vsarapin          #+#    #+#             */
/*   Updated: 2018/03/15 11:13:11 by vsarapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		usrid_padding(char **content_of_dir, char *dir)
{
	struct passwd	*usr_name;
	struct stat		buf;
	size_t			len_usrid;
	int				counter;
	char			*for_check_file;

	counter = -1;
	len_usrid = 0;
	for_check_file = NULL;
	while (content_of_dir[++counter])
	{
		for_check_file = f_path(dir, content_of_dir[counter]);
		if (lstat(for_check_file, &buf))
		{
			free(for_check_file);
			continue ;
		}
		lstat(for_check_file, &buf);
		usr_name = getpwuid(buf.st_uid);
		if (len_usrid < ft_strlen(usr_name->pw_name))
			len_usrid = ft_strlen(usr_name->pw_name);
		free(for_check_file);
	}
	return (len_usrid);
}

int		group_padding(char **content_of_dir, char *dir)
{
	struct group	*gr_name;
	struct stat		buf;
	int				counter;
	size_t			len_group;
	char			*for_check_file;

	len_group = 0;
	counter = -1;
	while (content_of_dir[++counter])
	{
		for_check_file = f_path(dir, content_of_dir[counter]);
		lstat(for_check_file, &buf);
		gr_name = getgrgid(buf.st_gid);
		if (len_group < ft_strlen(gr_name->gr_name))
			len_group = ft_strlen(gr_name->gr_name);
		free(for_check_file);
	}
	return (len_group);
}

int		size_padding(char **content_of_dir, char *dir)
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
		if (max_len_of_size < ft_intlen(buf.st_size))
			max_len_of_size = ft_intlen(buf.st_size);
		free(for_check_file);
	}
	return (max_len_of_size);
}
