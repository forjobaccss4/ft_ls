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

char			*joinmode_helper(char *stat_string, char *splited_saved_string_all)
{
	char	*tmp;

	if (stat_string)
	{
		tmp = ft_strdup(stat_string);
		free(stat_string);
		stat_string = ft_strjoinmode(tmp, splited_saved_string_all);
		free(tmp);
		return (stat_string);
	}
	else
		stat_string = ft_strdup(splited_saved_string_all);
	return (stat_string);
}

char				**arr_with_spaces(char *dir)
{
	char	**final_array_with_spaces;
	int		i;
	size_t	max;
	int		sum;

	max = max_len_of_word_in_array(save_dir_none_flags(dir));
	sum = sum_of_files_in_dir_non_all_flag(dir);
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

char				**sorted_array_with_files(char **empty_array, char *dir)
{
	int		i;
	size_t	x;
	size_t	max;
	int 	sum;
	char	**from_open;

	i = -1;
	max = max_len_of_word_in_array(save_dir_none_flags(dir));
	sum = sum_of_files_in_dir_non_all_flag(dir);
	from_open = ft_qsort_mode(save_dir_none_flags(dir), 0, sum - 1);
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