#include <string.h>
#include <stdlib.h>

size_t  ft_strlen(const char *str);

char *ft_strtrim(char const *str)
{
    char *new_str;
    size_t i;
    size_t j;
    size_t nb_spaces;

    new_str = malloc((ft_strlen(str) + 1) * sizeof(char));
    if (new_str == NULL)
        return (NULL);
    i = 0;
    j = 0;
    nb_spaces = 0;
    while (str[i])
    {
        if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
        {
            nb_spaces++;
            i++;
        }    
        else
            new_str[j++] = str[i++];
    }
    new_str[j] = '\0';
    if (nb_spaces == 0)
        return ((char *)str);
    return (new_str);
}
