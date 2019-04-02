#include "prepare_command.h"

typedef struct s_node
{
    char *type;
    char *cmd;
    // pour la redirection
    int nb_pipe;
    int fd_origin;
    char *file_name;
    struct s_node **child;
}              t_node;


t_node **get_child(char *cmd);
t_node *create_node(char *type, char *cmd);
void    print_tree(t_node *node);

int is_separator(char *str);
int is_redirection(char *str);
int is_pipe(char *str);
void print_tokens(t_token **list);


t_node *create_node(char *type, char *cmd)
{
    t_node *node;

    node = malloc(sizeof(t_node));
    node->type = type;
    node->cmd = cmd;
    // if type pipe;
    // only 2 child
    if (ft_strcmp(type, "cmd") == 0 || type[0] == 'r')
    {
        node->child = NULL;
        return (node);
    }
    node->child = get_child(cmd);
    if (node->child == NULL)
    {
        node->child = malloc(sizeof(t_node *) * 2);
        node->child[0] = create_node("cmd", cmd);
        node->child[1] = 0;
    }
    return (node);
}

int find_len_par(char *cmd)
{
    
    int len;
    int count;

    // we can check if it's valid or not first

    len = 0;
    count = 0;
    while (cmd[len])
    {
        if (cmd[len] == ')' && count == 1)
            return (len);
        if (cmd[len] == '(')
            count++;
        if (cmd[len] == ')' && count != 1)
            count--;
        len++;
    }
    return (-1);
}


t_node **get_parentheses_child(char *cmd)
{
    // cherche les paranthèses
    int i;
    int j;
    int k;
    t_node **child;
    char *tmp;
    char **list;

    list = malloc(999*sizeof(char *));
    k = 0;
    i = 0;
    while (cmd[i])
    {
        while (cmd[i] && cmd[i] != '(')
        {
            j = 0;
            tmp = malloc(999*sizeof(char));
            tmp[j] = cmd[i];
            tmp[j] = '\0';
            list[k] = tmp;
            k++;
            j++;
            i++;
        }
        if (cmd[i] && cmd[i] == '(')
        {
            size_t len;

            len = find_len_par(cmd + i);
            list[k] = ft_strsub(cmd, i + 1, len - 1);
            k++;
            i += len - 1;
        }
    }
    list[k] = 0;
    if (k == 1)
        return (NULL);
    child = malloc((k + 1) * sizeof(t_node *));
    k = 0;
    while (list[k])
    {
        child[k] = create_node("base", list[k]);
        k++;
    }
    child[k] = 0;
    return (child);
}


t_node **get_semi_colon_child(char *cmd)
{
    char **list;
    int k;
    t_node **child;

    list = ft_strsplit(cmd, ';');
    k = 0;
    child = NULL;
    if (list[0] && list[1])
    {
        child = malloc(999*sizeof(t_node *));
        while (list[k])
        {
            child[k] = create_node("semi_colon", list[k]);
            k++;
        }
        child[k] = 0;
    }
    if (k == 0)
        return (NULL);
    return (child);
}

t_node **get_pipe_child(char *cmd)
{
    char **list;
    int k;
    int nb_pipe;
    t_node **child;

    list = ft_strsplit(cmd, '|');
 
    child = malloc(999*sizeof(t_node *));
    k = 0;
    nb_pipe = 0;
    if (list[0] && list[1])
    {
        while (list[k])
        {
            nb_pipe++;
            k++;
        }
    }
    k = 0;
    if (list[0] && list[1])
    {
        while (list[k])
        {
            child[k] = create_node("pipe", list[k]);
            child[k]->nb_pipe = nb_pipe;
            k++;
        }
    }
    child[k] = 0;
    if (k == 0)
        return (NULL);
    return (child);
}

int is_redirection_op(char *cmd, int *fd, int *len)
{
    int i;

    if (fd != NULL && len != NULL)
    {
        *len = 0;
    }
    i = 0;
    if (cmd[i] && is_digit(cmd[i]))
    {
        if (fd != NULL && len != NULL)
        {
            *fd = cmd[i] - '0';
            *len = 1;
        }
        i++;
    }
    if (cmd[i] && cmd[i] == '>')
    {
        if (cmd[i + 1] && cmd[i + 1] == '>')
        {
            if (len)
                *len = *len + 2;
            return (2);
        }
        if (len)
            *len = *len + 1;
        return (1);
    }
    if (cmd[i] && cmd[i] == '<')
    {
        if (cmd[i + 1] && cmd[i + 1] == '<')
        {
            if (len)
                *len = *len + 2;
            return (4);
        }
        if (len)
            *len = *len + 1;
        return (3);
    }

    return (0);
}

t_node **get_redirection_child(char *cmd)
{
    int k;
    int i;
    int j;
    int ret;
    t_node **child;
    int len;
    int fd_origin;

    child = NULL;
    ret = 0;
    k = 0;
    i = 0;
    child = malloc(10 *sizeof(t_node *));
    len = 0;
    fd_origin = -1;
    char *command;

    command = NULL;
    while (cmd[i])
    {
        if ((ret = is_redirection_op(cmd + i, &fd_origin, &len)) > 0)
        {
            if (command == NULL)
                command = ft_strsub(cmd, 0, i);
            i += len;
            j = i;
            while (cmd[j] && is_redirection_op(cmd + j, NULL, NULL) == 0)
            {
                j++;
            }
            child[k] = create_node(ft_strjoin("redirection ", ft_itoa(ret)), command);
            child[k]->file_name = ft_strtrim(ft_strsub(cmd, i, j - i));
            child[k]->fd_origin = fd_origin;
            k++;
            i = j - 1;
        }
        i++;
    }
    child[k] = 0;
    if (k == 0)
        return (NULL);
    return (child);
}

t_node **get_child(char *cmd)
{
    t_node **child;

    // la recherche de paranthses doit se faire à chaque étape

    // on décompose en fonction de la semi colon
    child = get_semi_colon_child(cmd);
    if (child == NULL)
    {
        // alors on décompose en fonction du pipe
        child = get_pipe_child(cmd);
    } 
    if (child == NULL)
    {
        // on décompose en fonction de la redirection
        child = get_redirection_child(cmd);
    }

    return (child);
}


int get_fd(char *file_name)
{
    int fd;

    //    O_RDONLY        open for reading only
    //    O_WRONLY        open for writing only
    //    O_RDWR          open for reading and writing
    //    O_NONBLOCK      do not block on open or for data to become available
    //    O_APPEND        append on each write
    //    O_CREAT         create file if it does not exist

    fd = open(file_name, O_RDWR | O_CREAT, 0777);

    return (fd);
}

void    execute_tree(t_node *node, char **paths, char ***p_environ, struct termios *p_orig_termios, int fd0, int fd1, int fd2, int *p_success)
{
    if (ft_strcmp(node->type, "cmd") == 0)
    {
        if (is_exit(node->cmd) == 1)
            ft_exit(node->cmd, *p_success, p_orig_termios);
        else
        {
            // ft_printf("cmd : %s dans fd0 : %d et fd1 : %d\n", node->cmd, fd0, fd1);
            *p_success = execute_command(node->cmd, paths, p_environ, p_orig_termios, fd0, fd1, fd2);
        }
    }
    if (node->type[0] == 'r')
    {
        int fd_file;

        node->fd_origin = node->fd_origin == -1 ? fd0 : node->fd_origin;
        fd_file = get_fd(node->file_name);
        // ft_printf("Redirection de cmd : %s du fd_origin : %d dans le fichier : %s (du coup vers le fd : %d) et output dans %d\n", node->cmd, node->fd_origin, node->file_name, fd_file, fd1);
        *p_success = execute_command(node->cmd, paths, p_environ, p_orig_termios, node->fd_origin, fd_file, fd_file);
        // execute_tree(node, fd0, 9999);
    }
    if (node->child)
    {
        int k;

        k = 0;
        while (node->child[k])
        {
            t_node *node_child;

            node_child = node->child[k];
            if (node_child->type[0] == 's' && k != 0)
            {

            }
            if (node_child->type[0] == 'p')
            {
                int *ls_pfd;

                ls_pfd = malloc(((node_child->nb_pipe) * 2 + 1) * sizeof(int));
                int j;

                j = 0;
                while (j < (node_child->nb_pipe + 1) * 2)
                {
                    // ls_pfd[j] = j + 3;
                    // j++;
                    int pfd[2];
                    pipe(pfd);   
                    ls_pfd[j] = pfd[0];
                    j++;
                    ls_pfd[j] = pfd[1];
                    j++;
                }
                ls_pfd[j] = 0;
                while (node->child[k])
                {
                    if (k == 0)
                        execute_tree(node->child[k], paths, p_environ, p_orig_termios, fd0, ls_pfd[1], ls_pfd[1], p_success);
                    else if (node->child[k + 1])
                        execute_tree(node->child[k], paths, p_environ, p_orig_termios, ls_pfd[(k-1) * 2], ls_pfd[(k) * 2 + 1], ls_pfd[(k) * 2 + 1], p_success);
                    else
                        execute_tree(node->child[k], paths, p_environ, p_orig_termios, ls_pfd[(k-1) * 2], fd1, fd2, p_success);
                    k++;
                }
            }
            else
            {
                execute_tree(node_child, paths, p_environ, p_orig_termios, fd0, fd1, fd2, p_success);
            }
            k++;
        }
    }
}

int prepare_command(char *cmd, char ***copy_env, int prev_res, struct termios *p_orig_termios)
{
    t_node **root;
    int success;

    root = malloc(sizeof(t_node *));
    *root = create_node("base", cmd);

    success = prev_res;

    execute_tree(*root, get_paths(*copy_env), copy_env, p_orig_termios,  0, 1, 2, &success);

    return (success);
}