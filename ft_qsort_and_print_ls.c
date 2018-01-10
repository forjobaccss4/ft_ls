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

	tmp = NULL;
	tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
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
	size_t	i;
	int		count;

	count = 0;
	while (count < SUM_OF_FILES)
	{
		i = 0;
		while (i < MAX_LENGTH)
			ft_putchar(array[count][i++]);
		count++;
	}
}

int			*calc_rows(int calc_columns)
{
	int		*ret_cals_rows;
	int		calc;
	int		rows;

	calc = SUM_OF_FILES / calc_columns;
	rows = calc;
	ret_cals_rows = (int*)malloc(sizeof(int) * 2);
	ret_cals_rows[0] = calc_columns;
	if (calc_columns == SUM_OF_FILES)
	{
		ret_cals_rows[1] = 1;
		return(ret_cals_rows);
	}
	if ((calc * (calc_columns - 1)) > calc)
	{
		rows++;
		ret_cals_rows[1] = rows;
		return (ret_cals_rows);
	}
	else if ((calc * (calc_columns - 1)) > calc)
	{
		rows += 1;
		ret_cals_rows[1] = rows;
		return (ret_cals_rows);
	}
	return (ret_cals_rows);
}

void		swap_for_print_result(char **sorted_array, int *calc_columns_rows)
{
	char	**for_print_array;
	int		i;
	int		j;
	int		for_start_in_array;

	j = 0;
	for_start_in_array = 0;
	for_print_array = array_with_spaces();
	if (calc_columns_rows[0] == SUM_OF_FILES)
	{
		ft_print_all_words(sorted_array);
		return ;
	}
	while (for_start_in_array < calc_columns_rows[1])
	{
		i = 0;
		while ((i + for_start_in_array) < SUM_OF_FILES)
		{
			for_print_array[j] = sorted_array[i + for_start_in_array];
			i += calc_columns_rows[1];
			j++;
		}
		for_print_array[j - 1][MAX_LENGTH - 1] = '\n';
		for_start_in_array++;
	}
	ft_print_all_words(for_print_array);
}

















