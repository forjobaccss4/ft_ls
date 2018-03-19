/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_l.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsarapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 11:07:39 by vsarapin          #+#    #+#             */
/*   Updated: 2018/03/15 11:07:42 by vsarapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_l_opt(char **cont, char *dir, int trigger, int sort)
{
	return_t_r_array(sort, cont, dir);
	print_l_opt_trig(cont, dir, trigger);
	free_double_array(cont);
}

void	print_l_opt_trig(char **cont, char *dir, int trig)
{
	int	counter;
	int	*need_for_norms;

	counter = -1;
	need_for_norms = (int*)malloc(sizeof(int) * ((len_d_arr(cont) * 3) + 4));
	if (!trig)
	{
		l_in_right_way(cont, dir);
		print_long_format(cont, dir, counter, need_for_norms);
	}
	if (trig)
	{
		write(1, "\n", 1);
		write(1, dir, ft_strlen(dir));
		write(1, ":\n", 2);
		l_in_right_way(cont, dir);
		if (cont)
			print_long_format(cont, dir, counter, need_for_norms);
		else
			return ;
	}
}

void	print_long_format(char **cont, char *dir, int counter, int *idgrs)
{
	struct stat	buf;
	char		*for_check_file;

	if (!cont)
		return ;
	idgrs[0] = usrid_padding(cont, dir);
	idgrs[1] = group_padding(cont, dir);
	idgrs[2] = size_padding(cont, dir);
	idgrs[3] = right_distance_h_links(cont, dir);
	for_check_file = NULL;
	while (cont[++counter])
	{
		for_check_file = f_path(dir, cont[counter]);
		if (!lstat(for_check_file, &buf))
		{
			rights_print(buf.st_mode, for_check_file);
			num_of_hard(cont, cont[counter], dir, idgrs);
		}
		free(for_check_file);
	}
	free(idgrs);
}

char	file_type(int mode)
{
	if (S_ISREG(mode))
		return ('-');
	else if (S_ISDIR(mode))
		return ('d');
	else if (S_ISLNK(mode))
		return ('l');
	else if (S_ISBLK(mode))
		return ('b');
	else if (S_ISCHR(mode))
		return ('c');
	else if (S_ISSOCK(mode))
		return ('s');
	else if (S_ISFIFO(mode))
		return ('p');
	else
		return ('-');
}

char	extend_or_acl(char *fullpath)
{
	char	buf[101];
	acl_t	tmp;

	if (listxattr(fullpath, buf, sizeof(buf), XATTR_NOFOLLOW) > 0)
		return ('@');
	if ((tmp = acl_get_link_np(fullpath, ACL_TYPE_EXTENDED)))
	{
		acl_free(tmp);
		return ('+');
	}
	return (' ');
}
