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

	j = ft_strlen(s1);
	i = ft_strlen(s2);
	if (!s1 || !s2 || !(s3 = (char*)malloc(sizeof(char) * (i + j + 2))))
		return (NULL);
	tmp = s3;
/*	tmp = ft_strdup(s1);
	tmp[ft_strlen(s1)] = '\n';
	tmd = ++tmp;
	tmd = ft_strdup(s2);
	tmd[ft_strlen(s2)] = '\0';*/
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

char				**arr_with_spaces(char **array)
{
	char	**final_array_with_spaces;
	int		i;
	size_t	max;
	int		sum;

	max = max_len_of_word_in_array(array);
	if (!(sum = sum_of_files(array)))
		return (NULL);
	if (!(final_array_with_spaces = (char**)malloc(sizeof(char*) * (sum + 1))))
		return (NULL);
	i = 0;
	while (i < sum)
	{
		if (!(final_array_with_spaces[i] = (char*)malloc(sizeof(char) * (max + 1))))
			return (NULL);
		i++;
	}
	final_array_with_spaces[sum] = 0;
	return (final_array_with_spaces);
}

char				**sorted_array_with_files(char **array, char **empty_array)
{
	int		i;
	size_t	x;
	size_t	max;
	int 	sum;

	i = -1;
	max = max_len_of_word_in_array(array);
	sum = sum_of_files(array);
	if (!sum)
		return (NULL);
	while (array[++i])
	{
		x = -1;
		while (++x < max)
		{
			while (x < ft_strlen(array[i]))
			{
				empty_array[i][x] = array[i][x];
				x++;
			}
			empty_array[i][x] = ' ';
		}
		empty_array[i][x] = '\0';
	}
	empty_array[i - 1][x - 1] = '\n';
	return (empty_array);
}




