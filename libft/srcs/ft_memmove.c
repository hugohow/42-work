#include <string.h>
#include <stdlib.h>

size_t  ft_strlen(const char *str);

void    *ft_memmove(void *dst, const void *src, size_t len)
{
    size_t i;
    unsigned char *scr_cpy;

    scr_cpy = (unsigned char *)src;
    if (dst == src || len == 0)
        return (dst);
    i = (dst < src) ? 0 : len - 1;
    if (dst < src)
    {
        while (i < len && scr_cpy[i])
        {
            ((unsigned char *)dst)[i] = scr_cpy[i];
            i++;
        }
    }
    else
    {
        while (1)
        {
            ((unsigned char *)dst)[i] = scr_cpy[i];
            if (i == 0)
              break;
            i--;
        }
    }
    return (dst);
}