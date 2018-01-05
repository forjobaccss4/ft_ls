/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsarapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 15:17:48 by vsarapin          #+#    #+#             */
/*   Updated: 2017/11/22 15:21:31 by vsarapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int					i;
	int					is_negative;
	unsigned long int	number;

	i = 0;
	number = 0;
	is_negative = 1;
	while ((str[i] == ' ') || (str[i] == '\r') || (str[i] == '\n') ||
			(str[i] == '\t') || (str[i] == '\f') || (str[i] == '\v'))
		i++;
	if (str[i] == '-')
		is_negative = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = (number * 10) + (str[i] - '0');
		if (number >= 9223372036854775807 && is_negative == 1)
			return (-1);
		else if (number > 9223372036854775807 && is_negative == -1)
			return (0);
		i++;
	}
	return ((int)(number * is_negative));
}
