
#include "shell.h"


int is_exit(char *cmd)
{
    int i;

    i = 0;
    while (cmd[i] && cmd[i] == ' ')
        i++;
    if (cmd[i] == 'e')
    {
        if (ft_strcmp(cmd + i, "exit") == 0 || ft_strcmp(cmd + i, "exit ") >= 0)
            return (1);
        else
            return (0);
    }
    return (0);
}


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

int list_size(char **list)
{
    int size;

    size = 0;
    while (list[size])
        size++;
    return (size);
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
        ft_echo(list_size(cmd_list), cmd_list, p_environ, fd0, fd1, fd2);
        return 0;
    }
    if (ft_strcmp(command, "cd") == 0)
    {
        return (ft_cd(list_size(cmd_list), cmd_list, p_environ));
    }
    if (ft_strcmp(command, "setenv") == 0)
    {
        ft_setenv(list_size(cmd_list), cmd_list, p_environ);
        return 0;
    }
    if (ft_strcmp(command, "unsetenv") == 0)
    {
        ft_unsetenv(list_size(cmd_list), cmd_list, p_environ);
        return 0;
    }
    if (ft_strcmp(command, "env") == 0)
    {
        return (ft_env(list_size(cmd_list), cmd_list, p_environ, p_orig_termios));
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

void ft_exit(char *cmd, int success, struct termios *p_orig_termios)
{
    char **cmd_list;
    int i;

    cmd_list = ft_strsplit(cmd, ' ');
    if (cmd_list[1])
    {
        if (cmd_list[2])
        {
            ft_putstr_fd("Too many arguments Argument list too long", 2);
            return ;
        }
        i = 0;
        while (cmd_list[1][i] && cmd_list[1][i] == ' ')
            i++;
        while (cmd_list[1][i])
        {
            if (ft_isdigit(cmd_list[1][i]) == 0)
            {
                ft_putstr_fd("Numeric argument required", 2);
                ft_exit_terminal(p_orig_termios);
                exit(-1);
            }
            i++;
        }
        ft_exit_terminal(p_orig_termios);
        exit(ft_atoi(cmd_list[1]));
    }   
    ft_exit_terminal(p_orig_termios);
    exit(success);
}



int main(int argc, char **argv)
{
    char *command;
    char **copy_env;
    int fd;
    int success;

    struct termios orig_termios;
    struct termios new_termios;


    
    if ((ft_init_terminal(&orig_termios, &new_termios)) < 0)
        return (-1);
    // if (signal(SIGPIPE, signal_callback_handler) == SIG_ERR)
    //     printf("\ncan't catch SIGWINCH\n");


    success = 0;
    copy_env = copy_environ((char **)environ);

    if (argc > 1 || isatty(0) == 0)
    {
        fd = isatty(0) == 0 ? 0 : open(argv[1], O_RDONLY);
        while (ft_ask_command(fd, &command, &orig_termios) != 0)
        {
            success = prepare_command(command, &copy_env, success, &orig_termios);
        }
    }
    else
    {
        while (42)
        {
            ft_ask_command(0, &command, &orig_termios);
            success = prepare_command(command, &copy_env, success, &orig_termios);
        }
    }
    return (success);
}
