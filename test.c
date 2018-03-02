#include "ft_ls.h"

int main(int argc, char *argv[]) 
{
	struct stat buf;
	long a;
	long b;

	lstat("libft/libft.a", &buf);
	printf("libft/libft.a = %ld\n", buf.st_mtime);
	a =  buf.st_mtime;
	
	lstat("libft/libft.h.gch", &buf);
	printf("libft/libft.h.gch = %ld\n", buf.st_mtime);
	b =  buf.st_mtime;

	printf("%ld\n", a - b);

}

