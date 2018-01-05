/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsarapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 18:12:39 by vsarapin          #+#    #+#             */
/*   Updated: 2017/11/22 16:47:33 by vsarapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*p;
	t_list	*buffer;

	if (!lst || !f)
		return (0);
	if (!(p = (t_list*)malloc(sizeof(t_list))))
		return (0);
	p = f(lst);
	new = ft_lstnew(p->content, p->content_size);
	buffer = new;
	lst = lst->next;
	while (lst)
	{
		if (!(p = (t_list*)malloc(sizeof(t_list))))
			return (0);
		p = f(lst);
		new->next = ft_lstnew(p->content, p->content_size);
		new = new->next;
		lst = lst->next;
	}
	new->next = NULL;
	return (buffer);
}
