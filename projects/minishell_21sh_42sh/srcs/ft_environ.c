#include "ft_environ.h"

char **copy_environ(char **str)
{
    char **copy;
    int i;

    i = 0;
    while (str[i])
        i++;
    copy = (char **)malloc((i + 1) * sizeof(char *));
    i = 0;
    while (str[i])
    {
        copy[i] = str[i];
        i++;
    }
    copy[i] = 0;
    return (copy);
}

char **get_paths(char **copy_env)
{
    char *path_line;
    char **paths;

    path_line = get_line_env("PATH", &copy_env);
    if (path_line)
        path_line = ft_strjoin(get_line_env("PATH", &copy_env), ":.") + 5;
    else
        path_line = "/usr/sbin:/usr/bin:/sbin:/bin:.";
    paths = ft_strsplit(path_line, ':');
    return (paths);
}