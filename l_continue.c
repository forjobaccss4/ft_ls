/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_continue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsarapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 11:11:59 by vsarapin          #+#    #+#             */
/*   Updated: 2018/03/15 11:12:03 by vsarapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_date_time(char *fullpath, char *file)
{
	struct stat buf;
	char		my_time[13];
	char		*ttime;

	lstat(fullpath, &buf);
	ttime = ctime(&buf.st_mtime) + 4;
	if ((((time(NULL) - buf.st_mtime) < 15778800) &&
		(time(NULL) - buf.st_mtime) >= 0) ||
		((time(NULL) - buf.st_mtime) > -15778800 &&
		(time(NULL) - buf.st_mtime) <= 0))
	{
		ft_strncpy(my_time, ttime, 12);
		my_time[12] = '\0';
		ft_putstr(my_time);
		write(1, " ", 1);
		if (print_symbol_link(fullpath, file))
			return ;
		ft_putstr(file);
		return ;
	}
	else
		print_date_more_six_months(fullpath, file, my_time);
}

void	print_date_more_six_months(char *fullpath, char *file, char my_time[13])
{
	struct stat buf;
	char		*ttime;

	lstat(fullpath, &buf);
	ttime = ctime(&buf.st_mtime) + 4;
	lstat(fullpath, &buf);
	ft_strncpy(my_time, ttime, 7);
	my_time[7] = '\0';
	ft_putstr(my_time);
	ttime = ft_strdup(ctime(&buf.st_mtime) \
		+ ft_strlen(ctime(&buf.st_mtime)) - 6);
	if (ttime[0] == ' ')
		write(1, ttime, ft_strlen(ttime) - 1);
	else
	{
		write(1, " ", 1);
		write(1, ttime, ft_strlen(ttime) - 1);
	}
	free(ttime);
	write(1, " ", 1);
	if (print_symbol_link(fullpath, file))
		return ;
	ft_putstr(file);
}

int		print_symbol_link(char *fullpath, char *file)
{
	struct stat buf;
	int			end_of_str;
	char		buf_read[PATH_MAX];

	if (!lstat(fullpath, &buf) && S_ISLNK(buf.st_mode))
	{
		end_of_str = readlink(fullpath, buf_read, sizeof(buf_read));
		buf_read[end_of_str] = '\0';
		write(1, file, ft_strlen(file));
		write(1, " -> ", 4);
		write(1, buf_read, ft_strlen(buf_read));
		return (1);
	}
	return (0);
}

int		l_in_right_way(char **content_of_dir, char *dir)
{
	int			total;
	int			counter;
	char		*for_check_file;
	struct stat buf;

	counter = -1;
	total = 0;
	if (!content_of_dir || !content_of_dir[0])
	{
		ft_print_all_files_helper(dir);
		return (1);
	}
	while (content_of_dir[++counter])
	{
		for_check_file = f_path(dir, content_of_dir[counter]);
		if (!lstat(for_check_file, &buf))
			total += buf.st_blocks;
		free(for_check_file);
	}
	write(1, "total ", 6);
	ft_putnbr(total);
	write(1, "\n", 1);
	return (0);
}
