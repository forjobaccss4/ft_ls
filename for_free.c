/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsarapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 11:24:53 by vsarapin          #+#    #+#             */
/*   Updated: 2018/01/11 11:24:57 by vsarapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	free_double_array(char **need_free)
{
	int i;

	i = 0;
	if (!need_free)
		return ;
	while (need_free[i])
	{
		free(need_free[i]);
		i++;
	}
	free(need_free);
	need_free = NULL;
}

void	free_double_array_of_int(long **need_free)
{
	int i;
	int	len;

	i = 0;
	if (!need_free)
		return ;
	len = len_d_int_arr(need_free);
	while (i < len)
	{
		free(need_free[i]);
		i++;
	}
	free(need_free);
	need_free = NULL;
}

int		len_d_int_arr(long **array)
{
	int i;

	i = 0;
	if (!array)
		return (0);
	while (array[i])
		i++;
	return (i);
}

void	free_d_arr(char **ar_o, char **ar_t, char **ar_th, char **ar_f)
{
	if (ar_o)
	{
		free_double_array(ar_o);
		ar_o = NULL;
	}
	if (ar_t)
	{
		free_double_array(ar_t);
		ar_t = NULL;
	}
	if (ar_th)
	{
		free_double_array(ar_th);
		ar_th = NULL;
	}
	if (ar_f)
	{
		free_double_array(ar_f);
		ar_f = NULL;
	}
}

void	free_three_arrays(char **ar_o, char **ar_t, char **ar_th)
{
	if (ar_o)
	{
		free_double_array(ar_o);
		ar_o = NULL;
	}
	if (ar_t)
	{
		free_double_array(ar_t);
		ar_t = NULL;
	}
	if (ar_th)
	{
		free_double_array(ar_th);
		ar_th = NULL;
	}
}
