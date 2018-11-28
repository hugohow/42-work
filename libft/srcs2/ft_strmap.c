#include <string.h>
#include <stdlib.h>

size_t  ft_strlen(const char *str);

char *ft_strmap(char const *str, char (*f)(char))
{
    char *new_str;
    size_t i;

    new_str = malloc((ft_strlen(str) + 1) * sizeof(char));
    i = 0;
    while (str[i])
    {
        new_str[i] = (*f)(str[i]);
        i++;
    }
    new_str[i] = '\0';
    return (new_str);
}