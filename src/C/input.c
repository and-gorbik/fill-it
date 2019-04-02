#include <fcntl.h>
#include <stdio.h>
#include "map.h"

void    del(void *data, size_t size)
{
	if (size != 0)
		free(data);
}

static int  read_valid_item(int fd, char chr, t_item **item)
{
    char        buf[21];
    int         size;
    static int  next = 1;

    ft_memset(buf, '.', 21);
    size = read(fd, buf, 20);
    if (size != 20)
        return (-1);
    buf[20] = '\0';
    next = 0;
    if (!(ft_strlen(buf) == 20 && ft_strcount(buf, '\n') == 4
        && ft_strcount(buf, '#') == 4 && ft_strcount(buf, '.') == 12))
        return (-1);
	if (!(*item = create_item(chr, buf)))
        return (-1);
    if (read(fd, buf, 1))
    {
        if (buf[0] == '\n')
            next = 1;
        else
            return (-1);
    }
    else
        next = 0;
    return (next);
}

t_list  *get_valid_items(int fd)
{
    int     state;
    t_list  *lst;
    t_list  *cur;
    t_item  *item;
    char    chr;

    chr = 'A' - 1;
    lst = NULL;
    item = NULL;
    state = 1;
    while (state)
    {
        state = read_valid_item(fd, ++chr, &item);
        if (state < 0 || !item->is_valid ||
            !(cur = ft_lstnew(item, sizeof(t_item))))
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

int main(int argc, char **argv)
{
    int     fd;
    t_list  *lst;

    if (argc == 2)
    {
        printf("%s\n", argv[1]);
        if ((fd = open(argv[1], O_RDONLY)) < 0)
            return (0);
            if (!(lst = get_valid_items(fd)))
            printf("error\n");
        else
            printf("valid\n");
    }
    return (0);
}

// int main(int argc, char **argv)
// {
//     int     fd;
//     int     size;
//     char    buf[21];
//     int     next;

// 	if (argc == 2)
// 	{
//         fd = open(argv[1], O_RDONLY);
//         next = 1;
//         ft_memset(buf, '.', 21);
//         while ((size = read(fd, buf, 20)))
//         {
//             if (size != 20)
//             {
//                 printf("invalid file\n");
//                 return (0);
//             }
//             buf[20] = '\0';
//             next = 0;
//             if (!(ft_strlen(buf) == 20 && ft_strcount(buf, '\n') == 4 && ft_strcount(buf, '#') == 4 && ft_strcount(buf, '.') == 12))
//             {
//                 printf("invalid string\n");
//                 return (0);
//             }
//             printf("valid:\n%s\n", buf);
//             if (read(fd, buf, 1))
//             {
//                 if (buf[0] == '\n')
//                     next = 1;
//                 else
//                 {
//                     printf("invalid space between items\n");
//                     return (0);
//                 }
//             }
//             else
//             {
//                 next = 0;
//             }
//             ft_memset(buf, '.', 21);
//         }
//         if (next)
//             printf("invalid end of file\n");
//         close(fd);
// 	}
// 	return (0);
// }
