/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsarapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 16:23:26 by vsarapin          #+#    #+#             */
/*   Updated: 2017/11/19 18:30:11 by vsarapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;
	int	a;
	int b;

	i = 0;
	while (haystack[i])
	{
		b = i;
		a = 0;
		while (haystack[b] == needle[a] && needle[a])
		{
			b++;
			a++;
		}
		if (!needle[a])
			return ((char*)&haystack[b - a]);
		i++;
	}
	if (*haystack == '\0' && *needle == '\0')
		return ((char*)haystack);
	return (NULL);
}
