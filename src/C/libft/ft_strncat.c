/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacelyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 13:41:49 by sjacelyn          #+#    #+#             */
/*   Updated: 2018/11/24 18:06:46 by sjacelyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	end;

	if (*s2 == '\0')
		return (s1);
	i = 0;
	while (s1[i])
		++i;
	end = ft_strlen(s2) > n ? n : ft_strlen(s2);
	(void)ft_strncpy(s1 + i, s2, end);
	s1[i + end] = '\0';
	return (s1);
}
