/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacelyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 15:06:51 by sjacelyn          #+#    #+#             */
/*   Updated: 2018/12/05 18:34:00 by sjacelyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*cur;
	t_list	*next;

	if (!alst || !del)
		return ;
	cur = *alst;
	while (cur)
	{
		next = cur->next;
		ft_lstdelone(&cur, del);
		cur = next;
	}
	*alst = NULL;
}
