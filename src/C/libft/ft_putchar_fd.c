/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacelyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 20:39:23 by sjacelyn          #+#    #+#             */
/*   Updated: 2018/11/23 13:20:47 by sjacelyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	unsigned char	uc;
	char			oct1;
	char			oct2;

	uc = (unsigned char)c;
	if (uc < 128)
		write(fd, &c, 1);
	else
	{
		oct1 = (uc >> 6) | 0b11000000;
		oct2 = uc & 0b10111111;
		write(fd, &oct1, 1);
		write(fd, &oct2, 1);
	}
}
