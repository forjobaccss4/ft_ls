/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_with_files_in_arg.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsarapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 11:10:29 by vsarapin          #+#    #+#             */
/*   Updated: 2018/03/15 11:10:33 by vsarapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_print_all_array_with_files(char **files)
{
	int		count;
	size_t	len;
	int		max;

	max = len_d_arr(files);
	len = ft_strlen(files[0]);
	count = 0;
	while (count < max)
	{
		write(1, files[count], len);
		count++;
	}
	free_double_array(files);
}

void		print_files_after_errors(char **srtd_fls, int *calc_cols_rows)
{
	int		for_start_in_array;
	char	**for_print_array;

	if (calc_cols_rows[0] == len_d_arr(srtd_fls))
	{
		ft_print_all_array_with_files(srtd_fls);
		return ;
	}
	for_print_array = (char**)malloc(sizeof(char*) * (len_d_arr(srtd_fls) + 1));
	for_print_array[len_d_arr(srtd_fls)] = 0;
	for_start_in_array = -1;
	print_files_helper(srtd_fls, calc_cols_rows, for_print_array);
}

void		print_files_helper(char **srtd_fls, int *cols_rows, char **print)
{
	int i;
	int j;
	int	for_start_in_array;

	j = 0;
	for_start_in_array = -1;
	while (++for_start_in_array < cols_rows[1])
	{
		i = 0;
		while ((i + for_start_in_array) < len_d_arr(srtd_fls))
		{
			print[j++] = ft_strdup(srtd_fls[i + for_start_in_array]);
			i += cols_rows[1];
		}
		print[j - 1][max_len_of_word_in_array(srtd_fls) - 9] = '\n';
	}
	free_double_array(srtd_fls);
	ft_print_all_array_with_files(print);
}
