/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacelyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 20:22:16 by sjacelyn          #+#    #+#             */
/*   Updated: 2018/12/05 20:05:36 by sjacelyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dstlen;

	dstlen = ft_strlen(dst);
	if (size > dstlen)
	{
		i = 0;
		while (src[i] && dstlen + i < size - 1)
		{
			dst[dstlen + i] = src[i];
			++i;
		}
		dst[dstlen + i] = '\0';
	}
	return (ft_strlen(src) + (dstlen > size ? size : dstlen));
}
