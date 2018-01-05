/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft_strjoin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsarapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 10:20:43 by vsarapin          #+#    #+#             */
/*   Updated: 2017/12/14 10:17:17 by vsarapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;

	res = NULL;
	i = 0;
	if (s1 && s2)
	{
		if ((res = (char*)malloc(sizeof(char)
						* (ft_strlen(s1) + ft_strlen(s2) + 1))))
		{
			while (*s1)
			{
				res[i++] = *s1;
				s1++;
			}
			while (*s2)
			{
				res[i++] = *s2;
				s2++;
			}
			res[i] = '\0';
		}
	}
	return (res);
}
