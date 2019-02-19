#include "ft_list_size.h"

int ft_list_size(char **list)
{
    int size;

    size = 0;
    while (list[size])
        size++;
    return (size);
}