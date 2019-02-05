#include <string.h>

void    *ft_memset(void *b, int c, size_t len);

void    ft_bzero(void *s, size_t n)
{
    ft_memset(s, 0, n);
}
