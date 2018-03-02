#include "ft_ls.h"

void		r_swap(char **array, int i, int j)
{
	char *tmp;

	tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
	tmp = NULL;
}

char		**r_sort(char **array)
{
	int		start;
	int		end;

	start = 0;
	end = len_d_arr(array) - 1;
	while (start <= end)
	{
		r_swap(array, start, end);
		start++;
		end--;
	}
	return (array);
}
