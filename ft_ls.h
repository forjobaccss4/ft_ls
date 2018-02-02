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
# define FLAGS(check_this_options) (check_this_options[i][j] == 'a' || check_this_options[i][j] == 'l' \
				|| check_this_options[i][j] == 'r' || check_this_options[i][j] == 'R' \
				|| check_this_options[i][j] == 't' || check_this_options[i][j] == 'u' \
				|| check_this_options[i][j] == 'f' || check_this_options[i][j] == 'g' \
				|| check_this_options[i][j] == 'd')

char			**rem_er_helper(char **found_errors, char **dirs, char **no_err_array);
char			**remove_errors(char **found_errors, char **dirs);
void			ft_print_all_files(char **array, char *dir);
void			print_result(char **sorted_array, int *calc_columns_rows, char *dir);
int				sum_of_files_in_dir_non_all_flag(char *dir);
char			**save_dir_none_flags(char *dir);
char			**sorted_array_with_files(char **empty_array, char *dir);
int				calc_in_one_line_or_string(char *dir);
int				*calc_rows_and_columns(char *dir);
char			**arr_with_spaces(char *dir);
void			print_all_in_dirs_none_opts(char **dirs, char **string_from_term);
void			cheking_variants(char **string_from_term);
char			**looking_for_files(char **without_opts);
char			**looking_for_dirs(char **without_opts);
char			*search_for_dup(char *string_copy);
char			**dlt_repeated_symbols_opts(char *without_minus);
char			*minus_from_opts(char **string_from_term);
char			*opts_in_one_string(char **string_from_term);
char			**remove_end_of_options(char **remove_from);
char			**coinc_in_double_array(char **remove_this_opts, char **remove_from);
char			**remove_opt_from_string_input(char **poss_opt, char **string_from_term);
int				treatment_of_errors(char **string_from_term);
char			**find_errors_in_input(char **cleared_string_from_opts);
void			error_mes_of_nonval_opt(char c);
char			**valid_opt_or_not(char **possible_options);
char			*joinmode_helper(char *stat_string, char *splited_saved_string_all);
int				len_d_arr(char **array);
char			**find_possible_options(char **string_from_term);
void			free_double_array(char **need_free);
size_t			max_len_of_word_in_array(char **array);
void			ft_swap_strings(char **array, int first_string, int second_string);
char			**ft_qsort_mode(char **array, int start, int end);
unsigned long	size_of_screen(void);
int				sum_of_files(char **array);
char			*ft_strjoinmode(char *s1, char *s2);
char			**split_read_array(char *from_read_func);
char			*read_names(DIR *descriptor);
int				main(int argc, char **argv);

#endif
