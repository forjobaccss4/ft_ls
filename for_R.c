#include "ft_ls.h"

void		*dirwalk(char *path, char **opts, int kind_of_sort)
{
	char		**returned_arr;

	returned_arr = NULL;
	if (returned_arr)
		free_double_array(returned_arr);
	if (!(returned_arr = save_dir_none_flags(path, kind_of_sort)))
	{
		make_other_flags(path, opts, kind_of_sort);
		return (path);
	}
	return_t_r_array(kind_of_sort, returned_arr, path);
	make_other_flags(path, opts, kind_of_sort);
	find_dirs(returned_arr, path, opts, kind_of_sort);
	free_double_array(returned_arr);
	return (NULL);
}

char	*f_path(char *path, char *d_name)
{
	char		*fpath;

	if (!(fpath = (char*)malloc(sizeof(char) * \
		(ft_strlen(path) + ft_strlen(d_name) + 2))))
		return (NULL);
	ft_strcpy(fpath, path);
	if (fpath[ft_strlen(path + 1)] != '/')
		fpath[ft_strlen(path)] = '/';
	fpath[ft_strlen(path) +  1] = '\0';
	ft_strcat(fpath, d_name);
	return (fpath);
}

void		find_dirs(char **opened_array, char *path, char **opts, int kind_of_srt)
{
	char		*fullpath;
	struct 		stat sb;
	char		*buf_read;
	int			i;

	i = -1;
	while (opened_array[++i])
	{
		if (opened_array[i][0] == '.') 
			continue ;
		fullpath = f_path(path, opened_array[i]);
		buf_read = (char*)malloc(sizeof(char) * (ft_strlen(fullpath)));
		if ((stat(fullpath, &sb) == -1) || (!lstat(fullpath, &sb) && 
			readlink(fullpath, buf_read, ft_strlen(fullpath)) > 0))
		{
			free(buf_read);
			continue ;
		}
		free(buf_read);
		if (S_ISDIR(sb.st_mode)) 
		{
			dirwalk(fullpath, opts, kind_of_srt);
			free(fullpath);
		}
	}
}
