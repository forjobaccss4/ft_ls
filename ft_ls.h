#ifndef FT_LS
# define FT_LS
# include <dirent.h>
# include <stdlib.h>
# include <sys/ioctl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include "libft/libft.h"
# include <assert.h>
# define SUM_OF_FILES sum_of_files(open_directory_current_or_print_error())
# define MAX_LENGTH max_len_of_word_in_array(open_directory_current_or_print_error())
# define FLAGS(check_this_options) (check_this_options[i][j] == 'a' || check_this_options[i][j] == 'l' \
				|| check_this_options[i][j] == 'r' || check_this_options[i][j] == 'R' \
				|| check_this_options[i][j] == 't' || check_this_options[i][j] == 'u' \
				|| check_this_options[i][j] == 'f' || check_this_options[i][j] == 'g' \
				|| check_this_options[i][j] == 'd')

char			*repeated_symbols(char **string_from_term);
char			*opts_in_one_string(char **string_from_term);
char			**remove_end_of_options(char **remove_from);
char			**coinc_in_double_array(char **remove_this_opts, char **remove_from);
char			**remove_opt_from_string_input(char **poss_opt, char **string_from_term);
void			treatment_of_errors(char **string_from_term);
char			**find_errors_in_input(char **cleared_string_from_opts);
void			error_mes_of_nonval_opt(char c);
char			**valid_opt_or_not(char **possible_options);
char			*joinmode_helper(char *stat_string, char *splited_saved_string_all);
int				ft_strlen_double_array(char **array);
char			**find_possible_options(char **string_from_term);
void			free_double_array(char **need_free);
int				*calc_rows(void);
void			swap_for_print_result(char **sorted_array, int *calc_columns_rows);
int				calc_in_one_line_or_columns(void);
void			ft_print_all_words(char **array);
char			**array_with_spaces_and_words(char **empty_array);
size_t			max_len_of_word_in_array(char **array);
void			ft_swap_strings(char **array, int first_string, int second_string);
char			**ft_qsort_mode(char **array, int start, int end);
unsigned long	size_of_screen(void);
int				sum_of_files(char **array);
char			*ft_strjoinmode(char *s1, char *s2);
char			**split_read_array(char *from_read_func);
char			*read_names(DIR *descriptor);
char			**open_directory_current_or_print_error(void);
char			**array_with_spaces(void);
int				main(int argc, char **argv);

#endif
