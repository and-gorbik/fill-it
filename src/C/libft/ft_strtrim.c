/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacelyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 18:30:41 by sjacelyn          #+#    #+#             */
/*   Updated: 2018/12/01 19:17:49 by sjacelyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	is_whitespace(char c)
{
	return (c == '\n' || c == ' ' || c == '\t');
}

char		*ft_strtrim(const char *s)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s)
		return (NULL);
	if (!*s)
		return (ft_strnew(0));
	i = 0;
	while (is_whitespace(s[i]) && s[i])
		++i;
	j = ft_strlen(s) - 1;
	while (is_whitespace(s[j]) && (j > i))
		--j;
	++j;
	if (!(str = ft_strnew(j - i)))
		return (NULL);
	return (ft_strncpy(str, s + i, j - i));
}
