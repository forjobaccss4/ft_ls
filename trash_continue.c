/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash_continue.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsarapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 11:16:16 by vsarapin          #+#    #+#             */
/*   Updated: 2018/03/15 11:16:20 by vsarapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	treatment_of_errors_help(char **found_err_in_input)
{
	int i;

	i = 0;
	while (i < len_d_arr(found_err_in_input))
	{
		if (!ft_strcmp(found_err_in_input[i], ""))
		{
			write(2, "ls: fts_open: No such file or directory\n", 41);
			exit(0);
		}
		write(2, "ls: ", 4);
		perror(found_err_in_input[i]);
		i++;
	}
}

char	**copy_d_arr(char **d_arr)
{
	int		counter;
	char	**cpy_d_arr;

	counter = -1;
	cpy_d_arr = NULL;
	if (!d_arr)
		return (NULL);
	if (!(cpy_d_arr = (char**)malloc(sizeof(char*) * (len_d_arr(d_arr) + 1))))
		return (NULL);
	cpy_d_arr[len_d_arr(d_arr)] = 0;
	while (d_arr[++counter])
		cpy_d_arr[counter] = ft_strdup(d_arr[counter]);
	return (cpy_d_arr);
}

int		files_output_hlp(char **srt, int *rows, int trig, char **opt)
{
	int	counter;

	counter = -1;
	while (opt[++counter])
	{
		if (!ft_strcmp(opt[counter], "t") && !trig)
		{
			print_files_after_errors(srt, rows);
			trig++;
		}
	}
	counter = -1;
	while (opt[++counter])
	{
		if (!ft_strcmp(opt[counter], "r") && !trig)
		{
			print_files_after_errors(srt, rows);
			trig++;
		}
	}
	return (trig);
}

int		files_with_flags_hlp_cn(char **srt, int *rows, int trig, char **opt)
{
	int			counter;

	counter = -1;
	while (opt[++counter])
	{
		if (!ft_strcmp(opt[counter], "a") && !trig)
		{
			print_files_after_errors(srt, rows);
			trig++;
		}
	}
	counter = -1;
	while (opt[++counter])
	{
		if (!ft_strcmp(opt[counter], "R") && !trig)
		{
			print_files_after_errors(srt, rows);
			trig++;
		}
	}
	return (trig);
}

void	dev_print(char *p, char **c, char *dr, char *f)
{
	for_dev_dir_major(p, c, dr);
	for_dev_dir_minor(p, c, dr);
	print_date_time(p, f);
	write(1, "\n", 1);
}
