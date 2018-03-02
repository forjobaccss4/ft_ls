#include "ft_ls.h"

int 	right_distance_h_links(char **content_of_dir, char *dir)
{
	struct stat 	buf;
	int 			max_len_of_size;
	int 			counter;
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

char	*l_dirs(char **no_opts_str)
{
	struct stat buf;
	int 		counter;
	char		*save_for_split;

	save_for_split = NULL;
	counter = -1;
	if (!no_opts_str)
		return (NULL);
	while (no_opts_str[++counter])
	{
		if ((!stat(no_opts_str[counter], &buf) && S_ISDIR(buf.st_mode)) &&
			(!lstat(no_opts_str[counter], &buf) && !S_ISLNK(buf.st_mode)))
			save_for_split = joinmode_helper(save_for_split, no_opts_str[counter]);
		else if (!stat(no_opts_str[counter], &buf) && S_ISDIR(buf.st_mode) &&
			no_opts_str[counter][ft_strlen(no_opts_str[counter]) - 1] == '/')
				save_for_split = joinmode_helper(save_for_split, no_opts_str[counter]);
	}
	return (save_for_split);
}

char	*l_files(char **no_opts_str)
{
	struct stat buf;
	int 		counter;
	char		*save_for_split;

	save_for_split = NULL;
	counter = -1;
	if (!no_opts_str)
		return (NULL);
	while (no_opts_str[++counter])
	{
		if (!stat(no_opts_str[counter], &buf) && S_ISREG(buf.st_mode))
			save_for_split = joinmode_helper(save_for_split, no_opts_str[counter]);
		else if ((!lstat(no_opts_str[counter], &buf) && S_ISLNK(buf.st_mode) &&
			no_opts_str[counter][ft_strlen(no_opts_str[counter]) - 1] != '/'))
				save_for_split = joinmode_helper(save_for_split, no_opts_str[counter]);
	}
	return (save_for_split);
}

int 	file_or_dir(char *no_opts_str, char buf_read[PATH_MAX])
{
	struct stat	buf;
	int 		i;
	char		*full_path;

	full_path = NULL;
	i = ft_strlen(no_opts_str) + 1;
	while (no_opts_str[--i] != '/' && i > 0)
	{
		if (i == 1)
		{
			full_path = f_path("/", buf_read);
			if (!stat(full_path, &buf))
			{
				free(full_path);
				return (1);
			}
		}
	}
	if (full_path)
		free(full_path);
	return (0);
}

void	files_case(char **dirs, char **files, char **term, char **opts, int err)
{
	int 	counter;

	return_t_r_array(kind_of_srt(opts), files, ".");
	counter = -1;
	while (opts[++counter])
	{
		if (!ft_strcmp(opts[counter], "l"))
		{
			print_long_format_files(files, ".");
			if (dirs)
			{
				return_t_r_array(kind_of_srt(opts), files, ".");
				if (first_case(dirs, files, term, opts, err))
					sec_case(dirs, files, term, opts, err);
				else
					exit(0);
			}
		}
	}
	if (first_case(dirs, files, term, opts, err))
		sec_case(dirs, files, term, opts, err);
	else
		exit (0);
}





























