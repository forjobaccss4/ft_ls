#include "ft_ls.h"

/*В этой функции возвращаются заданные опции, если их нет то NULL*/

char		**find_possible_options(char **string_from_term)
{
	int		i;
	char	*save_options;
	char	**splited_save_options;

	i = 0;
	save_options = NULL;
	splited_save_options = NULL;
	if (!string_from_term)
		return (NULL);
	while (string_from_term[i] \
		&& string_from_term[i][0] == '-' \
		&& string_from_term[i][1] != '\0' \
		&& ft_strcmp(string_from_term[i], "--") != 0)
	{
		save_options = joinmode_helper(save_options, string_from_term[i]);
		i++;
	}
	if (!save_options)
		return (NULL);
	splited_save_options = ft_strsplit(save_options, '\n');
	free(save_options);
	return (splited_save_options);
}

void		error_mes_of_nonval_opt(char c)
{
	ft_putstr("ls: illegal option -- ");
	ft_putchar(c);
	ft_putchar('\n');
	ft_putstr("usage: ls [-Radfgltu] [file ...]");
	ft_putchar('\n');
}
/*Принимает результат верхней функции. Функция ниже проверяет валидные ли флаги зашли если да то возвращает эти флаги в двумерном массиве
, если нет то выводит ошибку, чистит массив символов с опциями и возвращает exit(1)*/
char		**valid_opt_or_not(char **possible_options)
{
	int		i;
	int		j;

	i = 0;
	if (possible_options)
	{
		while (possible_options[i])
		{
			j = 1;
			while (possible_options[i][j])
			{
				if (FLAGS(possible_options))
					j++;
				else
				{
					error_mes_of_nonval_opt(possible_options[i][j]);
					free_double_array(possible_options);
					exit(1);
				}
			}
			i++;
		}
	}
	return (possible_options);
}

/*Ищет совпадения одного массива в другом и удаляет их. Нужно чтбоы убрать опции из строки. Если опций нет то возвращается вся строка. 
Если там только опции то тоже вернется NULL*/
char		**coinc_in_double_array(char **remove_this_opts, char **remove_from)
{
	char	*return_this;
	char	**returned;
	int 	i;

	return_this = NULL;
	if (!remove_from)
		return (NULL);
	if (!remove_this_opts)
		return (remove_from);
	i = 0;
	while (remove_from[i] && remove_from[i][0] == '-' && remove_from[i][1] != '\0'\
		&& ft_strcmp(remove_from[i], "--"))
		i++;
	if (!remove_from[i])
		return (NULL);
	while (remove_from[i])
	{
		return_this = joinmode_helper(return_this, remove_from[i]);
		i++;
	}
	returned = ft_strsplit(return_this, '\n');
	free(return_this);
	return (returned);
}

/*Убираем с строки опции чтоб потом парсить дальше и убираем -- с строки с консоли, если их нет, то  убираем -- с строки с консоли*/
char		**remove_opt_from_string_input(char **poss_opt, char **string_from_term)
{ 
	char	**saved_string_with_end_of_opt;
	char	**split_save_string;

	saved_string_with_end_of_opt = NULL;
	split_save_string = NULL;
	saved_string_with_end_of_opt = coinc_in_double_array(poss_opt, string_from_term);
	split_save_string = remove_end_of_options(saved_string_with_end_of_opt);
	return (split_save_string);
}
