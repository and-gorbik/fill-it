/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacelyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 13:30:57 by sjacelyn          #+#    #+#             */
/*   Updated: 2018/11/21 18:59:30 by sjacelyn         ###   ########.fr       */
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

void		ft_putnbr(int n)
{
	int	mask;

	if (n == 0)
		ft_putchar('0');
	else if (n == -2147483648)
		ft_putstr("-2147483648");
	else
	{
		if (n < 0)
		{
			ft_putchar('-');
			n = -n;
		}
		mask = mask_gt(n);
		while (mask != 0)
		{
			ft_putchar(n / mask + '0');
			n %= mask;
			mask /= 10;
		}
	}
}
