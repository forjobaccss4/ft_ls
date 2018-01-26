/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsarapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 11:00:33 by vsarapin          #+#    #+#             */
/*   Updated: 2018/01/15 12:31:29 by vsarapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char				**open_directory_current_or_print_error(void)
{
	DIR		*open;
	char	*read_array;
	char	**for_splitted_array;
	if (!(open = opendir(".")))
	{
		ft_putstr("ft_ls:");
		ft_putchar(' ');
		perror(".");
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


int					main(int argc, char **argv)
{
	int		i;
	char	*save_from_input;
	char	**splited_string_from_input;

	i = 1;
	argc = 0;
	save_from_input = NULL;
	while (argv[i])
	{
			save_from_input = joinmode_helper(save_from_input, argv[i]);
		i++;
	}
	if (!save_from_input || !ft_strcmp(save_from_input, "."))
	{
		swap_for_print_result(array_with_spaces_and_words(array_with_spaces()), calc_rows());
		return (0);
	}
	splited_string_from_input = ft_strsplit(save_from_input, '\n');
	repeated_symbols(splited_string_from_input);
	/*treatment_of_errors(find_errors_in_input(splited_string_from_input));*/
/*	system("leaks a.out | grep Leak: | cut -d ' ' -f 2");*/
	return (0);
}
