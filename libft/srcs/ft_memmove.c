#include <string.h>
#include <stdlib.h>

size_t  ft_strlen(const char *str);

void    *ft_memmove(void *dst, const void *src, size_t len)
{
    size_t i;

    if (dst == src || len == 0)
        return (dst);
    if (dst < src)
    {
        i = 0;
        while (i < len && ((unsigned char *)src)[i])
        {
            ((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
            i++;
        }
    }
    else
    {
        i = len - 1;
        while (1)
        {
            ((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
            if (i == 0)
              break;
            i--;
        }
    }
    return (dst);
}