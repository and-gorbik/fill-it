/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacelyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 15:51:26 by sjacelyn          #+#    #+#             */
/*   Updated: 2018/11/23 15:33:51 by sjacelyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s, const char *sub)
{
	size_t	i;

	if (*sub == '\0')
		return ((char *)s);
	while (*s)
	{
		if (*s == *sub)
		{
			i = 0;
			while (s[i] == sub[i] && sub[i])
				++i;
			if (sub[i] == '\0')
				return ((char *)s);
		}
		++s;
	}
	return (NULL);
}
