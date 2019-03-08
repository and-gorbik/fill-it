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
    i = -1;
    while (matrix[++i])
    {
        if (ft_strlen(matrix[i]) != 4)
        {
            while (*matrix)
            {
                free(*matrix);
                ++matrix;
            }
            free(matrix);
            return (NULL);
        }
    }
    return (matrix);
}

t_point     _get_offset(char **matrix)
{
    int di;
    int dj;
    int i;
    int j;

    i = 0;
    while (i < 4)
    
}

static void _set_points(t_item *item, char **matrix)
{
    t_point offset;
    char    *s;
    int     i;
    int     k;

    if (!matrix)
    {
        item->is_valid = 0;
        return ;
    }
    offset = _get_offset(matrix);
    k = -1;
    i = -1;
    while (matrix[++i])
    {
        ft_strchr(matrix[i], '#');
    }
    while (*matrix)
    {
        free(*matrix);
        ++matrix;
    }
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
    i = -1;
    while (++i < 4)
    {
        t_point cur = item->points[i];
        j = -1;
        while (++j < 4)
        {
            t_point other = item->points[j];
            counter += (cur.j - 1 >= 0 && other.i == cur.i && other.j == cur.j - 1);
            counter += (cur.i - 1 >= 0 && other.i == cur.i - 1 && other.j == cur.j);
            counter += (cur.j + 1 < 4 && other.i == cur.i && other.j == cur.j + 1);
            counter += (cur.i + 1 < 4 && other.i == cur.i + 1 && other.j == cur.j);
        }
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