/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_length_and_other.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsarapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 09:56:32 by vsarapin          #+#    #+#             */
/*   Updated: 2018/01/12 09:56:45 by vsarapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				len_d_arr(char **array)
{
	int i;

	i = 0;
	if (!array)
		return (0);
	while (array[i])
		i++;
	return (i); /*HERE IS A LEAK*/
}

size_t			max_len_of_word_in_array(char **array)
{
	size_t	len;
	int		i;

	i = 0;
	len = 0;
	if (!array)
	{
		len = 1;
		return (len);
	}
	while (array[i])
	{
		if (len < ft_strlen(array[i]))
			len = ft_strlen(array[i]);
		i++;
	}
	if (!(len % 8))
		len++;
	while (len % 8)
		len++;
	return (len);
}

unsigned long	size_of_screen(void)
{
	struct ttysize	ws;
	unsigned long	line_length;

	line_length = 80;
	if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) != -1 && ws.ts_cols != 0)
		line_length = ws.ts_cols;
	return (line_length);
}

int				sum_of_files(char **array)
{
	int	count;

	count = 0;
	if (!array)
		return (count);
	while (array[count])
		count++;
	return (count);
}

int		sum_of_files_in_dir_non_all_flag(char *dir)
{
	DIR				*open;
	struct dirent	*read;
	int				counter_of_files;

	counter_of_files = 0;
	if (!(open = opendir(dir)))
		return (counter_of_files);
	while ((read = readdir(open)))
	{
		if (!ft_strcmp(read->d_name, ".") || !ft_strcmp(read->d_name, "..") \
		|| read->d_name[0] == '.')
			continue ;
		counter_of_files++;
	}
	closedir(open);
	return (counter_of_files);
}
