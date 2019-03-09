/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   container.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacelyn <sjacelyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 15:39:07 by sjacelyn          #+#    #+#             */
/*   Updated: 2019/03/09 15:49:42 by sjacelyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTAINER_H
# define CONTAINER_H

# include "item.h"

/*
** Container moves items between lists.
** `next` contains input items.
** `placed_items` contains items pushed into container.
** `size` keeps size of `placed_items`.
*/

typedef struct	s_container
{
	t_list		*placed_items;
	t_list		*next;
	size_t		size;
}				t_container;

t_container		*create_container(t_list *items);
void			delete_container(t_container **container);

/*
** moves the next item from `next` to `placed_items`
*/
t_list			*push(t_container *container);

/*
** moves the last placed item from `placed_items` to the top of `next`
*/
t_list			*pop(t_container *container);

#endif
