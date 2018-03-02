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
# include <sys/param.h>
# include "libft/libft.h"
# include <assert.h>
# include <time.h>
# include <sys/xattr.h>
# include <sys/acl.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>
# define FLAGS(check_this_options) (check_this_options[i][j] == 'a' || check_this_options[i][j] == 'l' \
				|| check_this_options[i][j] == 'r' || check_this_options[i][j] == 'R' \
				|| check_this_options[i][j] == 't' || check_this_options[i][j] == 'u' \
				|| check_this_options[i][j] == 'f' || check_this_options[i][j] == 'g' \
				|| check_this_options[i][j] == 'd')

void			print_major(char *file, char *dir, char **content_of_dir);
void			num_of_hard_links_other(char **cont, char *fpath, char *file, char *dir);
void			for_dev_dir(char **content, char *dir);
int				first_case(char **dirs, char **files, char **term, char **opts, int err);
void			sec_case(char **dirs, char **files, char **term, char **opts, int err);
void			hard_links_files(char **cont_of_dir, char *fpath, char *file, char *dir);
void			print_usrid_files(char *file, char *dir, char **content_of_dir);
int				print_usrid_helper(char **content_of_dir, char *for_check_file);
void			print_long_format_files(char **content_of_dir, char *dir);
void			files_case(char **dirs, char **files, char **term, char **opts, int err);
void			no_opts(char **dirs, char **files, char **term, char **opts, int errors);
void			all_cases(char **opts, char **drs, char **fls, char **term, int err);
int 			for_l_case(char **opts, char **no_opts_string, int err, char **term);
int 			file_or_dir(char *no_opts_str, char buf_read[PATH_MAX]);
char			*l_dirs(char **no_opts_str);
char			*l_files(char **no_opts_str);
int 			file_or_not_helper(char *some_file, char buf_read[PATH_MAX]);
int 			right_distance_h_links(char **content_of_dir, char *dir);
int 			right_distance(char **content_of_dir, char *dir);
void			opts_dirs(char **opts, char **dirs);
void			r_swap(char **array, int i, int j);
char			**r_sort(char **array);
int				file_or_not(char *some_file);
int				kind_of_srt(char **opts);
void			return_t_r_array(int kind_of_sort, char **content_of_dir, char *dir);
void			same_time(char **cont_of_dir, long **time_arr);
void			ft_swap_ints(long **array, int i, int j);
void			free_double_array_of_int(long **need_free);
int				len_d_int_arr(long **array);
void			ft_swap_ints(long **array, int i, int j);
long			**time_sort(char **array, long **time_arr, int start, int end);
long			**prepare_for_time_sort(char **content_of_dir, char *dir);
void			rights_print(int mode, char *fullpath);
void			num_of_hard(char **cont, char *fpath, char *file, char *dir);
void			print_usrid(char *file, char *dir, char **content_of_dir);
void			print_group(char *file, char *dir, char **content_of_dir);
void			print_size(char **content_of_dir, char *file, char *dir);
void			print_date_time(char *fullpath, char *file);
void			print_date_more_six_months(char *fullpath, char *file, char my_time[13]);
int				print_symbol_link(char *fullpath, char *file);
void			print_l_opt_trig(char **cont, char *dir, int trig);
int				l_in_right_way(char **content_of_dir, char *dir);
void			print_long_format(char **cont, char *dir);
void			print_flag(char **opts, char **print, char *dir, int trigger, int sort);
char			file_type(int mode);
char			extend_or_acl(char *fullpath);
void			print_l_opt(char **cont, char *dir, int trigger, int sort);
char			**loop_for_print_res(char **sorted_array, int *calc_columns_rows);
void			print_no_l_opt(char	**for_print, char *dir, int trigger, char **opts);
char			**for_a_arr(char *dir, int sort);
char			**read_names_for_a(DIR *descriptor);
void 			make_other_flags(char *dir, char **opts, int sort);
void			ft_print_all_files_helper(char *dir);
char			*f_path(char *path, char *d_name);
char			*pars_opts(char **opts, char *directory, int kind_of_sort);
void			find_dirs(char **opened_array, char *path, char **opts, int kind_of_srt);
void			*dirwalk(char *path, char **opts, int kind_of_sort);
void			print_files_after_errors(char **srtd_fls, int *calc_cols_rows_for_fls);
void			ft_print_all_array_with_files(char **files);
int				calc_columns_for_files(char **files);
int				*calc_rows_and_columns_for_files(char **files);
void			for_len_more_one(char **dirs, char **opts, int len_of_dirs);
char			**rem_er_helper(char **found_errors, char **dirs, char **no_err_array);
char			**remove_errors(char **found_errors, char **dirs);
void			ft_print_all_files(char **array, char *dir);
void			print_result(char **sorted_array, int *calc_columns_rows, char *dir, char **opts);
int				sum_of_files_in_dir_non_all_flag(char *dir);
char			**save_dir_none_flags(char *dir, int sort);
char			**sorted_array_with_files(char **array, char **empty_array);
int				calc_in_one_line_or_columns(char *dir, char **opts);
int				*calc_rows_and_columns(char *dir, char **opts);
char			**arr_with_spaces(char **array);
void			none_opts(char **dirs, char **opts, char **files, char **term, int err);
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
void			free_double_arrays(char **ar_o, char **ar_t,char **ar_th,char **ar_f);
int				main(int argc, char **argv);

#endif
