/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacelyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 15:07:25 by sjacelyn          #+#    #+#             */
/*   Updated: 2018/12/05 19:40:44 by sjacelyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	del(void *data, size_t size)
{
	if (!data || !size)
		return ;
	free(data);
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_list;
	t_list	*new_item;

	if (!lst || !f)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		if (!(new_item = (*f)(lst)))
		{
			ft_lstdel(&new_list, &del);
			return (NULL);
		}
		ft_lstappend(&new_list, new_item);
		lst = lst->next;
	}
	return (new_list);
}
