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
	while (need_free[i])
	{
		free(need_free[i]);
		i++;
	}
	free(need_free);
}
