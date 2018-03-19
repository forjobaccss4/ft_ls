/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_l_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsarapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 11:09:54 by vsarapin          #+#    #+#             */
/*   Updated: 2018/03/15 11:09:58 by vsarapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	rights_print(int mode, char *fullpath)
{
	char	rights[12];

	rights[0] = file_type(mode);
	rights[1] = (S_IRUSR & mode) ? 'r' : '-';
	rights[2] = (S_IWUSR & mode) ? 'w' : '-';
	rights[3] = (S_IXUSR & mode) ? 'x' : '-';
	rights[4] = (S_IRGRP & mode) ? 'r' : '-';
	rights[5] = (S_IWGRP & mode) ? 'w' : '-';
	rights[6] = (S_IXGRP & mode) ? 'x' : '-';
	rights[7] = (S_IROTH & mode) ? 'r' : '-';
	rights[8] = (S_IWOTH & mode) ? 'w' : '-';
	rights[9] = (S_IXOTH & mode) ? 'x' : '-';
	rights[10] = (extend_or_acl(fullpath));
	rights[11] = '\0';
	if (S_ISUID & mode)
		rights[3] = rights[3] == '-' ? 'S' : 's';
	if (S_ISGID & mode)
		rights[6] = rights[6] == '-' ? 'S' : 's';
	if (S_ISVTX & mode)
		rights[9] = rights[9] == '-' ? 'T' : 't';
	write(1, rights, 11);
}

void	num_of_hard(char **c, char *f, char *dr, int *idgrs)
{
	struct stat buf;
	char		*p;

	p = f_path(dr, f);
	lstat(p, &buf);
	write(1, "                    ", (idgrs[3] - ft_intlen(buf.st_nlink) + 1));
	ft_putnbr(buf.st_nlink);
	print_usrid(f, dr, idgrs[0]);
	print_group(f, dr, idgrs[1]);
	if (S_ISBLK(buf.st_mode) || S_ISCHR(buf.st_mode))
	{
		dev_print(p, c, dr, f);
		free(p);
		return ;
	}
	print_size(p, idgrs[2]);
	print_date_time(p, f);
	write(1, "\n", 1);
	free(p);
}

void	print_usrid(char *file, char *dir, int pad)
{
	struct passwd	*usr_name;
	struct stat		buf;
	char			*for_check_file;

	write(1, " ", 1);
	for_check_file = f_path(dir, file);
	lstat(for_check_file, &buf);
	usr_name = getpwuid(buf.st_uid);
	write(1, usr_name->pw_name, ft_strlen(usr_name->pw_name));
	write(1, "                    ", (pad - ft_strlen(usr_name->pw_name) + 2));
	free(for_check_file);
}

void	print_group(char *file, char *dir, int pad)
{
	struct group	*gr_name;
	struct stat		buf;
	char			*for_check_file;

	for_check_file = f_path(dir, file);
	lstat(for_check_file, &buf);
	gr_name = getgrgid(buf.st_gid);
	write(1, gr_name->gr_name, ft_strlen(gr_name->gr_name));
	write(1, "                    ", (pad - ft_strlen(gr_name->gr_name)));
	free(for_check_file);
}

void	print_size(char *file, int pad)
{
	struct stat	buf;

	write(1, "  ", 2);
	lstat(file, &buf);
	write(1, "                    ", (pad - ft_intlen(buf.st_size)));
	ft_putnbr(buf.st_size);
	write(1, " ", 1);
}
