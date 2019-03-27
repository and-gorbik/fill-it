/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacelyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 17:04:57 by sjacelyn          #+#    #+#             */
/*   Updated: 2018/12/04 18:05:26 by sjacelyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_list	*ft_lstreverse(t_list *lst)
{
	t_list	*newlst;
	t_list	*item;

	newlst = NULL;
	while (lst)
	{
		item = ft_lstnew(lst->content, lst->content_size);
		ft_lstadd(&newlst, item);
		lst = lst->next;
	}
	return (newlst);
}
