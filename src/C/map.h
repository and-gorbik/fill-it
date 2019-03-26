/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacelyn <sjacelyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 20:25:45 by sjacelyn          #+#    #+#             */
/*   Updated: 2019/03/26 11:33:56 by sjacelyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "container.h"

typedef struct	s_map
{
	t_container	*container;
	int			size;
	char		*data;
}				t_map;

t_map			*create_map(t_container *container);

#endif
