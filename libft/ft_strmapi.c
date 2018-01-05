/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsarapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:34:32 by vsarapin          #+#    #+#             */
/*   Updated: 2017/11/19 19:05:56 by vsarapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*a;
	unsigned int	i;

	if (s && f)
	{
		i = 0;
		a = (char *)ft_memalloc(sizeof(char) * (ft_strlen(s) + 1));
		if (a == NULL)
			return (NULL);
		while (s[i])
		{
			a[i] = f(i, s[i]);
			i++;
		}
		a[i] = '\0';
		return (a);
	}
	return (NULL);
}
