/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacelyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 15:03:59 by sjacelyn          #+#    #+#             */
/*   Updated: 2018/11/25 15:11:57 by sjacelyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*data;
	size_t	i;

	if (!(data = malloc(size)))
		return (NULL);
	i = 0;
	while (i < size)
	{
		((unsigned char *)data)[i] = '\0';
		++i;
	}
	return (data);
}
