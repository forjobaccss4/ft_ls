#include "ft_ls.h"

char	**looking_for_files(char **without_opts)
{
	struct stat	buf;
	int			i;
	char		*save_reg_files;
	char		**split_reg_files;

	i = 0;
	save_reg_files = NULL;
	if (!without_opts)
		return (NULL);
	while (without_opts[i])
	{
		if (!stat(without_opts[i], &buf) && S_ISREG(buf.st_mode))
			save_reg_files = joinmode_helper(save_reg_files, without_opts[i]);
		i++;
	}
	if (!save_reg_files)
		return (NULL);
	split_reg_files = ft_strsplit(save_reg_files, '\n');
	free(save_reg_files);
	return (split_reg_files);	
}

