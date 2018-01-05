/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsarapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 11:30:48 by vsarapin          #+#    #+#             */
/*   Updated: 2017/11/20 14:14:31 by vsarapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int n)
{
	char		*s;
	int			len;
	long int	a;

	a = n;
	len = ft_intlen(n);
	if (!(s = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (a == 0)
		s[0] = '0';
	if (a < 0)
	{
		s[0] = '-';
		a = -a;
	}
	s[len] = '\0';
	while (a)
	{
		len--;
		s[len] = (a % 10) + '0';
		a /= 10;
	}
	return (s);
}
