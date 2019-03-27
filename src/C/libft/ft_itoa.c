/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacelyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 11:33:56 by sjacelyn          #+#    #+#             */
/*   Updated: 2018/11/30 15:11:51 by sjacelyn         ###   ########.fr       */
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

static int	len(int n)
{
	int	i;

	i = 0;
	while ((n /= 10))
		++i;
	return (i);
}

char		*ft_itoa(int n)
{
	long	mask;
	char	*s;
	size_t	i;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = 0;
	if (n < 0)
	{
		i = 1;
		n = -n;
	}
	if (!(s = ft_strnew(len(n) + i + 1)))
		return (NULL);
	if (i)
		s[0] = '-';
	mask = mask_gt(n) * 10;
	while ((mask /= 10))
	{
		s[i++] = (n / mask + '0');
		n %= mask;
	}
	return (s);
}
