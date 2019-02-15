#include "prepare_command.h"

typedef struct s_node
{
    char *type;
    char *cmd;
    struct s_node **child;
}              t_node;


t_node **get_child(char *type, char *cmd);
t_node *create_node(char *type, char *cmd);
void    print_tree(t_node *node);
// ls ; echo a b > file ; cat file

// type = "root"
// str = "ls ; echo a b > file ; cat file"
// **t_node

// prioritaire

// ; -> séparateur de commande -> équivalent du *
// prendre les 2 commandes séparés dans un champs

// redirection prioritaire sur le pipe

//  >  -> il s'agit d'un file à droite, sinon "no such file or directory"
//  >>  -> il s'agit d'un file à droite, sinon "no such file or directory"
//  <<  -> 
//  <   -> à droite  un file
// prendre le file dans un champs


//  | -> stdout de la commande de gauche, va dans le stdin de la commande de droite 
// prendre la commande de droite et de gauche pour voir si c'est possible de piper

// aggregation de descripteurs de fichier

// optionnel

// &&
// ||

int is_separator(char *str)
{
    if (str[0] && str[0] == ';')
        return (1);
    return (0);
}


int is_redirection(char *str)
{
    if (str[0] && str[0] == ';')
        return (1);
    if (str[0] && str[0] == '<')
        return (1);
    return (0);
}

int is_pipe(char *str)
{
    if (str[0] && str[0] == ';')
        return (1);
    if (str[0] && str[0] == '<')
        return (1);
    return (0);
}

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

int has_separator(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == ';')
            return (1);
        i++;
    }
    return (0);
}

t_node *create_node(char *type, char *cmd)
{
    t_node *node;

    node = malloc(sizeof(t_node));
    node->type = type;
    node->cmd = cmd;
    node->child = get_child(type, cmd);
    return (node);
}

void print_tree(t_node *node)
{
    int k;

    if (node == NULL)
        return ;
    if (node->child == NULL)
    {
        ft_printf("%10s", node->cmd);
        return ;
    }
    k = 0;
    ft_printf("\ntype: %10s\n", node->type);
    while ((node->child)[k])
    {
        print_tree((node->child)[k]);
        k++;
    }
    ft_printf("\n\n");
}
int is_redirection(char *str)
{
    
}

t_node **get_child(char *type, char *cmd)
{
    t_node **child;
    char **list;
    int k;

    k = 0;
    child = malloc(sizeof(t_node *) * 20);
    if (ft_strcmp(type, "root") == 0)
    {
        list = ft_strsplit(cmd, ';');
        while (list[k])
        {
            child[k] = create_node("separator", list[k]);
            k++;
        }
        child[k] = 0;
        if (k == 0)
            return (NULL);
        return (child);
    }
    if (ft_strcmp(type, "separator"))
    {
        int i;

        i = 0;
        while (cmd[i])
        {
            if (is_redirection(cmd + i))
            {

            }
            i++;
        }
        // check if any redirection
        // ordre de gauche à droite


    }
    return (NULL);
}

int prepare_command(char *cmd, char ***copy_env, int prev_res, struct termios *p_orig_termios)
{
    t_node **root;

    root = malloc(sizeof(t_node *));


    *root = create_node("root", cmd);

    print_tree(*root);


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
        else if (ft_strcmp(list[i]->type, "cmd") == 0)
        {
            // check if a redirection is involved -> check if the file exists -> if not create it

            success = execute_command(list[i]->value, get_paths(*copy_env), copy_env, p_orig_termios);
        }
        i++;
    }
    return (success);
}