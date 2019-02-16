#include "ft_cd.h"


int is_file(char *path)
{
    struct stat fileStat;

    if (stat(path, &fileStat) < 0)
        return (-1);
    return (0);
}

int is_symlink(char *path)
{
    struct stat fileStat;

    if (lstat(path, &fileStat) < 0)
        return (0);
    if (S_ISLNK(fileStat.st_mode))
        return (1);
    return (0);
}

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

int change_env(char *new_pwd_line, char *old_pwd_line, char ***p_environ)
{
    if (change_line_env("OLDPWD", old_pwd_line, p_environ) == 0)
        return (-1);
    if (change_line_env("PWD", ft_strjoin("PWD=", new_pwd_line), p_environ) == 0)
        return (-1);
    return (0);
}

int go_to_root(char *old_pwd_line, char ***p_environ)
{
    while (ft_strcmp(get_path(BUF_SIZE), "/") != 0)
        chdir("..");

    if (change_env("/", old_pwd_line, p_environ) < 0)
        return (-1);
    return (0);
}

char *get_absolute_path(char *element)
{
    char *path;

    if (element[0] && element[0] == '/')
        return (element);
    path = ft_strjoin(get_path(BUF_SIZE), "/");
    path = ft_strjoin(path, element);
    return (path);
}

int ft_go_to(char *abs_path)
{
    struct stat fileStat;

    if (chdir(abs_path) < 0)
    {
        // si y'a un pb et que c'est un symbolic link
        if (stat(abs_path, &fileStat) < 0)
        {
            if (lstat(abs_path, &fileStat) == 0)
            {
                ft_putstr_fd("No such file or directory or Too many symbolic links\n", 2);
                return (-1);
            }
            else
            {
                ft_putstr_fd("No such file or directory\n", 2);
                return (-1);
            }
        }
        // is it a directory ?
        if (S_ISDIR(fileStat.st_mode) == 0)
        {
            ft_putstr_fd("not a directory !!!!! \n", 2);
            return (-1);
        }
        else
        {
            ft_putstr_fd("is a directory, but permission denied \n", 2);
            return (-1);
        }
    }
    return (0);
}

int ft_change_dir(char *element, char ***p_environ)
{
    char *abs_path;
    char *old_pwd_line;

    old_pwd_line = ft_strjoin("OLDPWD=", get_path(BUF_SIZE));

    // définition du chemin absolu
    if (element)
    {
        if (ft_strcmp(element, "/") == 0 || ft_strcmp(element, "/.") == 0)
            return (go_to_root(old_pwd_line, p_environ));
        if (ft_strcmp(element, "-") == 0)
            abs_path = get_line_env("OLDPWD", p_environ) + 7;
        else
            abs_path = get_absolute_path(element);
    }
    else
    {
        abs_path = get_line_env("HOME", p_environ) + 5;
    }


    // aller vers le chemin
    if (ft_go_to(abs_path) < 0)
        return (-1);

    // change env et return
    if (is_symlink(abs_path) == 1)
        return (change_env(abs_path, old_pwd_line, p_environ));
    return (change_env(get_path(BUF_SIZE), old_pwd_line, p_environ));
}

int ft_cd(int argc, char **argv, char ***p_environ)
{
    char *element;

    element = NULL;
    if (argc > 1)
        element = argv[1];

    return (ft_change_dir(element, p_environ));
}