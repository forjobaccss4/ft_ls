#include "ft_ls.h"

char		**remove_end_of_options(char **remove_from)
{
	int 	i;
	char	*save_string;

	save_string = NULL;
	if (!remove_from)
		return (NULL);
	if (!ft_strcmp(remove_from[0], "--"))
	{
		i = 1;
		while (remove_from[i])
		{
			save_string = joinmode_helper(save_string, remove_from[i]);
			i++;
		}
		remove_from = ft_strsplit(save_string, '\n');
		free(save_string);
		return (remove_from);
	}
	return (remove_from);
}

/*Функция просматривает список аргеменотов после опций и отбирает ошибочные их и возвращает,
если ошибочных нет возвращает NULL, если она пустая то вернется NULL*/ 
char		**find_errors_in_input(char **cleared_string_from_opts)
{
	struct 		stat buf;
	char		*save_error_input;
	char		**splited_save_error_input;
	int 		i;

	i = 0;
	if (!cleared_string_from_opts)
		return (NULL);
	save_error_input = NULL;
	while (cleared_string_from_opts[i])
	{
		if (stat(cleared_string_from_opts[i], &buf) && lstat(cleared_string_from_opts[i], &buf))
			save_error_input = joinmode_helper(save_error_input, cleared_string_from_opts[i]);
		i++;
	}
	if (!save_error_input)
		return (NULL);
	splited_save_error_input = ft_strsplit(save_error_input, '\n');
	return (splited_save_error_input);
}

char	**rem_er_helper(char **found_errors, char **dirs, char **no_err_array)
{
	int i;
	int j;
	int same_strings;
	int count;

	count = 0;
	i = -1;
	while(dirs[++i])
	{
		j = -1;
		same_strings = 0;
		while(found_errors[++j])
		{
			if (!ft_strcmp(found_errors[j], dirs[i]))
				same_strings++;
		}
		if (!same_strings)
		{
			no_err_array[count] = (char*)malloc(sizeof(char) * ft_strlen(dirs[i]) + 1);
			no_err_array[count] = dirs[i];
			count++;
		}
	}
	no_err_array[count] = 0;
	return (no_err_array);
}

char	**remove_errors(char **found_errors, char **dirs)
{
	char	**without_errors_array;

	if (!found_errors)
		return (dirs);
	if (len_d_arr(dirs) == len_d_arr(found_errors))
		return (NULL);
	without_errors_array = (char**)malloc(sizeof(char*) * \
		((len_d_arr(dirs) - len_d_arr(found_errors)) + 1));
	without_errors_array = rem_er_helper(found_errors, dirs, without_errors_array);
	return (without_errors_array);
}

/*Пишет сообщения об ошибке если файла или директории не существует*/
int		treatment_of_errors(char **string_from_term)
{
	int 	len;
	int 	i;
	char	**options;
	char	**found_err_in_input;

	options = valid_opt_or_not(find_possible_options(string_from_term));
	found_err_in_input = find_errors_in_input(\
		remove_opt_from_string_input(options, string_from_term));
	if (!found_err_in_input)
		return (0);
	len = len_d_arr(found_err_in_input);
	ft_qsort_mode(found_err_in_input, 0, len - 1);
	i = 0;
	while (i < len)
	{
		ft_putstr("ls:");
		ft_putchar(' ');
		perror(found_err_in_input[i]);
		i++;
	}
	free_double_array(found_err_in_input);
	return (1);
}



