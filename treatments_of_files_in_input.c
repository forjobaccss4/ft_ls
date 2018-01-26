#include "ft_ls.h"

/*все опции в 1 строку*/
char	*opts_in_one_string(char **string_from_term)
{
	char		**options;
	char		*saved_string;
	int 		i;

	treatment_of_errors(string_from_term);
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

/*убираем с опций повторения и '-'*/

char	*repeated_symbols(char **string_from_term)
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
		without_minus[count] =  opts_in_one_str[i];
		i++;
		count++;
	}
	without_repeat = (char*)malloc(sizeof(char) * ft_stlrlen(without_minus) + 1);
	without_repeat = without_minus[0];
/*	while (*without_minus)
	{
		i = 0;
		while (without_repeat[i])
		{
			if (*without_minus == without_repeat[i])
				i++;
			else
				without_repeat
		}
	}*/
	return (NULL);
}