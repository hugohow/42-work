#include <string.h>
#include <stdlib.h>

void    ft_memdel(void **ap)
{
    if (ap == NULL)
       return ;
    free(*ap);
    *ap = NULL;
}