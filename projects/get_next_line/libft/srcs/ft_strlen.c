#include <string.h>

size_t ft_strlen(const char *str)
{
    size_t length;

    length = 0;
    while(str[length])
        length++;
    return (length);
}