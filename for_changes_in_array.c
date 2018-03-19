/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_swap_and_change_array.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsarapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 11:01:01 by vsarapin          #+#    #+#             */
/*   Updated: 2018/01/15 12:35:09 by vsarapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	**sorted_array_with_files(char **array)
{
	int		i;
	size_t	x;
	size_t	max;
	char	returned[PATH_MAX];
	char	**empty_array;

	i = -1;
	max = max_len_of_word_in_array(array);
	if (!sum_of_files(array))
		return (NULL);
	empty_array = (char**)malloc(sizeof(char*) * (sum_of_files(array) + 1));
	empty_array[sum_of_files(array)] = 0;
	while (array[++i])
	{
		x = (ft_strlen(array[i]) - 1);
		ft_strcpy(returned, array[i]);
		while (++x < max)
			returned[x] = ' ';
		returned[x] = '\0';
		empty_array[i] = ft_strdup(returned);
		ft_bzero(returned, ft_strlen(returned));
	}
	empty_array[i - 1][x - 1] = '\n';
	return (empty_array);
}
