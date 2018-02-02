/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsarapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 11:00:33 by vsarapin          #+#    #+#             */
/*   Updated: 2018/01/15 12:31:29 by vsarapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int					main(int argc, char **argv)
{
	int		i;
	char	*save_from_input;
	char	**splited_string_from_input;

	i = 0;
	argc = 0;
	save_from_input = NULL;
	splited_string_from_input = NULL;
	while (argv[++i])
		save_from_input = joinmode_helper(save_from_input, argv[i]);
	if (save_from_input)
		splited_string_from_input = ft_strsplit(save_from_input, '\n');
	cheking_variants(splited_string_from_input);
	return (0);
}
