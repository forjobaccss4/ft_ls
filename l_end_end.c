/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_end_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsarapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 11:12:18 by vsarapin          #+#    #+#             */
/*   Updated: 2018/03/15 11:12:25 by vsarapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_long_format_files(char **content_of_dir, char *dir)
{
	struct stat buf;
	int			counter;
	char		*for_check_file;

	counter = -1;
	for_check_file = NULL;
	while (content_of_dir[++counter])
	{
		dir = (content_of_dir[counter][0] == '/') ? "/" : ".";
		for_check_file = f_path(dir, content_of_dir[counter]);
		if (!lstat(for_check_file, &buf))
		{
			rights_print(buf.st_mode, for_check_file);
			hard_links_files(content_of_dir, for_check_file, \
				content_of_dir[counter], dir);
		}
		free(for_check_file);
	}
}

void	hard_links_files(char **cont_of_dir, char *fpath, char *file, char *dir)
{
	struct stat buf;
	int			max_len_of_size;
	size_t		len_group;
	int			len_size;

	len_group = group_padding(cont_of_dir, dir);
	len_size = size_padding(cont_of_dir, dir);
	max_len_of_size = right_distance_h_links(cont_of_dir, dir);
	lstat(fpath, &buf);
	write(1, " ", 1);
	while (--max_len_of_size + 1 > ft_intlen(buf.st_nlink))
		write(1, " ", 1);
	ft_putnbr(buf.st_nlink);
	print_usrid_files(file, dir, cont_of_dir);
	print_group(file, dir, len_group);
	print_size(fpath, len_size);
	print_date_time(fpath, file);
	write(1, "\n", 1);
}

void	print_usrid_files(char *file, char *dir, char **content_of_dir)
{
	struct passwd	*usr_name;
	struct stat		buf;
	size_t			max_len_of_size;
	char			*for_check_file;

	for_check_file = NULL;
	max_len_of_size = print_usrid_helper(content_of_dir, for_check_file);
	write(1, " ", 1);
	dir = (file[0] == '/') ? "/" : ".";
	for_check_file = f_path(dir, file);
	lstat(for_check_file, &buf);
	usr_name = getpwuid(buf.st_uid);
	ft_putstr(usr_name->pw_name);
	while (--max_len_of_size + 1 > ft_strlen(usr_name->pw_name))
		write(1, " ", 1);
	free(for_check_file);
	write(1, "  ", 2);
}

int		print_usrid_helper(char **content_of_dir, char *for_check_file)
{
	struct passwd	*usr_name;
	struct stat		buf;
	size_t			max_len_of_size;
	int				counter;
	char			*dir;

	counter = -1;
	dir = NULL;
	for_check_file = NULL;
	max_len_of_size = 0;
	while (content_of_dir[++counter])
	{
		dir = (content_of_dir[counter][0] == '/') ? "/" : ".";
		for_check_file = f_path(dir, content_of_dir[counter]);
		lstat(for_check_file, &buf);
		usr_name = getpwuid(buf.st_uid);
		if (max_len_of_size < ft_strlen(usr_name->pw_name))
			max_len_of_size = ft_strlen(usr_name->pw_name);
		free(for_check_file);
	}
	return (max_len_of_size);
}
