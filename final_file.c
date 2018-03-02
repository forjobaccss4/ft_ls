#include "ft_ls.h"

int		first_case(char **dirs, char **files, char **term, char **opts, int err)
{
	if ((len_d_arr(dirs) == 1) && (files && files[0]))
	{
		write(1, "\n", 1);
		write(1, dirs[0], ft_strlen(dirs[0]));
		write(1, ":\n", 2);
		opts_dirs(opts, dirs);
		free_double_arrays(term, opts, dirs, files);
		return (0);
	}
	else if ((len_d_arr(dirs) > 1) && err && !files)
	{
		opts_dirs(opts, dirs);
		free_double_arrays(term, opts, dirs, files);
		return (0);
	}
	else if ((len_d_arr(dirs) > 1) && err && (files && files[0]))
	{
		write(1, "\n", 1);
		opts_dirs(opts, dirs);
		free_double_arrays(term, opts, dirs, files);
		return (0);
	}
	return (1);
}

void	sec_case(char **dirs, char **files, char **term, char **opts, int err)
{
	if ((len_d_arr(dirs) > 1) && !err && (files && files[0]))
	{
		write(1, "\n", 1);
		opts_dirs(opts, dirs);
		free_double_arrays(term, opts, dirs, files);
		exit(0);
	}
	else if ((len_d_arr(dirs) > 1) && err)
	{
		opts_dirs(opts, dirs);
		free_double_arrays(term, opts, dirs, files);
		exit(0);
	}
	else if ((len_d_arr(dirs) == 1) && err)
	{
		write(1, dirs[0], ft_strlen(dirs[0]));
		write(1, ":\n", 2);
		opts_dirs(opts, dirs);
		free_double_arrays(term, opts, dirs, files);
		exit(0);
	}
}

void	for_dev_dir(char **content, char *dir)
{
	struct stat	buf;
	char		*for_dev_check;
	char		*for_check_file;
	int			counter;

	counter = -1;
	for_dev_check = ft_strdup(dir + (ft_strlen(dir) - 4));
	if (!ft_strcmp(for_dev_check, "/dev"))
	{
		while (content[++counter])
		{
			for_check_file = f_path(dir, content[counter]);
			if (!lstat(for_check_file, &buf))
			{
				rights_print(buf.st_mode, for_check_file);
				num_of_hard_links_other(content, for_check_file, \
					content[counter], "/dev");
			}
			free(for_check_file);
		}
	}
	free(for_dev_check);
}

void	num_of_hard_links_other(char **cont, char *fpath, char *file, char *dir)
{
	struct stat buf;
	int 		max_len_of_size;

	max_len_of_size = right_distance_h_links(cont, dir);
	lstat(fpath, &buf);
	write(1, " ", 1);
	while (--max_len_of_size + 1 > ft_intlen(buf.st_nlink))
		write(1, " ", 1);
	ft_putnbr(buf.st_nlink);
	print_usrid(file, dir, cont);
	print_group(file, dir, cont);
	print_major(file, dir, cont);
	print_date_time(fpath, file);
	write(1, "\n", 1);
}

void	print_major(char *file, char *dir, char **content_of_dir)
{
	struct stat 	buf;
	int 			counter;
	char			*for_check_file;

	counter = -1;
	for_check_file = NULL;
	while (content_of_dir[++counter])
	{
		for_check_file = f_path(dir, content_of_dir[counter]);
		lstat(for_check_file, &buf);
		free(for_check_file);
	}
	write(1, " ", 1);
	for_check_file = f_path(dir, file);
	lstat(for_check_file, &buf);
	ft_putnbr(buf.st_dev);
	free(for_check_file);
}











