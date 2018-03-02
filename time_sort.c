#include "ft_ls.h"

void		ft_swap_ints(long **array, int i, int j)
{
	long *tmp;

	tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
	tmp = NULL;
}

long		**time_sort(char **array, long **time_arr, int start, int end)
{
	int		i;
	int		j;
	long	*middle;

	i = start;
	j = end;
	if (end <= start)
		return (0);
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
	return (time_arr);
}

long		**prepare_for_time_sort(char **content_of_dir, char *dir)
{
	struct stat buf;
	int 		counter;
	long		**time_arr;
	int 		size_of_arr;
	char		*for_check_file;

	counter = 0;
	size_of_arr = len_d_arr(content_of_dir);
	time_arr = (long**)malloc(sizeof(long*) * (size_of_arr + 1));
	while (counter < size_of_arr)
	{
		for_check_file = f_path(dir, content_of_dir[counter]);
		lstat(for_check_file, &buf);
		time_arr[counter] = (long*)malloc(sizeof(long) * 10);
		ft_memcpy(time_arr[counter], &buf.st_mtime, 10);
		free(for_check_file);
		counter++;
	}
	time_arr[counter] = NULL;
	return (time_arr);
}

void		same_time(char **cont_of_dir, long **time_arr)
{
	int		chr_same_time;
	int 	start;
	int 	end;
	int 	len_time_arr;


	chr_same_time = 0;
	start = 0;
	end = 0;
	len_time_arr = len_d_int_arr(time_arr);
	while (chr_same_time < len_time_arr - 1)
	{
		if (*time_arr[chr_same_time] == *time_arr[chr_same_time + 1])
		{
			start = chr_same_time;
			while ((*time_arr[start] == *time_arr[chr_same_time + 1]) &&
				(chr_same_time < len_time_arr - 2))
				chr_same_time++;
			end = chr_same_time + 1;
		}
		ft_qsort_mode(cont_of_dir, start, end);
		chr_same_time++;
	}
}
