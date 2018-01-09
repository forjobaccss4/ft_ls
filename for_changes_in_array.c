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

char				**array_with_spaces(void)
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
		if (!(array_with_word = (char*)malloc(sizeof(char) * MAX_LENGTH)))
			return (NULL);
		final_array_with_spaces[i] = array_with_word;
		i++;
	}
	final_array_with_spaces[SUM_OF_FILES] = 0;
	return (final_array_with_spaces);
}

char				**array_with_spaces_and_words(void)
{
	int		i;
	size_t	x;
	char	**from_open;  /*need free*/
	char	**arr_with_spaces_and_words;

	i = -1;
	from_open = ft_qsort_mode(open_and_ls(), 0, SUM_OF_FILES - 1);
	arr_with_spaces_and_words = array_with_spaces();
	while (from_open[++i])
	{
		x = 0;
		while (x < MAX_LENGTH)
		{
			while (x < ft_strlen(from_open[i]))
			{
				arr_with_spaces_and_words[i][x] = from_open[i][x];
				x++;
			}
			arr_with_spaces_and_words[i][x] = ' ';
			x++;
		}
	}
	arr_with_spaces_and_words[i - 1][x - 1] = '\n';
	return (arr_with_spaces_and_words);
}

int				calc_in_one_line_or_columns(void)
{
	unsigned long	screen_width;
	double			division;
	double			res;
	int				words_in_one_line;

	division = 2;
	res = SUM_OF_FILES;
	screen_width = size_of_screen();
	while ((MAX_LENGTH * res) > screen_width)
	{
		if (screen_width < MAX_LENGTH)
		{
			words_in_one_line = 1;
			return (words_in_one_line);
		}
		res = (SUM_OF_FILES / division);
		division++;
	}
	words_in_one_line = res;
	if ((res + 0.5) >= (words_in_one_line + 1))
		words_in_one_line += 1;
	else
		words_in_one_line = res;
	return (words_in_one_line);
}












