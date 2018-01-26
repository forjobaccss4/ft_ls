#include "ft_ls.h"
/*Ищет совпадения одного массива в другом и удаляет их*/
char		**coinc_in_double_array(char **remove_this_opts, char **remove_from)
{
	char	*return_this;
	char	**returned;
	int 	i;

	return_this = NULL;
	if (!remove_this_opts)
		return (remove_from);
	i = 0;
	while (remove_from[i] \
		&& remove_from[i][0] == '-' \
		&& remove_from[i][1] != '\0'\
		&& ft_strcmp(remove_from[i], "--"))
		i++;
	if (remove_from[i]) /*Подумать нужно ли это условие, строки не может не быть??*/
	{
		while (remove_from[i])
		{
			return_this = joinmode_helper(return_this, remove_from[i]);
			i++;
		}
		returned = ft_strsplit(return_this, '\n');
		free(return_this);
		return (returned);
	}
	return (NULL);
}

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
		free_double_array(remove_from);
		remove_from = ft_strsplit(save_string, '\n');
		free(save_string);
		return (remove_from);
	}
	return (remove_from);
}

/*Функция просматривает список агрументов и отбирает ошибочные их и возвращает,
если ошибочных нет возвращает NULL*/ 
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
		if (stat(cleared_string_from_opts[i], &buf) == -1)
			save_error_input = joinmode_helper(save_error_input, cleared_string_from_opts[i]);
		i++;
	}
	if (!save_error_input)
		return (NULL);
	splited_save_error_input = ft_strsplit(save_error_input, '\n');
	return (splited_save_error_input);
}


/*Пишет сообщения об ошибке если файла или директории не существует*/
void		treatment_of_errors(char **string_from_term)
{
	int 	len;
	int 	i;
	char	**errors;
	char	**options;
	char	**found_err_in_input;

	options = valid_opt_or_not(find_possible_options(string_from_term));
	found_err_in_input = find_errors_in_input(\
		remove_opt_from_string_input(options, string_from_term));
	if (!found_err_in_input)
		return ;
	len = ft_strlen_double_array(found_err_in_input);
	errors = ft_qsort_mode(found_err_in_input, 0, len - 1);
	i = 0;
	while (i < len)
	{
		ft_putstr("ls:");
		ft_putchar(' ');
		perror(errors[i]);
		i++;
	}
	free_double_array(errors);
}



