/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsarapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 14:30:24 by vsarapin          #+#    #+#             */
/*   Updated: 2017/11/13 18:48:40 by vsarapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dst, int c, size_t n)
{
	char	*d;
	size_t	i;

	i = 0;
	if (n)
	{
		d = (char *)dst;
		while (i < n)
		{
			d[i] = (unsigned char)c;
			i++;
		}
	}
	return (dst);
}
