/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsarapin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:30:36 by vsarapin          #+#    #+#             */
/*   Updated: 2017/11/19 20:37:47 by vsarapin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	num;
	long int	i;

	num = n;
	i = 1;
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		num *= -1;
	}
	while (num / i > 9)
		i *= 10;
	while (i > 0)
	{
		ft_putchar_fd(num / i + '0', fd);
		num %= i;
		i /= 10;
	}
}
