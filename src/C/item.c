/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacelyn <sjacelyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 09:38:02 by sjacelyn          #+#    #+#             */
/*   Updated: 2019/03/09 19:10:52 by sjacelyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "item.h"

static char		**to_matrix(const char *s)
{
	char	**matrix;
	int		i;

	if (!(matrix = ft_strsplit(s, '\n')))
		return (NULL);
	i = 0;
	while (matrix[i])
	{
		if (ft_strlen(matrix[i]) != 4)
		{
			i = -1;
			while (matrix[++i])
				free(matrix[i]);
			free(matrix);
			return (NULL);
		}
		++i;
	}
	return (matrix);
}

static t_point	get_offset(char **matrix)
{
	t_point	offset;
	int		i;
	char	*ptr;

	offset.j = 4;
	i = 0;
	while (matrix[i])
	{
		ptr = ft_strchr(matrix[i], '#');
		if (ptr && ptr - matrix[i] < offset.j)
			offset.j = ptr - matrix[i];
		++i;
	}
	offset.i = 0;
	i = 0;
	while (matrix[i] && !ft_strchr(matrix[i], '#'))
	{
		offset.i = i;
		++i;
	}
	return (offset);
}

static void		set_points(t_item *item, char **matrix)
{
	t_point	offset;
	int		i;
	int		k;

	if (!matrix)
	{
		item->is_valid = 0;
		return ;
	}
	offset = get_offset(matrix);
	k = 0;
	i = 0;
	while (i < 16)
	{
		if (matrix[i / 4][i % 4] == '#')
		{
			item->points[k].i = i / 4 - offset.i;
			item->points[k].j = i % 4 - offset.j;
			++k;
		}
		++i;
	}
	while (--k >= 0)
		free(matrix[k]);
	free(matrix);
}

static void		validate_item(t_item *item)
{
	t_point	cur;
	t_point	other;
	int		c;
	int		i;
	int		j;

	if (!item->is_valid)
		return ;
	c = 0;
	i = -1;
	while (++i < 4)
	{
		cur = item->points[i];
		j = -1;
		while (++j < 4)
		{
			other = item->points[j];
			c += (cur.j - 1 >= 0 && other.i == cur.i && other.j == cur.j - 1);
			c += (cur.i - 1 >= 0 && other.i == cur.i - 1 && other.j == cur.j);
			c += (cur.j + 1 < 4 && other.i == cur.i && other.j == cur.j + 1);
			c += (cur.i + 1 < 4 && other.i == cur.i + 1 && other.j == cur.j);
		}
	}
	if (c < 6)
		item->is_valid = 0;
}

t_item			*create_item(char chr, const char *src)
{
	t_item	*item;

	if (!(item = malloc(sizeof(t_item))))
		return (NULL);
	item->chr = chr;
	item->posi = 0;
	item->posj = 0;
	item->is_valid = (ft_strlen(src) == 20 && ft_strcount(src, '\n') == 4 &&
					ft_strcount(src, '#') == 4 && ft_strcount(src, '.') == 12);
	set_points(item, to_matrix(src));
	validate_item(item);
	return (item);
}
