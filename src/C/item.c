#include "item.h"

/* TODO: add to libft */
static int  ft_strcount(const char *s, char chr)
{
    int counter;

    counter = 0;
    while (*s)
    {
        if (*s == chr)
            ++counter;
        ++s;
    }
    return (counter);
}

static char **_to_matrix(const char *s)
{
    char    **matrix;
    int     i;

    if (!(matrix = ft_strsplit(s, '\n')))
        return (NULL);
    i = 0;
    while (matrix[i])
    {
        if (ft_strlen(matrix[i]) != 4)
        {
            while (*matrix)
                free(*matrix++);
            free(matrix);
            return (NULL);
        }
        ++i;
    }
    return (matrix);
}

t_point     _get_offset(char **matrix)
{
    t_point offset;
    int     i;
    char    *ptr;

    offset.i = 0;
    offset.j = 4;
    i = 0;
    while (matrix[i])
    {
        ptr = ft_strchr(matrix[i], '#');
        if (ptr - matrix[i] < offset.j)
            offset.j = ptr - matrix[i];
        if (!ptr)
            offset.i += 1;
        ++i;
    }
    return (offset);
}

static void _set_points(t_item *item, char **matrix)
{
    t_point offset;
    int     i;
    int     k;

    if (!matrix)
    {
        item->is_valid = 0;
        return ;
    }
    offset = _get_offset(matrix);
    k = 0;
    i = 0;
    while (matrix[i / 4][i % 4])
    {
        if (matrix[i / 4][i % 4] == '#')
        {
            item->points[k].i = i / 4 - offset.i;
            item->points[k].j = i % 4 - offset.j;
            ++k;
        }
        ++i;
    }
    while (*matrix)
        free(*matrix++);
    free(matrix);
}

static void _validate_item(t_item *item)
{
    int     counter;
    int     i;
    int     j;

    if (!item->is_valid)
        return;
    counter = 0;
    i = 0;
    while (i < 4)
    {
        t_point cur = item->points[i];
        j = 0;
        while (j < 4)
        {
            t_point other = item->points[j];
            counter += (cur.j - 1 >= 0 && other.i == cur.i && other.j == cur.j - 1);
            counter += (cur.i - 1 >= 0 && other.i == cur.i - 1 && other.j == cur.j);
            counter += (cur.j + 1 < 4 && other.i == cur.i && other.j == cur.j + 1);
            counter += (cur.i + 1 < 4 && other.i == cur.i + 1 && other.j == cur.j);
            ++j;
        }
        ++i;
    }
    if (counter < 6)
        item->is_valid = 0;
}

t_item      *create_valid_item(char chr, const char *src)
{
    t_item  *item;
    size_t  i;

    if (!(item = malloc(sizeof(t_item))))
        return NULL;
    item->chr = chr;
    item->posi = 0;
    item->posj = 0;
    item->is_valid = (ft_strlen(src) == 20 && ft_strcount(src, '\n') == 4 &&
                    ft_strcount(src, '#') == 4 && ft_strcount(src, '.') == 12);
    _set_points(item, _to_matrix(src));
    _validate_item(item);
    if (!item->is_valid)
    {
        free(item);
        return (NULL);
    }
    return (item);
}