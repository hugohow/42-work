
#include "minishell.h"

typedef struct s_token
{
    char* type;
    char* value;
}              t_token;


void print_tokens(t_token **list)
{
    int i;

    i = 0;
    while (list[i])
    {
        ft_printf("type : %s, value : %s\n", list[i]->type, list[i]->value);
        i++;
    }
}

int is_separator(char *str)
{
    if (str[0] && str[0] == ';')
        return (1);
    if (str[0] && str[0] == '<')
        return (1);
    return (0);
}

t_token **tokenize_command(char *cmd)
{
    t_token **list;
    t_token *token;
    int i;
    int k;
    int len;
    char *value;

    list = (t_token **)malloc(1000*sizeof(t_token *));
    i = 0;
    k = 0;
    while (cmd[i])
    {
        token = malloc(sizeof(t_token));
        if (is_separator(cmd + i) == 0)
        {
            value = malloc(((ft_strlen(cmd) + 1) * sizeof(char)));
            len = 0;
            while (cmd[i] && is_separator(cmd + i) == 0)
            {
                value[len] = cmd[i];
                len++;
                i++;
            }
            value[len] = '\0';
            token->value = value;
            token->type = "cmd";
            list[k] = token;
            k++;
        }
        else if (is_separator(cmd + i))
        {
            token->type = "separator";
            token->value = ft_strsub(cmd, i, 1);
            list[k] = token;
            k++;
            i++;
        }
    }
    list[k] = 0;
    print_tokens(list);
    return (list);
}

int execute_path(char *path, char **argv, char ***p_environ)
{
    pid_t pid;
    struct stat fileStat;

    // le fichier existe mais impossible d'avoir stat -> loop symbolic links
    if (stat(path, &fileStat) < 0)
    {
        ft_putstr_fd("Too many symbolic links\n", 2);
        return (-1);
    }
    if (access(path, X_OK) == -1)
    {
        ft_putstr_fd("Permission denied\n", 2);
        return (-1);
    }
    pid = fork();
    if (pid < 0) {
        ft_putstr("Failed to fork process 1\n");
        exit(1);
    }
    if (pid == 0)
    {
       execve(path, argv, *p_environ);
    }
    else
    {
        wait(NULL);
    }
    return (0);
}

int search_path_exe(char *cmd, char *path, char **argv, char ***p_environ)
{
    DIR *pDir;
    struct dirent *pDirent;
    char *new_path;
    int result;

    result = 0;
    (void)p_environ;
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
            argv[0] = pDirent->d_name;
            result = execute_path(new_path, argv, p_environ);
            closedir (pDir);
            return (result);
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

int execute_command(char *cmd, char **paths, char ***p_environ)
{
    int i;
    int result;
    i = 0;
    char **cmd_list;
    char *command;

    cmd_list = ft_strsplit(cmd, ' ');
    if (cmd_list[0] == NULL)
        return 0;
    command = ft_strtrim(cmd_list[0]);
    result = 0;
    if (is_path(command) == 1)
    {
        cmd_list[0] = "name";
        result = execute_path(command, cmd_list, p_environ);
        return (result);
    }
    if (ft_strcmp(command, "echo") == 0)
    {
        ft_echo(list_size(cmd_list), cmd_list);
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
        ft_env(list_size(cmd_list), cmd_list, p_environ);
        return 0;
    }
    if (ft_strcmp(command, "exit") == 0)
    {
        exit(0);
    }
    while (paths[i])
    {
        if (search_path_exe(command, paths[i], cmd_list, p_environ) == 0)
        {
            return (0);
        }
        i++;
    }
    if (paths[i] == 0)
    {
        ft_putstr_fd("minishell: command not found: ", 2);
        ft_putstr_fd(cmd, 2);
        ft_putstr_fd("\n", 2);
        return (1);
    }
    return (1);
}

int ask_command(int fd, char **command)
{
    if (fd == 0 && isatty(0) == 1)
        ft_putstr("$> ");
    return (get_next_line(fd, command));
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


int prepare_command(char *cmd, char **copy_env)
{
    t_token **list;
    int i;
    int success;

    list = tokenize_command(cmd);
    i = 0;
    success = 0;
    while (list[i])
    {
        if (ft_strcmp(list[i]->type, "separator") != 0)
            success = execute_command(list[i]->value, get_paths(copy_env), &copy_env);
        i++;
    }
    return (success);
}


int main(int argc, char **argv)
{
    char *command;
    char **copy_env;
    int fd;
    int *success;

    success = malloc(sizeof(int));
    *success = 0;
    copy_env = copy_environ((char **)environ);

    if (argc > 1 || isatty(0) == 0)
    {
        fd = isatty(0) == 0 ? 0 : open(argv[1], O_RDONLY);
        if (fd > 0)
        {
            while (ask_command(fd, &command) != 0)
            {
                *success = prepare_command(command, copy_env);
            }
        }
    }
    else
    {
        while (42)
        {
            ask_command(0, &command);
            *success = prepare_command(command, copy_env);
        }
    }
    return (*success);
}
