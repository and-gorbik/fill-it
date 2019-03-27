/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfilter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacelyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 14:13:51 by sjacelyn          #+#    #+#             */
/*   Updated: 2018/12/05 19:12:58 by sjacelyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	del(void *data, size_t size)
{
	if (!data || !size)
		return ;
	free(data);
}

t_list		*ft_lstfilter(t_list *lst, int (*filter)(t_list *elem))
{
	t_list	*newlst;
	t_list	*item;

	newlst = NULL;
	while (lst)
	{
		if ((*filter)(lst))
		{
			if (!(item = ft_lstnew(lst->content, lst->content_size)))
			{
				ft_lstdel(&newlst, &del);
				return (NULL);
			}
			ft_lstappend(&newlst, item);
		}
		lst = lst->next;
	}
	return (newlst);
}
