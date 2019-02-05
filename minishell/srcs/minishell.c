
#include "minishell.h"

typedef struct s_token
{
    char* type;
    char* value;
}           t_token;


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
    // print_tokens(list);
    return (list);
}

void execute_path(char *path, char **argv, char ***p_environ)
{
    pid_t pid;

    pid = fork();
    if (pid < 0) {
        ft_printf("Failed to fork process 1\n");
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
}

int search_path_exe(char *cmd, char *path, char **argv, char ***p_environ)
{
    DIR *pDir;
    struct dirent *pDirent;
    char *new_path;

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
            execute_path(new_path, argv, p_environ);
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
    if (is_path(command) == 1)
    {
        cmd_list[0] = "name";
        execute_path(command, cmd_list, p_environ);
        return ;
    }
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
    if (ft_strcmp(command, "exit") == 0)
    {
        exit(0);
        return ;
    }
    while (paths[i])
    {
        if (search_path_exe(command, paths[i], cmd_list, p_environ) == 0)
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


int main()
{
    char *command;
    char **paths;
    char **copy_env;
    t_token **list;
    int i;
    
    copy_env = copy_environ((char **)environ);
    paths = ft_strsplit(get_line_env("PATH", &copy_env) + 5, ':');
    while (1)
    {
        copy_env = copy_environ((char **)environ);
        paths = ft_strsplit(get_line_env("PATH", &copy_env) + 5, ':');
        ask_command(&command);
        list = tokenize_command(command);
        i = 0;
        while (list[i])
        {
            if (ft_strcmp(list[i]->type, "separator") != 0)
            {
                execute_command(list[i]->value, paths, &copy_env);
                break;
            }
            i++;
        }
    }
    return (0);
}