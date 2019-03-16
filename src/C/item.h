/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacelyn <sjacelyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 09:36:48 by sjacelyn          #+#    #+#             */
/*   Updated: 2019/03/09 15:11:09 by sjacelyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITEM_H
# define ITEM_H

# include <stdlib.h>
# include "libft/libft.h"

typedef struct	s_point
{
	char		i;
	char		j;
}				t_point;

typedef struct	s_item
{
	char		chr;
	char		is_valid;
	t_point		pos;
	t_point		points[4];
}				t_item;

t_item			*create_item(char chr, const char *src);

#endif
