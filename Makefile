NAME = ft_ls
PATH_SRC = ./

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I $(PATH_SRC)
SRC = 			$(PATH_SRC)ft_strcat.c \
				$(PATH_SRC)ft_bzero.c \
				$(PATH_SRC)ft_putnbr.c \
				$(PATH_SRC)ft_memcpy.c \
				$(PATH_SRC)ft_putstr.c \
				$(PATH_SRC)ft_memset.c \
				$(PATH_SRC)ft_putchar.c \
				$(PATH_SRC)ft_strcmp.c \
				$(PATH_SRC)ft_strdup.c \
				$(PATH_SRC)ft_strjoin.c \
				$(PATH_SRC)ft_strlen.c \
				$(PATH_SRC)ft_strcpy.c \
				$(PATH_SRC)ft_strncpy.c \
				$(PATH_SRC)ft_strsplit.c \
				$(PATH_SRC)ft_intlen.c \
				$(PATH_SRC)for_changes_in_array.c \
				$(PATH_SRC)ft_qsort_and_swap.c \
				$(PATH_SRC)rows_and_columns.c \
				$(PATH_SRC)print_file.c \
				$(PATH_SRC)job_with_files.c \
				$(PATH_SRC)for_free.c \
				$(PATH_SRC)width_length_and_other.c \
				$(PATH_SRC)parsing_arguments.c \
				$(PATH_SRC)errors_in_input.c \
				$(PATH_SRC)job_with_opts.c \
				$(PATH_SRC)job_with_dirs.c \
				$(PATH_SRC)do_all_work_file.c \
				$(PATH_SRC)job_with_files_in_arg.c \
				$(PATH_SRC)for_rec.c \
				$(PATH_SRC)make_opts_work.c \
				$(PATH_SRC)for_a.c \
				$(PATH_SRC)for_l.c \
				$(PATH_SRC)for_l_helper.c \
				$(PATH_SRC)l_continue.c \
				$(PATH_SRC)time_sort.c \
				$(PATH_SRC)kind_of_sort.c \
				$(PATH_SRC)r_sort.c \
				$(PATH_SRC)l_end.c \
				$(PATH_SRC)l_end_end.c \
				$(PATH_SRC)final_file.c \
				$(PATH_SRC)print_one_flag_helper.c \
				$(PATH_SRC)paddings_l.c \
				$(PATH_SRC)ls.c \
				$(PATH_SRC)join_names.c \
				$(PATH_SRC)trash.c \
				$(PATH_SRC)trash_continue.c \
				$(PATH_SRC)print_and_free.c \
				$(PATH_SRC)trash_end.c \
				$(PATH_SRC)trash_end_end.c \



OBJ		= $(SRC:.c=.o)
				
all: $(NAME)

$(NAME): $(OBJ) 
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
