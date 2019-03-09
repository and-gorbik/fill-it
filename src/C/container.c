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
	return (container);
}

static void		del(void *data, size_t size)
{
	if (size != 0)
		free(data);
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