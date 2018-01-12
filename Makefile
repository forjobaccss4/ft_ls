NAME = ft_ls
PATH_SRC = ./
PATH_LIB = libft/libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror ./$(PATH_LIB) -I $(PATH_SRC)
SRC = 			$(PATH_SRC)ls.c \
				$(PATH_SRC)for_changes_in_array.c \
				$(PATH_SRC)ft_qsort_and_print_ls.c \
				$(PATH_SRC)for_free.c \
				$(PATH_SRC)width_length_and_other.c \
				


				

all: $(NAME)

$(NAME): clean 

	/bin/rm -f a.out
	$(CC) $(CFLAGS) $(SRC)

clean:
	/bin/rm -f $(OBJ)

n:
	norminette $(SRC) libft/

re: fclean all
