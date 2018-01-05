/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_swap_and_change_array.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsarapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 11:01:01 by vsarapin          #+#    #+#             */
/*   Updated: 2018/01/05 19:37:30 by vsarapin         ###   ########.fr       */
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

size_t				len_for_sorted_array(char **array)
{
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(array[0]);
	while (array[i])
	{
		if (len < ft_strlen(array[i]))
			len = ft_strlen(array[i]);
		i++;
	}
	while (len % 8)
		len++;
	return (len);
}

char				**array_with_spaces(size_t len)
{
	char	**final_array_with_spaces;
	char	*array_with_word;
	int		i;

	i = 0;
	final_array_with_spaces = NULL;
	if (!(final_array_with_spaces = (char**)malloc(sizeof(char*) \
		* (SUM_OF_FILES + 1))))
		return (NULL);
	i = 0;
	while (i < SUM_OF_FILES)
	{
		if (!(array_with_word = (char*)malloc(sizeof(char) * len)))
			return (NULL);
		final_array_with_spaces[i] = array_with_word;
		i++;
	}
	final_array_with_spaces[i] = 0;
	return (final_array_with_spaces);
}

void				print_array_with_spaces(size_t len)
{
	int		i;
	size_t	x;
	char	**from_open;
	char	**arr_with_spaces;

	i = 0;
	from_open = ft_qsort_mode(open_and_ls(), 0, SUM_OF_FILES - 1);
	arr_with_spaces = array_with_spaces(len);
	while (i < SUM_OF_FILES)
	{
		x = 0;
		while (x < len)
		{
			while (x < ft_strlen(from_open[i]))
			{
				arr_with_spaces[i][x] = from_open[i][x];
				x++;
			}
			arr_with_spaces[i][x] = ' ';
			x++;
		}
		ft_putstr(arr_with_spaces[i]);
		i++;
	}
}










