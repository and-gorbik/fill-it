/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacelyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 17:26:56 by sjacelyn          #+#    #+#             */
/*   Updated: 2018/11/25 17:28:13 by sjacelyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new_str;
	size_t	i;

	if (!s || !f)
		return (NULL);
	if (!(new_str = ft_strnew(ft_strlen(s))))
		return (NULL);
	(void)ft_strcpy(new_str, s);
	i = 0;
	while (new_str[i])
	{
		new_str[i] = (*f)(i, new_str[i]);
		++i;
	}
	return (new_str);
}
