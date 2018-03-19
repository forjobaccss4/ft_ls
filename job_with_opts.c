/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_with_opts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsarapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 11:10:53 by vsarapin          #+#    #+#             */
/*   Updated: 2018/03/15 11:11:02 by vsarapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*opts_in_one_string(char **string_from_term)
{
	char		**options;
	char		*saved_string;
	char		*tmp;
	int			i;

	saved_string = NULL;
	tmp = NULL;
	if (!(options = valid_opt_or_not(find_possible_options(string_from_term))))
		return (NULL);
	i = -1;
	while (options[++i])
	{
		if (saved_string)
		{
			tmp = ft_strdup(saved_string);
			free(saved_string);
		}
		saved_string = ft_strjoin(tmp, options[i]);
		if (tmp)
			free(tmp);
	}
	free_double_array(options);
	return (saved_string);
}

char	*minus_from_opts(char **string_from_term)
{
	int		i;
	int		count;
	char	without_minus[256];
	char	*opts_in_one_str;
	char	*without_repeat;

	i = 0;
	count = 0;
	if (!(opts_in_one_str = opts_in_one_string(string_from_term)))
		return (NULL);
	while (opts_in_one_str[i])
	{
		if (opts_in_one_str[i] == '-')
			i++;
		without_minus[count] = opts_in_one_str[i];
		i++;
		count++;
	}
	without_minus[count] = '\0';
	without_repeat = ft_strdup(without_minus);
	free(opts_in_one_str);
	return (without_repeat);
}

char	*search_for_dup(char *string_copy, int counter)
{
	int		i;
	int		j;
	char	*one_opt;
	char	tmp[PATH_MAX];
	char	*returned;

	one_opt = remove_l_if_one(string_copy);
	ft_bzero(tmp, ft_strlen(one_opt) + 1);
	while (one_opt[++counter])
	{
		i = -1;
		j = 0;
		while (tmp[++i])
			if (one_opt[counter] == tmp[i])
				j++;
		if (j == 0)
			tmp[i] = one_opt[counter];
	}
	returned = ft_strdup(tmp);
	free(one_opt);
	return (returned);
}

char	**dlt_repeated_symbols_opts(char *without_minus)
{
	size_t	i;
	int		s_cp;
	char	*result;
	char	**splited_result;

	if (!without_minus)
		return (NULL);
	s_cp = -1;
	result = search_for_dup(without_minus, s_cp);
	if (!(splited_result = (char**)malloc(sizeof(char*) \
		* (ft_strlen(result) + 1))))
		return (NULL);
	splited_result[ft_strlen(result)] = 0;
	i = -1;
	while (++i < ft_strlen(result))
	{
		splited_result[i] = (char*)malloc(sizeof(char) * 2);
		splited_result[i][1] = '\0';
	}
	i = -1;
	while (result[++i])
		splited_result[i][0] = result[i];
	splited_result = ft_qsort_mode(splited_result, 0, ft_strlen(result) - 1);
	free(result);
	return (splited_result);
}

char	*rem_l_end(char *opts, char final[PATH_MAX], char *new)
{
	int i;
	int j;

	j = -1;
	i = -1;
	while (opts[++j])
	{
		if (opts[j] == 'l')
			continue ;
		final[++i] = opts[j];
	}
	final[i + 1] = '\0';
	new = ft_strdup(final);
	return (new);
}
