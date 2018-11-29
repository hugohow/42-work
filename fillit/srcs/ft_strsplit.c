#include <string.h>
#include <stdlib.h>
#include <stdio.h>

size_t  ft_strlen(const char *str);

size_t   count_tetri(char const *str)
{
    size_t i;
    size_t count;

    i = 0;
    count = 1;
    while (str[i])
    {
        if (str[i + 1] && str[i] == '\n' && str[i + 1] == '\n')
            count++;
        i++;
    }
    return (count);
}

char    **ft_strsplit(char const *str)
{
    char **list;
    char *tetri;
    size_t str_len;
    size_t i;
    size_t j;
    size_t k;

    list = (char **)malloc((count_tetri(str) + 1) * sizeof(char *));
    if (list == NULL)
        return (NULL);
    i = 0;
    k = 0;
    str_len = ft_strlen(str);
    while (str[i])
    {
        if (str[i + 1] && str[i] != '\n' && str[i + 1] != '\n')
        {
            tetri = (char *)malloc((str_len + 1) * sizeof(char));
            if (tetri == NULL)
                return (NULL);
            j = 0;
            while (str[i])
            {
                tetri[j] = str[i] == '#' ? 'A' + k : str[i];
                if (str[i] == '\n' && str[i + 1] == '\n')
                    break;
                j++;
                i++;
            }
            tetri[j] = '\0';
            list[k++] = tetri;
        }
        else 
        {
            i++;
        }
    }
    list[k] = 0;
    return (list);
}