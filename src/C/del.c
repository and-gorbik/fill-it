/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacelyn <sjacelyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 20:34:35 by sjacelyn          #+#    #+#             */
/*   Updated: 2019/03/28 20:38:33 by sjacelyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "del.h"

void    del(void *data, size_t size)
{
	if (size != 0)
		free(data);
}