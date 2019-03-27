/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacelyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 16:24:51 by sjacelyn          #+#    #+#             */
/*   Updated: 2018/11/30 18:51:53 by sjacelyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *sub, size_t len)
{
	size_t	i;
	size_t	j;

	if (*sub == '\0')
		return ((char *)s);
	i = 0;
	while (s[i] && i < len)
	{
		if (s[i] == sub[0])
		{
			j = 0;
			while (s[i + j] == sub[j] && s[i + j] && i + j < len)
				++j;
			if (sub[j] == '\0')
				return ((char *)s + i);
		}
		++i;
	}
	return (NULL);
}
