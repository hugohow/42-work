
#include "minishell.h"

int search_path_exe(char *cmd, char *path, char **argv)
{
    DIR *pDir;
    struct dirent *pDirent;
    char *new_path;
    pid_t pid;

    if (path == NULL)
        return (-1);
    if ((pDir = opendir (path)) == NULL)
    {
        return (-1);
    }
    while ((pDirent = readdir(pDir)) != NULL) 
    {
        if (ft_strcmp(pDirent->d_name, cmd) == 0)
        {
            new_path = ft_strjoin(path, "/");
            new_path = ft_strjoin(new_path, pDirent->d_name);
            pid = fork();
            if (pid < 0) {
                ft_printf("Failed to fork process 1\n");
                exit(1);
            }
            if (pid == 0)
            {
                execve(new_path, argv, environ);
            }
            else
            {
                wait(NULL);
            }
            closedir (pDir);
            return (0);
        }
    }
    closedir (pDir);
    return (-1);
}

int list_size(char **list)
{
    int size;

    size = 0;
    while (list[size])
        size++;
    return (size);
}

void execute_command(char *cmd, char **paths, char ***p_environ)
{
    int i;

    i = 0;
    char **cmd_list;
    char *command;

    cmd_list = ft_strsplit(cmd, ' ');
    if (cmd_list[0] == NULL)
        return ;
    command = ft_strtrim(cmd_list[0]);
    if (ft_strcmp(command, "echo") == 0)
    {
        ft_echo(list_size(cmd_list), cmd_list);
        return ;
    }
    if (ft_strcmp(command, "cd") == 0)
    {
        ft_cd(list_size(cmd_list), cmd_list, p_environ);
        return ;
    }
    if (ft_strcmp(command, "setenv") == 0)
    {
        ft_setenv(list_size(cmd_list), cmd_list, p_environ);
        return ;
    }
    if (ft_strcmp(command, "unsetenv") == 0)
    {
        ft_unsetenv(list_size(cmd_list), cmd_list, p_environ);
        return ;
    }
    if (ft_strcmp(command, "env") == 0)
    {
        ft_env(list_size(cmd_list), cmd_list, p_environ);
        return ;
    }
    while (paths[i])
    {
        if (search_path_exe(command, paths[i], cmd_list) == 0)
            break;
        i++;
    }
    if (paths[i] == 0)
    {
        ft_printf("minishell: command not found: %s\n", cmd);
    }
}

int ask_command(char **command)
{
    ft_printf("$> ");
    return (get_next_line(1, command));
}

char **copy_environ(char **environ)
{
    char **copy;
    int i;

    i = 0;
    while (environ[i])
        i++;
    copy = (char **)malloc((i + 1) * sizeof(char *));
    i = 0;
    while (environ[i])
    {
        copy[i] = environ[i];
        i++;
    }
    copy[i] = 0;
    return (copy);
}


int main()
{
    char *command;
    char **paths;
    char **copy_env;

    copy_env = copy_environ((char **)environ);
    paths = ft_strsplit(get_line_env("PATH", copy_env) + 5, ':');
    while (1)
    {
        ask_command(&command);
        execute_command(command, paths, &copy_env);
        // ft_printf("command : %s\n", command);
    }
    return (0);
}