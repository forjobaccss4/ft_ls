/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsarapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 11:11:27 by vsarapin          #+#    #+#             */
/*   Updated: 2018/03/15 11:11:33 by vsarapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <dirent.h>
# include <stdlib.h>
# include <sys/ioctl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/param.h>
# include <assert.h>
# include <time.h>
# include <sys/xattr.h>
# include <sys/acl.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>

typedef struct		s_lst
{
	char			*name;
	int				counter;
	struct s_lst	*next;
}					t_lst;

void				first_func(char **term);
int					second_func_(char **o, char **t, char **fi, char **rem);
void				third_func(char **opts, char **rem, char **term, int e);
char				**dirs_opts(char **opts, char **no, char **rem);
char				**files_opts(char **opts, char **no_opts_string);
int					coinc_helper(char **remove_from);
int					valid_flags(char **flags, int i);
void				print_long_format_files(char **cont, char *dir);
void				dev_print(char *p, char **c, char *dr, char *f);
char				*f_path_for_r(char *path, char *d_name);
int					files_with_flags_hlp_cn(char **s, int *r, int t, char **o);
int					files_output_hlp(char **s, int *r, int t, char **o);
void				print_no_l_opt_tr_zero(char	**for_print, char *dir);
char				**copy_d_arr(char **d_arr);
void				treatment_of_errors_help(char **found_err_in_input);
void				for_len_more_one_help(char **dir, char **opt, int coun);
void				if_empty_term(char **opts);
void				len_dir_one_have_err(char **dirs, char **opts);
void				len_dir_one_have_files(char **dirs, char **opts);
void				len_dir_one(char **dirs, char **opts);
void				print_no_l_opt_tr_one(char	**for_print, char *dir);
void				print_files_helper(char **srt, int *c_r, char **pr);
void				free_three_arrays(char **ar_o, char **ar_t, char **ar_th);
char				**free_opts(char **string_from_term);
t_lst				*add_lst(t_lst *structure, char *name);
t_lst				*joinmode_list(t_lst *names, char *name_dir);
char				**splited_arr(t_lst *names);
char				*rem_l_end(char *opts, char final[PATH_MAX], char *new);
char				*remove_l_if_one(char *opts_str);
void				for_break(int *arr, int len, long **t, char **c);
int					usrid_padding(char **cont, char *dir);
int					group_padding(char **cont, char *dir);
int					size_padding(char **cont, char *dir);
int					opts_with_files(char **opts, char **files, int trigger);
int					files_output_flags(char **opts, char **files, int trigg);
int					files_output_flags_cont(char **opt, char **fls, int trg);
void				print_one_flag_trg_zero(char **array, char *dir, int count);
void				print_one_flag_trg_one(char **array, char *dir, int count);
void				ft_print_one_flag(char **array, char *dir, int trg);
void				print_one_opt(char **fls, char **opts);
char				**make_flags_contin(char *d, char **op, char **a, int so);
int					l_file_or_not(char *no_opts_str);
void				for_dev_dir_major(char *fp, char **cont, char *dir);
void				for_dev_dir_minor(char *fp, char **cont, char *dir);
int					first_case(char **dirs, char **files, char **opts, int err);
void				sec_case(char **dirs, char **files, char **opts, int err);
void				hard_links_files(char **c, char *fa, char *fi, char *d);
void				print_usrid_files(char *f, char *d, char **cont);
int					print_usrid_helper(char **cont, char *for_check_file);
void				print_long_format(char **cont, char *dir, int c, int *igs);
void				files_case(char **dirs, char **files, char **opts, int err);
void				no_opts(char **d, char **f, char **o, int e);
void				all_cases(char **opts, char **drs, char **fls, int err);
int					dir_or_not(char *no_opts_str);
t_lst				*l_dirs(char **no_opts_str);
t_lst				*l_files(char **no_opts_str);
char				**read_names_for_a(DIR *descriptor);
int					file_or_not_helper(char *s, char b[PATH_MAX]);
int					right_distance_h_links(char **cont, char *dir);
int					size_padding(char **cont, char *dir);
void				opts_dirs(char **opts, char **dirs, int err);
void				r_swap(char **array, int i, int j);
char				**r_sort(char **array);
int					file_or_not(char *some_file);
int					kind_of_srt(char **opts);
void				return_t_r_array(int kind_of_sort, char **cont, char *dir);
void				same_time(char **cont_of_dir, long **time_arr);
void				ft_swap_ints(long **array, int i, int j);
void				free_double_array_of_int(long **need_free);
int					len_d_int_arr(long **array);
void				ft_swap_ints(long **array, int i, int j);
void				time_sort(char **a, long **t, int start, int end);
long				**prepare_for_time_sort(char **cont, char *dir);
void				rights_print(int mode, char *fullpath);
void				num_of_hard(char **c, char *f, char *dr, int *idgrs);
void				print_usrid(char *file, char *dir, int pad);
void				print_group(char *file, char *dir, int pad);
void				print_size(char *file, int pad);
void				print_date_time(char *fullpath, char *file);
void				print_date_more_six_months(char *i, char *f, char m[13]);
int					print_symbol_link(char *fullpath, char *file);
void				print_l_opt_trig(char **cont, char *dir, int trig);
int					l_in_right_way(char **cont, char *dir);
void				prnt_flg(char **o, char **a, char *d, int t);
char				file_type(int mode);
char				extend_or_acl(char *fullpath);
void				print_l_opt(char **cont, char *dir, int trigger, int sort);
char				**loop_for_print_res(char **srt, int *c_r);
void				print_no_l_opt(char	**for_print, char *dir, int trigger);
char				**for_a_arr(char *dir, int sort);
t_lst				*read_names(DIR *descriptor);
void				make_other_flags(char *dir, char **opts, int sort);
void				ft_print_all_files_helper(char *dir);
char				*f_path(char *path, char *d_name);
char				*pars_opts(char **opts, char *directory, int kind_of_sort);
void				find_dirs(char **opn_arr, char *path, char **opts, int srt);
void				*dirwalk(char *path, char **opts, int kind_of_sort);
void				print_files_after_errors(char **srtd_fl, int *c_r);
void				ft_print_all_array_with_files(char **files);
int					calc_columns_for_files(char **files);
int					*calc_rows_and_columns_for_files(char **files);
void				for_len_more_one(char **dirs, char **opts, int len_of_dirs);
char				**rem_er_helper(char **errors, char **d, char **no_err);
char				**remove_errors(char **found_errors, char **dirs);
void				ft_print_all_files(char **array, char *dir);
void				print_result(char **sorted_array, int *c_r, char *dir);
int					sum_of_files_in_dir_non_all_flag(char *dir);
char				**save_dir_none_flags(char *dir, int sort);
char				**sorted_array_with_files(char **array);
int					calc_in_one_line_or_columns(char *dir, char **opts);
int					*calc_rows_and_columns(char *dir, char **opts);
void				none_opts(char **d, char **o, char **f, int err);
char				**looking_for_files(char **without_opts);
char				**looking_for_dirs(char **without_opts);
char				*search_for_dup(char *string_copy, int c);
char				**dlt_repeated_symbols_opts(char *without_minus);
char				*minus_from_opts(char **string_from_term);
char				*opts_in_one_string(char **string_from_term);
char				**remove_end_of_options(char **remove_from);
char				**coinc_in_double_array(char **remove, char **from);
char				**remove_opt_from_string_input(char **opt, char **term);
int					treatment_of_errors(char **string_from_term);
char				**find_errors_in_input(char **cleared_string_from_opts);
void				error_mes_of_nonval_opt(char c);
char				**valid_opt_or_not(char **possible_options);
int					len_d_arr(char **array);
char				**find_possible_options(char **string_from_term);
void				free_double_array(char **need_free);
size_t				max_len_of_word_in_array(char **array);
void				ft_swap_strings(char **arr, int f_string, int s_string);
char				**ft_qsort_mode(char **array, int start, int end);
unsigned long		size_of_screen(void);
int					sum_of_files(char **array);
void				free_d_arr(char **o, char **t, char **th, char **f);
int					main(int argc, char **argv);
void				*ft_memset(void *dst, int c, size_t n);
void				ft_bzero(void *s, size_t n);
char				*ft_strcpy(char *dst, char *src);
void				ft_putstr(char const *s);
void				ft_putchar(char c);
char				*ft_strdup(const char *s1);
char				*ft_strjoin(char *s1, char *s2);
size_t				ft_strlen(const char *str);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				**ft_strsplit(char const *s, char c);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcat(char *s1, const char *s2);
int					ft_intlen(int n);
void				ft_putnbr(int n);
void				*ft_memcpy(void *dst, const void *src, size_t n);

#endif
