#include <string.h>
#include <stdlib.h>

void    *ft_memset(void *b, int c, size_t len);

void *ft_memalloc(size_t size)
{
    void *mem;

    mem = malloc(size);
    if (mem == NULL)
        return (NULL);
    mem = ft_memset(mem, 0, size);
    return (mem);
}