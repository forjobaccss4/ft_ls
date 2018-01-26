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

char				*ft_strjoinmode(char *s1, char *s2)
{
	char		*s3;
	char		*tmp;
	char		*tmd;
	size_t		i;
	size_t		j;

	j = 0;
	i = 0;
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	if (!s1 || !s2 || !(s3 = (char*)malloc(sizeof(char) * (i + j + 2))))
		return (NULL);
	tmp = s3;
	while (*s1 != '\0')
		*tmp++ = *s1++;
	*tmp = '\n';
	tmd = ++tmp;
	while (*s2 != '\0')
		*tmd++ = *s2++;
	*tmd = '\0';
	return (s3);
}

char				**array_with_spaces(void)
{
	char	**final_array_with_spaces;
	int		i;
	size_t	max;
	int		sum;

	max = MAX_LENGTH;
	sum = SUM_OF_FILES;
	if (!(final_array_with_spaces = (char**)malloc(sizeof(char*) * (sum + 1))))
	{
		free(final_array_with_spaces);
		return (NULL);
	}
	i = 0;
	while (i < sum)
	{
		if (!(final_array_with_spaces[i] = (char*)malloc(sizeof(char) * (max + 1))))
		{
			free_double_array(final_array_with_spaces);
			return (NULL);
		}
		i++;
	}
	final_array_with_spaces[sum] = 0;
	return (final_array_with_spaces);
}

char				**array_with_spaces_and_words(char **empty_array)
{
	int		i;
	size_t	x;
	size_t	max;
	char	**from_open;

	i = -1;
	max = MAX_LENGTH;
	from_open = ft_qsort_mode(open_directory_current_or_print_error(), 0, SUM_OF_FILES - 1);
	while (from_open[++i])
	{
		x = 0;
		while (x < max)
		{
			while (x < ft_strlen(from_open[i]))
			{
				empty_array[i][x] = from_open[i][x];
				x++;
			}
			empty_array[i][x] = ' ';
			x++;
		}
		empty_array[i][x] = '\0';
	}
	empty_array[i - 1][x - 1] = '\n';
	free_double_array(from_open);
	return (empty_array);
}

int					calc_in_one_line_or_columns(void)
{
	size_t			res;
	double			min_cols;
	size_t			result;

	min_cols = SUM_OF_FILES / 2.00;
	result = min_cols;
	res = size_of_screen() / MAX_LENGTH;
	if ((min_cols + 0.5) >= (result + 1))
		result = result + 1;
	else
		result = min_cols;
	if (res > result)
		res = result;
	if (size_of_screen() < MAX_LENGTH)
	{
		res = 1;
		return (res);
	}
	if ((MAX_LENGTH * SUM_OF_FILES) <= size_of_screen())
		res = SUM_OF_FILES;
	return (res);
}
