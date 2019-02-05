#include "ft_cd.h"

char *get_path(size_t size)
{
    char *path;
    char *cwd;

    path = malloc((size) * sizeof(char));

    cwd = getcwd(path, size);
    if (cwd == NULL)
        return (get_path(size * 2));
    return (path);
}


int ft_cd(int argc, char **argv, char ***p_environ)
{
    char *path;

    if (argc && argv[1])
    {
        path = ft_strjoin(get_path(BUF_SIZE), "/");
        path = ft_strjoin(path, argv[1]);
    }
    else
    {
        path = get_line_env("HOME", p_environ) + 5;
    }
    if (chdir(path) < 0)
        ft_printf("cd: no such file or directory: %s\n", argv[1]);
    return (0);
}