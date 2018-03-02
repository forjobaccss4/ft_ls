NAME = ft_ls
PATH_SRC = ./
PATH_LIB = libft/libft.a

CC = gcc
CFLAGS =  -Wall -Wextra -Werror -o ft_ls ./$(PATH_LIB) -I $(PATH_SRC)
SRC = 			$(PATH_SRC)ls.c \
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
				$(PATH_SRC)for_R.c \
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
				
all: $(NAME)

$(NAME): clean 

	/bin/rm -f a.out
	$(CC) $(CFLAGS) $(SRC)

clean:
	/bin/rm -f $(OBJ)

n:
	norminette $(SRC) libft/

re: fclean all
