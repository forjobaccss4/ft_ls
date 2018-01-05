#ifndef FT_LS
# define FT_LS
# include <dirent.h>
# include <stdlib.h>
# include <sys/ioctl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"
# define MAX_SPACES_BETWEEN 7
# define SUM_OF_FILES num_of_files(open_and_ls())

void				print_array_with_spaces(size_t len);
size_t				len_for_sorted_array(char **array);
void				ft_swap_strings(char **array, int i, int j);
char				**ft_qsort_mode(char **array, int start, int end);
unsigned long		size_of_screen(void);
int					num_of_files(char **array);
char				*ft_strjoinmode(char *s1, char *s2);
char				**read_names(DIR *descriptor);
char				**open_and_ls(void);
char				**array_with_spaces(size_t len);
int					main(int argc, char **argv);

#endif
