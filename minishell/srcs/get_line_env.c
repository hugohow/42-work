#include "get_line_env.h"

char *get_line_env(char *str)
{
    size_t i;
    size_t j;

    i = 0;
    while (environ[i])
    {

        if (environ[i][0] == str[0])
        {
            j = 0;
            while (str[j] && environ[i][j] && environ[i][j] == str[j])
            {
                j++;
            }
            if (j == ft_strlen(str))
                return (environ[i]);
        }
        i++;
    }
    return (NULL);
}