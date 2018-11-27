#include <string.h>
#include <stdlib.h>
#define UNUSED(x) (void)(x)

size_t  ft_strlen(const char *str);
char    *ft_strcpy(char *dst, const char *src);


void    *ft_memmove(void *dst, const void *src, size_t len)
{
    size_t i;
    char *original_src;

    original_src = (char *)malloc((ft_strlen((char *)src) + 1) * sizeof(char));
    if (original_src == NULL)
        return (original_src);
    original_src = ft_strcpy(original_src, (char *)src);
    i = 0;
    while (i < len)
    {
        *(char*)(dst + i) = *(char*)(original_src + i);
        i++;
    }
    return (dst);
}