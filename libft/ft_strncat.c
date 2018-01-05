/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsarapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 15:39:10 by vsarapin          #+#    #+#             */
/*   Updated: 2017/11/19 18:26:17 by vsarapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	dl;
	size_t	i;

	i = 0;
	dl = ft_strlen(s1);
	while (s2[i] && i < n)
	{
		s1[dl] = s2[i];
		dl++;
		i++;
	}
	s1[dl] = '\0';
	return (s1);
}
