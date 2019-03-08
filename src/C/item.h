#include <stdlib.h>

typedef struct  s_point
{
    char        i;
    char        j;
}               t_point;

typedef struct  s_item
{
    short       posi;
    short       posj;
    char        chr;
    char        is_valid;
    char        *data[4];
    t_point     points[4];
}               t_item;

t_item          *create_item(char chr, const char *src);