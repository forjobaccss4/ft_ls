/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsarapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 14:29:02 by vsarapin          #+#    #+#             */
/*   Updated: 2017/11/13 16:41:13 by vsarapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	int i;

	i = 0;
	while (i < (int)len && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	while (i < (int)len)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}
