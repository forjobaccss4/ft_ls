/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsarapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 16:41:22 by vsarapin          #+#    #+#             */
/*   Updated: 2018/01/05 16:47:06 by vsarapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_swap_strings(char **array, int i, int j)
{
	char *tmp;

	tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
	tmp = NULL;
}

char		**ft_qsort_mode(char **array, int start, int end)
{
	int		i;
	int		j;
	char	*middle;


	i = start;
	j = end;
	if (end <= start)
		return (0);
	middle = array[(i + j) / 2];
	while (i <= j)
	{
		while (ft_strcmp(array[i], middle) < 0)
			i++;
		while (ft_strcmp(middle, array[j]) < 0)
			j--;
		if (i <= j)
		{
			ft_swap_strings(array, i, j);
			i++;
			j--;
		}
	}
	ft_qsort_mode(array, start, j);
	ft_qsort_mode(array, i, end);
	return (array);
}

void		ft_print_all_words(char **array)
{
	int		count;
	int		len;
	int		max;

	max = SUM_OF_FILES;
	len = MAX_LENGTH;
	count = 0;
	while (count < max)
	{
		write(1, array[count], len);
		count++;
	}
	free_double_array(array);
 }

int			*calc_rows(void)
{
	int		*ret_cals_rows;
	int		sum;
	int		rows;
	int		calc_columns;

	calc_columns = calc_in_one_line_or_columns();
	sum = SUM_OF_FILES;
	rows = sum / calc_columns;
	ret_cals_rows = (int*)malloc(sizeof(int) * 2);
	ret_cals_rows[0] = calc_columns;
	if (calc_columns == sum)
	{
		ret_cals_rows[1] = 1;
		return(ret_cals_rows);
	}
	if ((sum - (rows * (calc_columns - 1))) > rows)
	{
		rows++;
		ret_cals_rows[1] = rows;
		return (ret_cals_rows);
	}
	else
		ret_cals_rows[1] = rows;
	return (ret_cals_rows);
}

void		swap_for_print_result(char **sorted_array, int *calc_columns_rows)
{
	char	**for_print_array;
	int		i;
	int		j;
	int		for_start_in_array;
	int		sum;

	sum = SUM_OF_FILES;
	for_print_array = array_with_spaces();
	if (calc_columns_rows[0] == sum)
	{
		ft_print_all_words(sorted_array);
		return ;
	}
	j = 0;
	for_start_in_array = 0;
	while (for_start_in_array < calc_columns_rows[1])
	{
		i = 0;
		while ((i + for_start_in_array) < sum)
		{
			for_print_array[j++] = sorted_array[i + for_start_in_array];
			i += calc_columns_rows[1];
		}
		for_print_array[j - 1][MAX_LENGTH - 1] = '\n';
		for_start_in_array++;
	}
	ft_print_all_words(for_print_array);
	free(calc_columns_rows);
}

















