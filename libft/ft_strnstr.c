/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsarapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 10:12:02 by vsarapin          #+#    #+#             */
/*   Updated: 2017/11/20 10:35:18 by vsarapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	a;
	size_t	b;

	i = 0;
	while (haystack[i] && i < len)
	{
		a = 0;
		b = i;
		while (haystack[b] == needle[a] && needle[a] && b < len)
		{
			b++;
			a++;
		}
		if (needle[a] == '\0')
			return ((char*)&haystack[b - a]);
		i++;
	}
	if (*haystack == '\0' && *needle == '\0')
		return ((char*)haystack);
	return (NULL);
}
