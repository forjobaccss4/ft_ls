#include "ft_ls.h"

/*Ищем директории в строке с консоли. Если она пустая, то NULL, если нет директорий, то NULL, иначе возврат директорий*/
char	**looking_for_dirs(char **without_opts)
{
	struct stat	buf;
	int			i;
	char		*save_dirs;
	char		**split_dirs;

	i = -1;
	save_dirs = NULL;
	if (!without_opts)
		return (NULL);
	while (without_opts[++i])
	{
		if (!stat(without_opts[i], &buf) && S_ISDIR(buf.st_mode))
			save_dirs = joinmode_helper(save_dirs, without_opts[i]);
	}
	if (!save_dirs)
		return (NULL);
	split_dirs = ft_strsplit(save_dirs, '\n');
	free(save_dirs);
	return (split_dirs);
}

char	**save_dir_none_flags(char *dir, int sort)
{
	DIR		*open;
	char	*read_array;
	char	**for_splitted_array;

	if (!(open = opendir(dir)))
		return (NULL);
	read_array = read_names(open);
	for_splitted_array = split_read_array(read_array);
	closedir(open);
	return_t_r_array(sort, for_splitted_array, dir);
	return (for_splitted_array);
}

char				*read_names(DIR *descriptor)
{
	struct dirent	*read;
	char			*array;

	array = NULL;
	while ((read = readdir(descriptor)))
	{
		if (!ft_strcmp(read->d_name, ".") || !ft_strcmp(read->d_name, "..") \
				|| read->d_name[0] == '.')
			continue ;
		array = joinmode_helper(array, read->d_name);
	}
	return (array);
}

char				**split_read_array(char *from_read_func)
{
	char	**splited;

	splited = NULL;
	splited = ft_strsplit(from_read_func, '\n');
	free(from_read_func);
	return (splited);
}
