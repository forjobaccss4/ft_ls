/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsarapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:14:02 by vsarapin          #+#    #+#             */
/*   Updated: 2017/11/19 18:33:46 by vsarapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	char	*new;
	size_t	new_len;
	int		i;

	i = 0;
	if (!s || !f)
		return (NULL);
	new_len = ft_strlen(s);
	new = (char *)ft_memalloc(sizeof(char) * (new_len + 1));
	if (new == NULL)
		return (NULL);
	while (s[i])
	{
		new[i] = f(s[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}
