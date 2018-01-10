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

unsigned long		size_of_screen(void)
{
	struct ttysize	ws;
	unsigned long	line_length;

	line_length = 80;
	if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) != -1 && ws.ts_cols != 0)
		line_length = ws.ts_cols;
	return (line_length);
}

int					num_of_files(char **array)
{
	int	count;

	count = 0;
	while (array[count])
		count++;
	return (count);
}

char				**read_names(DIR *descriptor)
{
	struct dirent	*read;
	char			*array;
	char			*tmp;
	char			**res;

	array = NULL;
	while ((read = readdir(descriptor)))
	{
		if (!ft_strcmp(read->d_name, ".") || !ft_strcmp(read->d_name, "..") \
		|| read->d_name[0] == '.')
			continue ;
		if (array)
		{
			tmp = array;
			array = ft_strjoinmode(tmp, read->d_name);
			free(tmp);
			tmp = NULL;
		}
		else
			array = ft_strdup(read->d_name);
	}
	res = ft_strsplit(array, '\n');
	free(array);
	return (res);
}

char				**open_and_ls(void)
{
	DIR		*open;
	char	**array;

	if (!(open = opendir(".")))
	{
		perror("Error opening directory");
		exit(1);
	}
	array = read_names(open);
	closedir(open);
	return (array);
}

int					main(int argc, char **argv)
{
	argc = 0;
	int *array;
	int i;
	if (!argv[1])
	{
		i = calc_in_one_line_or_columns();
		array = calc_rows(i);
		swap_for_print_result(array_with_spaces_and_words(), array);
	}
/*	system("leaks a.out");*/
	return (0);
}
