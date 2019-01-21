
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

void execute_command(char *cmd, char **paths)
{
    int i;

    i = 0;
    char **cmd_list;

    cmd_list = ft_strsplit(cmd, ' ');
    if (cmd_list[0] == NULL)
        return ;
    if (ft_strcmp(cmd_list[0], "echo") == 0)
    {
        ft_echo(list_size(cmd_list), cmd_list);
        return ;
    }
    while (paths[i])
    {
        if (search_path_exe(cmd_list[0], paths[i], cmd_list) == 0)
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

int main()
{
    char *command;
    char **paths;
    int i;

    i = 0;
    while (environ[i])
    {
        if (environ[i][0] == 'P' && environ[i][1] == 'A' && environ[i][2] == 'T' && environ[i][3] == 'H')
        {
            paths = ft_strsplit(environ[i] + 5, ':');
            i = 0;
            while (paths[i])
            {
                // ft_printf("%s\n", paths[i]);
                i++;
            }
            break;
        }
        i++;
    }
    while (ft_strcmp(command, "exit"))
    {
        ask_command(&command);
        execute_command(command, paths);
        // ft_printf("command : %s\n", command);
    }
    return (0);
}