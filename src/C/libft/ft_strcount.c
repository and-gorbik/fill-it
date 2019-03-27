/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacelyn <sjacelyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 10:05:42 by sjacelyn          #+#    #+#             */
/*   Updated: 2019/03/09 14:36:57 by sjacelyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcount(const char *s, char chr)
{
	int	counter;

	counter = 0;
	while (*s)
	{
		if (*s == chr)
			++counter;
		++s;
	}
	return (counter);
}
