/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacelyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 20:43:18 by sjacelyn          #+#    #+#             */
/*   Updated: 2018/11/22 20:44:36 by sjacelyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	mask_gt(int n)
{
	long	r;

	r = 1;
	while (r * 10 <= n)
		r *= 10;
	return (r);
}

void		ft_putnbr_fd(int n, int fd)
{
	int	mask;

	if (n == 0)
		ft_putchar_fd('0', fd);
	else if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n = -n;
		}
		mask = mask_gt(n);
		while (mask != 0)
		{
			ft_putchar_fd(n / mask + '0', fd);
			n %= mask;
			mask /= 10;
		}
	}
}
