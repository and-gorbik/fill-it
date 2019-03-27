/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacelyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 12:58:48 by sjacelyn          #+#    #+#             */
/*   Updated: 2018/11/27 20:22:37 by sjacelyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(char c)
{
	unsigned char	uc;
	char			oct1;
	char			oct2;

	uc = (unsigned char)c;
	if (uc < 128)
		write(1, &c, 1);
	else
	{
		oct1 = (uc >> 6) | 0b11000000;
		oct2 = uc & 0b10111111;
		write(1, &oct1, 1);
		write(1, &oct2, 1);
	}
}
