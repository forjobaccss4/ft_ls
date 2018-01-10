#ifndef FT_LS
# define FT_LS
# include <dirent.h>
# include <stdlib.h>
# include <sys/ioctl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"
# define SUM_OF_FILES num_of_files(open_and_ls())
# define MAX_LENGTH len_for_sorted_array(open_and_ls())

int					*calc_rows(int calc_columns);
void				swap_for_print_result(char **sorted_array, int *calc_columns_rows);
int					calc_in_one_line_or_columns(void);
void				ft_print_all_words(char **array);
char				**array_with_spaces_and_words(void);
size_t				len_for_sorted_array(char **array);
void				ft_swap_strings(char **array, int i, int j);
char				**ft_qsort_mode(char **array, int start, int end);
unsigned long		size_of_screen(void);
int					num_of_files(char **array);
char				*ft_strjoinmode(char *s1, char *s2);
char				**read_names(DIR *descriptor);
char				**open_and_ls(void);
char				**array_with_spaces(void);
int					main(int argc, char **argv);

#endif
