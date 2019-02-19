#include "ft_execute_cmd.h"

char *search_path_exe(char *cmd, char *path, char ***p_environ)
{
    DIR *pDir;
    struct dirent *pDirent;
    int result;

    result = 0;
    (void)p_environ;
    if (path == NULL)
        return (NULL);
    if ((pDir = opendir (path)) == NULL)
    {
        return (NULL);
    }
    while ((pDirent = readdir(pDir)) != NULL) 
    {
        if (ft_strcmp(pDirent->d_name, cmd) == 0)
        {
            closedir (pDir);
            return (pDirent->d_name);
        }
    }
    closedir (pDir);
    return (NULL);
}

int is_path(char *cmd)
{
    int i;

    i = 0;
    while (cmd[i])
    {
        if (cmd[i] == '/')
            return (1);
        i++;
    }
    return (0);
}

int execute_command(char *cmd, char **paths, char ***p_environ, struct termios *p_orig_termios, int fd0, int fd1, int fd2)
{
    int i;
    int result;
    i = 0;
    char **cmd_list;
    char *command;
    char *new_path;
    char *d_name;

    cmd_list = ft_strsplit(cmd, ' ');
    if (cmd_list[0] == NULL)
        return 0;
    command = ft_strtrim(cmd_list[0]);
    result = 0;
    new_path = NULL;
    if (is_path(command) == 1)
    {
        cmd_list[0] = "name";
        result = ft_execute_path(command, cmd_list, p_environ, fd0, fd1, fd2);
        return (result);
    }
    if (ft_strcmp(command, "echo") == 0)
    {
        ft_echo(ft_list_size(cmd_list), cmd_list, p_environ, fd0, fd1, fd2);
        return 0;
    }
    if (ft_strcmp(command, "cd") == 0)
    {
        return (ft_cd(ft_list_size(cmd_list), cmd_list, p_environ));
    }
    if (ft_strcmp(command, "setenv") == 0)
    {
        ft_setenv(ft_list_size(cmd_list), cmd_list, p_environ);
        return 0;
    }
    if (ft_strcmp(command, "unsetenv") == 0)
    {
        ft_unsetenv(ft_list_size(cmd_list), cmd_list, p_environ);
        return 0;
    }
    if (ft_strcmp(command, "env") == 0)
    {
        return (ft_env(ft_list_size(cmd_list), cmd_list, p_environ, p_orig_termios));
    }
    while (paths[i])
    {
        if ((d_name = search_path_exe(command, paths[i], p_environ)) != NULL)
        {
            new_path = ft_strjoin(paths[i], "/");
            new_path = ft_strjoin(new_path, d_name);
            cmd_list[0] = d_name;
            result = ft_execute_path(new_path, cmd_list, p_environ, fd0, fd1, fd2);
            return (result);
        }
        i++;
    }
    if (paths[i] == 0)
    {
        ft_putstr_fd("shell: command not found: ", fd2);
        ft_putstr_fd(cmd, fd2);
        ft_putstr_fd("\n", fd2);
        return (1);
    }
    return (1);
}