/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacelyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 18:52:15 by sjacelyn          #+#    #+#             */
/*   Updated: 2018/12/05 19:03:04 by sjacelyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfind(t_list *lst, void *data, size_t size)
{
	while (lst)
	{
		if (size == lst->content_size && !ft_memcmp(lst->content, data, size))
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
