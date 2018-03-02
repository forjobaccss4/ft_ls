#include "ft_ls.h"

int		kind_of_srt(char **opts)
{
	int	counter;
	int	kind_of_sort;

	counter = -1;
	kind_of_sort = 0;
	if (!opts)
		return (kind_of_sort);
	while (opts[++counter])
	{
		if (!ft_strcmp(opts[counter], "t"))
			kind_of_sort++;
		if (!ft_strcmp(opts[counter], "r"))
			kind_of_sort += 2;
	}
	return (kind_of_sort);
}

void	return_t_r_array(int kind_of_sort, char **content_of_dir, char *dir)
{
	long		**free_sort;

	free_sort = NULL;
	if (kind_of_sort == 1)
	{
		free_sort = time_sort(content_of_dir, \
		prepare_for_time_sort(content_of_dir, dir), 0, len_d_arr(content_of_dir) - 1);
		same_time(content_of_dir, free_sort);
		free_double_array_of_int(free_sort);
	}
	if (kind_of_sort == 2)
	{
		ft_qsort_mode(content_of_dir, 0, len_d_arr(content_of_dir) - 1);
		r_sort(content_of_dir);
	}
	if (kind_of_sort == 3)
	{
		free_sort = time_sort(content_of_dir, \
		prepare_for_time_sort(content_of_dir, dir), 0, len_d_arr(content_of_dir) - 1);
		same_time(content_of_dir, free_sort);
		free_double_array_of_int(free_sort);
		r_sort(content_of_dir);
	}
	if (kind_of_sort == 0)
		ft_qsort_mode(content_of_dir, 0, len_d_arr(content_of_dir) - 1);
}
