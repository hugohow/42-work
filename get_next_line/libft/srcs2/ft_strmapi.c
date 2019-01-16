#include <string.h>
#include <stdlib.h>

size_t  ft_strlen(const char *str);

char *ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
    char        *new_str;
    unsigned int i;

    if (str == NULL)
		return (NULL);
    new_str = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
    if (new_str == NULL)
        return (NULL);
    i = 0;
    while (str[i])
    {
        new_str[i] = (*f)(i, str[i]);
        i++;
    }
    new_str[i] = '\0';
    return (new_str);
}