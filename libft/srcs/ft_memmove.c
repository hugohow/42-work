#include <string.h>
#include <stdlib.h>
#define UNUSED(x) (void)(x)

int     ft_strlen(char *str);
char    *ft_strcpy(char *dst, const char *src);


void    *ft_memmove(void *dst, const void *src, size_t len)
{
    size_t i;
    char *original_dst;
    char *original_src;

    original_dst = (char *)malloc((ft_strlen((char *)dst) + 1) * sizeof(char));
    if (original_dst == NULL)
        return (original_dst);
    original_dst = ft_strcpy(original_dst, (char *)dst);
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