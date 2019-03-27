/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjacelyn <sjacelyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 19:09:25 by sjacelyn          #+#    #+#             */
/*   Updated: 2019/03/27 16:18:28 by sjacelyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "map.h"

static void		del(void *data, size_t size)
{
	if (size != 0)
		free(data);
}

static t_list	*read_valid_items(int fd)
{
	t_list	*lst;
	t_list	*cur;
	t_item	*item;
	char	buf[21];
	char	chr;

	chr = 'A' - 1;
	while ((read(fd, buf, 21)))
	{
		buf[20] = '\0';
		if (!(item = create_item(++chr, buf)))
		{
			ft_lstdel(&lst, del);
			return (NULL);
		}
		if (!item->is_valid || !(cur = ft_lstnew(item, sizeof(t_item))))
		{
			ft_lstdel(&lst, del);
			free(item);
			return (NULL);
		}
		free(item);
		ft_lstappend(&lst, cur);
	}
	return (lst);
}

static void		print_map(const char *data, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			write(1, &data[i * size + j], 1);
			++j;
		}
		write(1, "\n", 1);
		++i;
	}
}

static void		delete_map(t_map **map)
{
	delete_container(&(*map)->container);
	free((*map)->data);
	free(*map);
	*map = NULL;
}

int				main(int argc, char **argv)
{
	t_map		*map;
	t_list		*items;
	int			fd;

	if (argc != 2)
	{
		write(1, "Usage:	./fillit <file with tetrominos>\n", 39);
		return (0);
	}
	if (((fd = open(argv[1], O_RDONLY)) >= 0) && (read(fd, NULL, 0) >= 0))
	{
		if ((items = read_valid_items(fd)))
		{
			if ((map = create_map(items)))
			{
				print_map(map->data, map->size);
				delete_map(&map);
				return (0);
			}
			ft_lstdel(&items, del);
		}
	}
	write(1, "error\n", 6);
	close(fd);
	return (0);
}
