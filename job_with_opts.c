#include "ft_ls.h"

/*все опции в 1 строку, если опций нет то вернутся NULL*/
char	*opts_in_one_string(char **string_from_term)
{
	char		**options;
	char		*saved_string;
	int 		i;

	saved_string = NULL;
	if (!(options = valid_opt_or_not(find_possible_options(string_from_term))))
		return (NULL);
	i = 0;
	while (options[i])
	{
		saved_string = ft_strjoin(saved_string, options[i]);
		i++;
	}
	free_double_array(options);
	return (saved_string);
}

/*убираем с опций '-', если опций нет то вернутся NULL*/

char	*minus_from_opts(char **string_from_term)
{
	int 	i;
	int 	count;
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
	if (!(without_repeat = (char*)malloc(sizeof(char) * ft_strlen(without_minus) + 1)))
		return (NULL);
	ft_strcpy(without_repeat, without_minus);
	return (without_repeat);
}
/*Убираем дубликаты с опций (посимвольно сравнивает)*/

char	*search_for_dup(char *string_copy)
{
	int 	i;
	int 	j;
	int 	s_cp;
	char	*returned;

	if (!(returned = (char*)malloc(sizeof(char) * (ft_strlen(string_copy) + 1))))
		return (NULL);
	ft_bzero(returned, ft_strlen(string_copy) + 1);
	s_cp = -1;
	while (string_copy[++s_cp])
	{
		i = 0;
		j = 0;
		while (returned[i])
		{
			if (string_copy[s_cp] == returned[i])
				j++;
			i++;
		}
		if (j == 0)
			returned[i] = string_copy[s_cp];
	}
	return (returned);
}

/*если нет опций то NULL, если есть то их вовзвращаем ЭТО ГОТОВЫЙ ВАРИАНТ ОПЦИЙ ЕСЛИ ОНИ ЕСТЬ НО НЕ ОТСОРТИРОВАННЫЙ*/
char	**dlt_repeated_symbols_opts(char *without_minus)
{
	size_t 	i;
	char	*result;
	char	**splited_result;

	if (!without_minus)
		return (NULL);
	result = search_for_dup(without_minus);
	free(without_minus);
	if (!(splited_result = (char**)malloc(sizeof(char*) * (ft_strlen(result) + 1))))
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
