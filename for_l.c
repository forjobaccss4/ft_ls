#include "ft_ls.h"

void	print_l_opt(char **cont, char *dir, int trigger, int sort)
{
	return_t_r_array(sort, cont, dir);
	print_l_opt_trig(cont, dir, trigger);
	free_double_array(cont);
}

void	print_l_opt_trig(char **cont, char *dir, int trig)
{
	if (!trig)
	{
		l_in_right_way(cont, dir);
		print_long_format(cont, dir);
	}
	if (trig)
	{
		write(1, "\n", 1);
		write(1, dir, ft_strlen(dir));
		write(1, ":\n", 2);
		l_in_right_way(cont, dir);
		if (cont)
			print_long_format(cont, dir);
		else
			return ;
	}
}

void	print_long_format(char **cont, char *dir)
{
	struct stat buf;
	int 		counter;
	char		*for_check_file;

	counter = -1;
	for_check_file = NULL;
	for_dev_dir(cont, dir);
	while (cont[++counter])
	{
		for_check_file = f_path(dir, cont[counter]);
		if (!lstat(for_check_file, &buf))
		{
			rights_print(buf.st_mode, for_check_file);
			num_of_hard(cont, for_check_file, \
				cont[counter], dir);
		}
		free(for_check_file);
	}
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
	char 	buf[101];
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


