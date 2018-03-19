/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsarapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 11:16:28 by vsarapin          #+#    #+#             */
/*   Updated: 2018/03/15 11:16:33 by vsarapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_swap_ints(long **array, int i, int j)
{
	long *tmp;

	tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
	tmp = NULL;
}

void		time_sort(char **array, long **time_arr, int start, int end)
{
	int		i;
	int		j;
	long	*middle;

	i = start;
	j = end;
	if (end <= start)
		return ;
	middle = time_arr[(i + j) / 2];
	while (i <= j)
	{
		while (*time_arr[i] > *middle)
			i++;
		while (*time_arr[j] < *middle)
			j--;
		if (i <= j)
		{
			ft_swap_strings(array, i, j);
			ft_swap_ints(time_arr, i, j);
			i++;
			j--;
		}
	}
	time_sort(array, time_arr, start, j);
	time_sort(array, time_arr, i, end);
}

long		**prepare_for_time_sort(char **content_of_dir, char *dir)
{
	struct stat buf;
	int			counter;
	long		**time_arr;
	int			size_of_arr;
	char		*for_check_file;

	counter = 0;
	size_of_arr = len_d_arr(content_of_dir);
	time_arr = (long**)malloc(sizeof(long*) * (size_of_arr + 1));
	while (counter < size_of_arr)
	{
		for_check_file = f_path(dir, content_of_dir[counter]);
		lstat(for_check_file, &buf);
		time_arr[counter] = (long*)malloc(sizeof(long) * 11);
		ft_memcpy(time_arr[counter], &buf.st_mtime, 10);
		time_arr[counter][10] = '\0';
		free(for_check_file);
		counter++;
	}
	time_arr[counter] = NULL;
	return (time_arr);
}

void		same_time(char **cont_of_dir, long **time_arr)
{
	int		len_time_arr;
	int		*arr;

	arr = (int*)malloc(sizeof(int) * 4);
	arr[0] = -1;
	arr[1] = 0;
	arr[2] = 0;
	arr[3] = 0;
	len_time_arr = len_d_arr(cont_of_dir);
	for_break(arr, len_time_arr, time_arr, cont_of_dir);
	free(arr);
}

void		for_break(int *arr, int len, long **t, char **c)
{
	while (1)
	{
		arr[3] = arr[2];
		while ((++arr[0] < len - 1) && (arr[0] + 1 < len - 1))
		{
			if (*t[arr[0]] == *t[arr[0] + 1])
			{
				arr[1] = arr[0];
				break ;
			}
		}
		arr[0] = arr[1];
		while (arr[0] < len - 1)
		{
			while (*t[arr[0]] == *t[arr[0] + 1] \
				&& (arr[0] + 1 < len - 1))
				arr[0]++;
			arr[2] = ((arr[0] == len - 2) && *t[len - 1] == *t[len - 2]) ? \
			arr[0] + 1 : arr[0];
			break ;
		}
		ft_qsort_mode(c, arr[1], arr[2]);
		if (arr[3] == arr[2])
			return ;
	}
}
