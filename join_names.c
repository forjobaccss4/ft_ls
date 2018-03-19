/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_names.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsarapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 11:11:12 by vsarapin          #+#    #+#             */
/*   Updated: 2018/03/15 11:11:16 by vsarapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_lst	*add_lst(t_lst *structure, char *name)
{
	structure = (t_lst*)malloc(sizeof(t_lst));
	structure->name = ft_strdup(name);
	structure->counter = 0;
	structure->next = NULL;
	return (structure);
}

t_lst	*joinmode_list(t_lst *names, char *name_dir)
{
	static t_lst *head;

	if (!names)
	{
		names = add_lst(names, name_dir);
		head = names;
		head->counter += 1;
		return (names);
	}
	while (names)
	{
		if (!names->next)
		{
			names->next = add_lst(names, name_dir);
			head->counter += 1;
			return (head);
		}
		names = names->next;
	}
	return (head);
}

char	**splited_arr(t_lst *names)
{
	t_lst			*head;
	int				from_zero;
	char			**for_split;
	t_lst			*tmp;

	from_zero = -1;
	head = names;
	if (!names)
		return (NULL);
	for_split = (char**)malloc(sizeof(char*) * (names->counter + 1));
	for_split[names->counter] = 0;
	while (names)
	{
		for_split[++from_zero] = ft_strdup(names->name);
		names = names->next;
	}
	while (head)
	{
		tmp = head->next;
		free(head->name);
		free(head);
		head = tmp;
	}
	head = NULL;
	return (for_split);
}
