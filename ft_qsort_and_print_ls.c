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

void		swap_for_print_result(char **sorted_array, int calc_columns)
{
	char	**for_print_array;
	int		i;
	int		j;
	int		count;
	int		for_start_in_array;

	i = 0;
	j = 0;
	count = 0;
	for_start_in_array = 0;
	for_print_array = array_with_spaces();
	if (calc_columns == SUM_OF_FILES)
	{
		ft_print_all_words(sorted_array);
		return ;
	}
	while (for_start_in_array < count)
	{
		while ((i + calc_columns) < SUM_OF_FILES)
		{
			for_print_array[j] = sorted_array[i];
			i += calc_columns;
			j++;
		}
		for_start_in_array++;
	}
	ft_print_all_words(for_print_array);
}

















