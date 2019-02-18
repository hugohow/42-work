
#include "shell.h"


enum editorKey 
{
  ARROW_LEFT = 1000,
  ARROW_RIGHT,
  ARROW_UP,
  ARROW_DOWN
};

#define CTRL_J 10
#define CTRL_L ('l' & 0x1f)
#define CTRL_I 9
#define CTRL_K ('k' & 0x1f)

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


int execute_path(char *path, char **argv, char ***p_environ, int fd0, int fd1, int fd2)
{
    pid_t pid;
    struct stat fileStat;
    int waitstatus;
    int i;
    i = 0;
    // le fichier existe mais impossible d'avoir stat -> loop symbolic links
    if (stat(path, &fileStat) < 0)
    {
        ft_putstr_fd("Command not found\n", fd2);
        return (-1);
    }
    if (access(path, X_OK) == -1)
    {
        ft_putstr_fd("Permission denied\n", fd2);
        return (-1);
    }
    pid = fork();
    if (pid < 0) {
        ft_putstr_fd("Failed to fork process 1\n", fd2);
        exit(1);
    }
    if (pid == 0)
    {
        if (fd0 != 0)
        {
            dup2(fd0, STDIN_FILENO);    
            close(fd0);
        }
        if (fd1 != 1)
        {
            dup2(fd1, STDOUT_FILENO);
            close(fd1);
        }
        if (fd2 != 2)
        {
            dup2(fd2, STDERR_FILENO);
            close(fd2);
        }
        // dup2(fd0, STDIN_FILENO);
        // dup2(fd1, STDOUT_FILENO);
        // dup2(fd2, STDERR_FILENO);
        // close(fd0);
        // close(fd1);
        // close(fd2);
        execve(path, argv, *p_environ);
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
        result = execute_path(command, cmd_list, p_environ, fd0, fd1, fd2);
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
            result = execute_path(new_path, cmd_list, p_environ, fd0, fd1, fd2);
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

int is_quote_closed(char *cmd)
{
    int i;
    int count_opened;
    int count_closed;

    count_opened = 0;
    count_closed = 0;
    i = 0;
    while (cmd[i])
    {
        if (cmd[i] == '"')
        {
            count_opened++;
        }
        i++;
    }
    return (count_opened % 2 != 0);
}

char **list_historic;
int *k;


int ask_command(int fd, char **command, struct termios *p_orig_termios)
{
    int key;
    char *cmd;
    int index;
    int historic_index;
    int original_row;
    char *command_tmp;
    char *command_tmp1;

    if (list_historic == NULL)
        list_historic = malloc(999*sizeof(char *));
    if (k == NULL)
    {
        k = malloc(sizeof(int));
        *k = 0;
    }
    if (fd == 0 && isatty(0) == 1)
    {
        cmd = malloc(sizeof(char) * 2);
        cmd = "";
        ft_putstr("----------🍄---------------\n");
        print_cmd(cmd);
        if (get_pos(&index, &original_row) < 0)
            return (0);
        index = 0;
        historic_index = *k;
        // not enough !! for the simple ou double quote
        while (42)
        {
            key = ft_read_key();
            // printf("key : %d", key);
            if (key == 10)
            {
                // check if it's closed
                if (is_quote_closed(cmd) == 0)
                {
                    historic_index = *k + 1;
                    break;
                }
            }
            if (key == ('i' & 0x1f))
                ft_exit_terminal(p_orig_termios);
            if (key == ARROW_UP && historic_index - 1 >= 0)
            {
                // to clean
                if (cmd)
                    delete_n_lines(count_nb_line(cmd));
                cmd = list_historic[--historic_index];
                index = ft_strlen(cmd);
            }
            else if (key == ARROW_DOWN && historic_index < *k)
            {
                // to clean
                if (cmd)
                    delete_n_lines(count_nb_line(cmd));
                cmd = list_historic[++historic_index];
                index = ft_strlen(cmd);
            }
            add_to_stdout(&cmd, key, &index);
        }
        *command = cmd;
        list_historic[*k] = cmd;
        *k = *k + 1;
        list_historic[*k] = "";
        ft_putstr("\r\n");
        return (0);
    }
    int ret;
    command_tmp = malloc(9999*sizeof(char));
    ret = get_next_line(fd, &command_tmp);
    while (is_quote_closed(command_tmp) != 0 && ret >= 0)
    {
        ret = get_next_line(fd, &command_tmp1);
        command_tmp = ft_strjoin(command_tmp, "\n");
        command_tmp = ft_strjoin(command_tmp, command_tmp1);
    }
    *command = command_tmp;
    return (ret);
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
            success = prepare_command(command, &copy_env, success, &orig_termios);
        }
    }
    return (success);
}
