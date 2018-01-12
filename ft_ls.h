#ifndef FT_LS
# define FT_LS
# include <dirent.h>
# include <stdlib.h>
# include <sys/ioctl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"
# define SUM_OF_FILES sum_of_files(open_directory())
# define MAX_LENGTH max_len_of_word_in_array(open_directory())

void				free_double_array(char **need_free);
int					*calc_rows(void);
void				swap_for_print_result(char **sorted_array, int *calc_columns_rows);
int					calc_in_one_line_or_columns(void);
void				ft_print_all_words(char **array);
char				**array_with_spaces_and_words(char **empty_array);
size_t				max_len_of_word_in_array(char **array);
void				ft_swap_strings(char **array, int first_string, int second_string);
char				**ft_qsort_mode(char **array, int start, int end);
unsigned long		size_of_screen(void);
int					sum_of_files(char **array);
char				*ft_strjoinmode(char *s1, char *s2);
char				**split_read_array(char *from_read_func);
char				*read_names(DIR *descriptor);
char				**open_directory(void);
char				**array_with_spaces(void);
int					main(int argc, char **argv);

#endif
