/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreduce.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacelyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 17:36:57 by sjacelyn          #+#    #+#             */
/*   Updated: 2018/12/05 18:51:54 by sjacelyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstreduce(t_list *lst, t_list *(*reducer)(t_list *one, t_list *two))
{
	t_list	*temp;

	if (!lst || !reducer)
		return (NULL);
	temp = lst;
	while (lst->next)
	{
		temp = (*reducer)(lst, lst->next);
		if (!temp)
			return (NULL);
		lst = lst->next;
	}
	return (ft_lstnew(temp->content, temp->content_size));
}
