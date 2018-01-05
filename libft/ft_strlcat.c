/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsarapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 16:02:33 by vsarapin          #+#    #+#             */
/*   Updated: 2017/11/20 14:44:45 by vsarapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	a;

	i = ft_strlen(dst);
	if (i <= dstsize)
		a = i + ft_strlen(src);
	else
		a = dstsize + ft_strlen(src);
	while (dstsize && i < dstsize - 1)
	{
		if (*src)
			dst[i] = *src;
		else
			dst[i] = '\0';
		i++;
		src++;
	}
	dst[i] = '\0';
	return (a);
}
