/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacelyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 13:29:22 by sjacelyn          #+#    #+#             */
/*   Updated: 2018/12/05 19:51:18 by sjacelyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*buf;

	if (dst == src)
		return (dst);
	if ((char *)dst > (char *)src && (char *)dst < (char *)src + len)
	{
		buf = (unsigned char *)malloc(len);
		(void)ft_memcpy(buf, (void *)src, len);
		(void)ft_memcpy(dst, buf, len);
		free(buf);
	}
	else
		(void)ft_memcpy(dst, (void *)src, len);
	return (dst);
}
