
#include "shell.h"

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
            if (is_exit(value) == 1)
                token->type = "exit";
            else
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

int execute_path(char *path, char **argv, char ***p_environ)
{
    pid_t pid;
    struct stat fileStat;
    int waitstatus;
    int i;
    // le fichier existe mais impossible d'avoir stat -> loop symbolic links
    if (stat(path, &fileStat) < 0)
    {
        ft_putstr_fd("Command not found\n", 2);
        return (-1);
    }
    if (access(path, X_OK) == -1)
    {
        ft_putstr_fd("Permission denied\n", 2);
        return (-1);
    }
    pid = fork();
    if (pid < 0) {
        ft_putstr_fd("Failed to fork process 1\n", 2);
        exit(1);
    }
    if (pid == 0)
    {
       execve(path, argv, *p_environ);
        //  en cas d'erreur
       exit(1);
    }
    else
    {
        wait(&waitstatus);
        i = WEXITSTATUS(waitstatus);
    }
    return (i);
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

int execute_command(char *cmd, char **paths, char ***p_environ, struct termios *p_orig_termios)
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
        return (ft_env(list_size(cmd_list), cmd_list, p_environ, p_orig_termios));
    }
    while (paths[i])
    {
        if ((d_name = search_path_exe(command, paths[i], p_environ)) != NULL)
        {
            new_path = ft_strjoin(paths[i], "/");
            new_path = ft_strjoin(new_path, d_name);
            cmd_list[0] = d_name;
            result = execute_path(new_path, cmd_list, p_environ);
            return (result);
        }
        i++;
    }
    if (paths[i] == 0)
    {
        ft_putstr_fd("shell: command not found: ", 2);
        ft_putstr_fd(cmd, 2);
        ft_putstr_fd("\n", 2);
        return (1);
    }
    return (1);
}



int ask_command(int fd, char **command, struct termios *p_orig_termios)
{
    int c;
    char *cmd;
    if (fd == 0 && isatty(0) == 1)
    {
        print_bold_green(1);
        ft_putstr("$> ");
        print_normal(1);
        cmd = malloc(sizeof(char) * 2);
        cmd = "";
        while (42)
        {
            c = ft_read_key();
            if (c == ('c' & 0x1f))
            {
                ft_exit_terminal(p_orig_termios);
            }
            else if (c == 13)
            {
                *command = cmd;
                ft_putstr("\r\n");
                return (0);
            }
            char str[2];
            str[0] = c;
            str[1] = '\0';
            cmd = ft_strjoin(cmd, str);
            ft_putchar(c);

        }
    }
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


int prepare_command(char *cmd, char ***copy_env, int prev_res, struct termios *p_orig_termios)
{
    t_token **list;
    int i;
    int success;

    list = tokenize_command(cmd);
    i = 0;
    success = prev_res;
    while (list[i])
    {
        if (ft_strcmp(list[i]->type, "exit") == 0)
            ft_exit(list[i]->value, success, p_orig_termios);
        else if (ft_strcmp(list[i]->type, "separator") != 0)
            success = execute_command(list[i]->value, get_paths(*copy_env), copy_env, p_orig_termios);
        i++;
    }
    return (success);
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

    success = 0;
    copy_env = copy_environ((char **)environ);

    if (argc > 1 || isatty(0) == 0)
    {
        fd = isatty(0) == 0 ? 0 : open(argv[1], O_RDONLY);
        while (ask_command(fd, &command, &orig_termios) != 0)
        {
            success = prepare_command(command, &copy_env, success, &orig_termios);
        }
    }
    else
    {
        while (42)
        {
            ask_command(0, &command, &orig_termios);
            ft_putstr("\r");
            success = prepare_command(command, &copy_env, success, &orig_termios);
            ft_putstr("\r");
        }
    }
    return (success);
}
