/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacelyn <sjacelyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 20:45:14 by sjacelyn          #+#    #+#             */
/*   Updated: 2019/03/26 14:06:30 by sjacelyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static void		resize(t_map *map)
{
	t_list	*lst;

	while (map->size * map->size < 4 * map->container->size)
		map->size += 1;
	if (map->data)
	{
		free(map->data);
		map->size += 1;
	}
	lst = map->container->next;
	while (lst)
	{
		((t_item *)lst->content)->pos.i = 0;
		((t_item *)lst->content)->pos.j = 0;
		lst = lst->next;
	}
	if ((map->data = malloc(map->size * map->size)))
		map->data = ft_memset((void *)map->data, '.', map->size * map->size);
}

static int		check_position(t_map *map, int curi, int curj)
{
	int		i;
	t_point	next;

	i = 0;
	while (i < 4)
	{
		next = ((t_item *)map->container->next->content)->points[i];
		if ((next.i + curi >= map->size) || (next.j + curj >= map->size))
			return (0);
		if (map->data[(next.i + curi) * map->size + next.j + curj] != '.')
			return (0);
		++i;
	}
	return (1);
}

static int		place_item(t_map *m)
{
	t_point	cur;
	int		k;
	t_item	*i;

	cur.i = ((t_item *)m->container->next->content)->pos.i - 1;
	cur.j = ((t_item *)m->container->next->content)->pos.j - 1;
	while (++cur.i < m->size)
	{
		while (++cur.j < m->size)
		{
			if (check_position(m, cur.i, cur.j))
			{
				i = (t_item *)push(m->container)->content;
				k = -1;
				while (++k < 4)
					m->data[(i->points[k].i + cur.i) * m->size +
							(i->points[k].j + cur.j)] = i->chr;
				i->pos = cur;
				return (1);
			}
		}
		cur.j = -1;
	}
	return (0);
}

static void		remove_item(t_map *m)
{
	t_item	*i;
	t_point	cur;
	int		k;

	((t_item *)m->container->next->content)->pos.i = 0;
	((t_item *)m->container->next->content)->pos.j = 0;
	i = (t_item *)pop(m->container)->content;
	cur = i->pos;
	k = -1;
	while (++k < 4)
		m->data[(i->points[k].i + cur.i) * m->size +
				(i->points[k].j + cur.j)] = '.';
	if (cur.j + 1 < m->size)
	{
		i->pos.i = cur.i;
		i->pos.j = cur.j + 1;
	}
	else if (cur.i + 1 < m->size)
	{
		i->pos.i = cur.i + 1;
		i->pos.j = cur.j;
	}
}

t_map			*create_map(t_container *container)
{
	t_map	*map;

	if (!(map = malloc(sizeof(t_map))))
		return (NULL);
	map->size = 0;
	map->container = container;
	map->data = NULL;
	resize(map);
	while (container->next)
	{
		if (!place_item(map))
		{
			if (!container->placed_items)
				resize(map);
			else
				remove_item(map);
		}
	}
	return (map);
}
