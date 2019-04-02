#include "ft_setenv.h"


void ft_setenv_args(char *prefix, char *line, char ***p_environ)
{
    char **new_environ;
    char *env_line;
    int i;

    new_environ = NULL;
    env_line = ft_strjoin(prefix, "=");
    if (line == NULL)
        env_line = ft_strjoin(env_line, "");
    else
        env_line = ft_strjoin(env_line, line);
    if (change_line_env(prefix, env_line, p_environ) == 0)
    {
        new_environ = (char **)malloc((ft_list_size(*p_environ) + 2) * sizeof(char *));
        i = 0;
        while (i < ft_list_size(*p_environ))
        {
            new_environ[i] = (*p_environ)[i];
            i++;
        }
        new_environ[i++] = env_line;
        new_environ[i] = 0;
        *p_environ = new_environ;
    }
}

int ft_setenv(int argc, char **argv, char ***p_environ)
{
    if (argc > 3)
    {
        ft_putstr_fd("setenv: Too many arguments.\n", 2);
        return (0);
    }
    if (argc == 1)
    {
        ft_print_env(*p_environ);
        return (0);
    }
    if (ft_isdigit(argv[1][0]))
    {
        ft_putstr_fd("not valid. must begin with a letter\n", 2);
        return (-1);
    }
    if (argc == 2)
    {
        int i;

        i = 0;
        while (argv[1][i] && argv[1][i] != '=')
            i++;
        ft_setenv_args(ft_strsub(argv[1], 0, i), argv[1] + i + 1, p_environ);
    }
    else
    {
        ft_setenv_args(argv[1], argv[2], p_environ);
    }

    return (0);
}