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
