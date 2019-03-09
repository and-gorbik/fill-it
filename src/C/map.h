/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacelyn <sjacelyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 20:25:45 by sjacelyn          #+#    #+#             */
/*   Updated: 2019/03/09 20:45:01 by sjacelyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "container.h"

typedef struct	s_map
{
	t_container	*container;
	int			size;
	char		**data;
}				t_map;

t_map			*create_map(t_container *container, t_list *items);

static void		resize(t_map *map);
static int		check_position(t_map *map, int curi, int curj);
static int		place_item(t_map *map);
static void		remove_item(t_map *map);

#endif
