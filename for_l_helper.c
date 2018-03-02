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
	ft_putstr(rights);
}

void	num_of_hard(char **cont, char *fpath, char *file, char *dir)
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
	print_size(cont, fpath, dir);
	print_date_time(fpath, file);
	write(1, "\n", 1);
}

void	print_usrid(char *file, char *dir, char **content_of_dir)
{
	struct passwd 	*usr_name;
	struct stat 	buf;
	size_t 			max_len_of_size;
	int 			counter;
	char			*for_check_file;

	counter = -1;
	for_check_file = NULL;
	while (content_of_dir[++counter])
	{
		for_check_file = f_path(dir, content_of_dir[counter]);
		lstat(for_check_file, &buf);
		usr_name = getpwuid(buf.st_uid);
		if (max_len_of_size < ft_strlen(usr_name->pw_name))
			max_len_of_size = ft_strlen(usr_name->pw_name);
		free(for_check_file);
	}
	write(1, " ", 1);
	for_check_file = f_path(dir, file);
	lstat(for_check_file, &buf);
	usr_name = getpwuid(buf.st_uid);
	ft_putstr(usr_name->pw_name);
	while (--max_len_of_size + 1 > ft_strlen(usr_name->pw_name))
		write(1, " ", 1);
	free(for_check_file);
}

void	print_group(char *file, char *dir, char **content_of_dir)
{
	struct group 	*gr_name;
	struct stat 	buf;
	int 			counter;
	size_t 			max_len_of_size;
	char			*for_check_file;

	max_len_of_size = 0;
	counter = -1;
	while (content_of_dir[++counter])
	{
		for_check_file = f_path(dir, content_of_dir[counter]);
		lstat(for_check_file, &buf);
		gr_name = getgrgid(buf.st_gid);
		if (max_len_of_size < ft_strlen(gr_name->gr_name))
			max_len_of_size = ft_strlen(gr_name->gr_name);
		free(for_check_file);
	}
	write(1, "  ", 2);
	for_check_file = f_path(dir, file);
	lstat(for_check_file, &buf);
	gr_name = getgrgid(buf.st_gid);
	ft_putstr(gr_name->gr_name);
	while (--max_len_of_size + 1 > ft_strlen(gr_name->gr_name))
		write(1, " ", 1);
	free(for_check_file);
}

void	print_size(char **content_of_dir, char *file, char *dir)
{
	struct stat 	buf;
	int 			max_len_of_size;

	max_len_of_size = right_distance(content_of_dir, dir);
	lstat(file, &buf);
	write(1, "  ", 2);
	while (max_len_of_size > ft_intlen(buf.st_size))
	{
		write(1, " ", 1);
		max_len_of_size--;
	}
	ft_putnbr(buf.st_size);
	write(1, " ", 1);
}
