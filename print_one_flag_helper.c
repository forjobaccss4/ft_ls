/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_one_flag_helper.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsarapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 11:13:31 by vsarapin          #+#    #+#             */
/*   Updated: 2018/03/15 11:13:35 by vsarapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_one_flag_trg_zero(char **array, char *dir, int count)
{
	DIR *open;

	if ((open = opendir(dir)) && array)
	{
		closedir(open);
		while (array[++count])
		{
			ft_putstr(array[count]);
			write(1, "\n", 1);
			free(array[count]);
		}
		free(array);
		return ;
	}
	ft_print_all_files_helper(dir);
	return ;
}

void	print_one_flag_trg_one(char **array, char *dir, int count)
{
	DIR *open;

	if ((open = opendir(dir)) && array)
	{
		closedir(open);
		write(1, "\n", 1);
		write(1, dir, ft_strlen(dir));
		write(1, ":\n", 2);
		while (array[++count])
		{
			ft_putstr(array[count]);
			write(1, "\n", 1);
			free(array[count]);
		}
		free(array);
		return ;
	}
	write(1, "\n", 1);
	write(1, dir, ft_strlen(dir));
	write(1, ":\n", 2);
	ft_print_all_files_helper(dir);
	return ;
}
