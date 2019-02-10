#include <string.h>
#include <stdlib.h>

size_t  ft_strlen(const char *str);

char *ft_strsub(char const *str, unsigned int start, size_t len)
{
    char *new_str;
    size_t i;

    if (str == NULL)
        return (NULL);
    if (len + start > ft_strlen(str))
        return (NULL);
    new_str = malloc((len + 1) * sizeof(char));
    if (new_str == NULL)
        return (NULL);
    i = start;
    while (i - start != len)
    {
        new_str[i - start] = str[i];
        i++;
    }
    new_str[len] = '\0';
    return (new_str);
}
