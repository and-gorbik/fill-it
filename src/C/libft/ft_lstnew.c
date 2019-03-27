/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacelyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 15:06:08 by sjacelyn          #+#    #+#             */
/*   Updated: 2018/11/29 15:06:16 by sjacelyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(const void *data, size_t size)
{
	t_list	*item;

	if (!(item = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!data)
	{
		item->content = NULL;
		item->content_size = 0;
	}
	else
	{
		if (!(item->content = malloc(size)))
		{
			free(item);
			return (NULL);
		}
		(void)ft_memcpy(item->content, data, size);
		item->content_size = size;
	}
	item->next = NULL;
	return (item);
}
