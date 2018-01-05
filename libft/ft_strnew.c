/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsarapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:38:10 by vsarapin          #+#    #+#             */
/*   Updated: 2017/11/16 09:56:10 by vsarapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*a;

	a = (char*)malloc(sizeof(char) * (size + 1));
	if (a == NULL)
		return (NULL);
	ft_memset(a, '\0', size + 1);
	return (a);
}
