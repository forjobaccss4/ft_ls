/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsarapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 11:00:33 by vsarapin          #+#    #+#             */
/*   Updated: 2018/01/05 18:23:10 by vsarapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char				**open_directory(void)
{
	DIR		*open;
	char	*read_array;
	char	**for_splitted_array;

	if (!(open = opendir(".")))
	{
		perror("Error opening directory");
		exit(1);
	}
	read_array = read_names(open);
	for_splitted_array = split_read_array(read_array);
	closedir(open);
	return (for_splitted_array);
}

char				*read_names(DIR *descriptor)
{
	struct dirent	*read;
	char			*array;
	char			*tmp;

	while ((read = readdir(descriptor)))
	{
		if (!ft_strcmp(read->d_name, ".") || !ft_strcmp(read->d_name, "..") \
		|| read->d_name[0] == '.')
			continue ;
		if (array)
		{
			tmp = array;
			free(array);
			array = ft_strjoinmode(tmp, read->d_name);
			tmp = NULL;
		}
		else
			array = ft_strdup(read->d_name);
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


int					main(int argc, char **argv)
{
/*	char **array;*/
	argc = 0;
	argv = NULL;
		swap_for_print_result(array_with_spaces_and_words(array_with_spaces()), \
		 calc_rows());
/*		array = array_with_spaces(); */
	system("leaks a.out | grep Leak: | cut -d ' ' -f 2");
	return (0);
}
