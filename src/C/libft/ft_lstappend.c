/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacelyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 17:30:05 by sjacelyn          #+#    #+#             */
/*   Updated: 2018/12/05 17:35:07 by sjacelyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstappend(t_list **root, t_list *item)
{
	t_list	*ptr;

	if (!root)
		return ;
	if (!*root)
	{
		*root = item;
		return ;
	}
	ptr = *root;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = item;
}
