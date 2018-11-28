#include <string.h>
#include <stdlib.h>

void    ft_memdel(void **ap)
{
    free(*ap);
    *ap = NULL;
}