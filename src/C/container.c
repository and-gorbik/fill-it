/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   container.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacelyn <sjacelyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 20:21:06 by sjacelyn          #+#    #+#             */
/*   Updated: 2019/04/05 20:25:04 by sjacelyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "container.h"

t_container		*create_container(t_list *items)
{
	t_container	*container;

	if (!items)
		return (NULL);
	if (!(container = malloc(sizeof(t_container))))
		return (NULL);
	container->next = items;
	container->placed_items = NULL;
	container->size = 0;
	while (items)
	{
		container->size += 1;
		items = items->next;
	}
	if (container->size > 26)
		return (NULL);
	return (container);
}

void			delete_container(t_container **container)
{
	ft_lstdel(&(*container)->next, del);
	ft_lstdel(&(*container)->placed_items, del);
	free(*container);
	*container = NULL;
}

t_list			*push(t_container *container)
{
	t_list	*cur;

	if (!container->next)
		return (NULL);
	cur = container->next;
	container->next = container->next->next;
	cur->next = container->placed_items;
	container->placed_items = cur;
	return (cur);
}

t_list			*pop(t_container *container)
{
	t_list	*cur;

	if (!container->placed_items)
		return (NULL);
	cur = container->placed_items;
	container->placed_items = container->placed_items->next;
	cur->next = container->next;
	container->next = cur;
	return (cur);
}
