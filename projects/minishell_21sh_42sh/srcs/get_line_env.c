#include "get_line_env.h"

char *get_line_env(char *str, char ***p_environ)
{
    size_t i;
    size_t j;

    i = 0;
    while ((*p_environ)[i])
    {

        if ((*p_environ)[i][0] == str[0])
        {
            j = 0;
            while (str[j] && (*p_environ)[i][j] && (*p_environ)[i][j] == str[j])
            {
                j++;
            }
            if (j == ft_strlen(str))
                return ((*p_environ)[i]);
        }
        i++;
    }
    return (NULL);
}

int change_line_env(char *key, char *line, char ***p_environ)
{
    size_t i;
    size_t j;
    char **envp;

    envp = *p_environ;
    i = 0;
    while (envp[i])
    {
        if (envp[i][0] == key[0])
        {
            j = 0;
            while (key[j] && envp[i][j] && envp[i][j] == key[j])
            {
                j++;
            }
            if (j == ft_strlen(key))
            {
                *(envp + i) = line;
                *p_environ = envp;
                return (1);
            }
        }
        i++;
    }
    return (0);
}

int delete_line_env(char *key, char ***p_environ)
{
    size_t i;
    size_t j;
    size_t k;
    char **envp;

    envp = *p_environ;
    i = 0;
    while (envp[i])
    {

        if (envp[i][0] == key[0])
        {
            j = 0;
            while (key[j] && envp[i][j] && envp[i][j] == key[j])
            {
                j++;
            }
            if (j == ft_strlen(key))
            {
                k = i + 1;
                while (envp[k])
                {
                    envp[k - 1] = envp[k];
                    k++;
                }
                envp[k - 1] = envp[k];
                *p_environ = envp;
                return (1);
            }
        }
        i++;
    }
    *p_environ = envp;
    return (0);
}