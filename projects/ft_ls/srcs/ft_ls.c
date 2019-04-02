#include "ft_ls.h"


void ft_print_tree_ls(t_btree *root, t_flag *flag)
{
    t_file *file;

    file = NULL;
    if (root == NULL)
        return ;
    if (root->left)
        ft_print_tree_ls(root->left, flag);
    if (root->content)
    {
        file = ((t_file *)(root->content));
        ft_print_files(file->path, flag);
        ft_printf("\n");
    }
    if (root->right)
        ft_print_tree_ls(root->right, flag);
}

int is_flag(char *str)
{
    if (str[0] && str[0] == '-')
    {
        return (1);
    }
    return (0);
}

int main(int argc, char **argv)
{
    t_flag *flag;
    t_btree *root;
    t_file *file;
    int i;

    i = 1;
    flag = NULL;
    root = NULL;
    // on essaye, si NULL c'est que argv 1 est autre chose
    if (argc >= 2)
    {
        while (argv[i] && is_flag(argv[i]) == 1)
        {
            flag = ft_get_flag_info(argv[i], flag);
            i++;
        }
    }
    if (flag != NULL)
        i++;
    else
        flag = ft_get_flag_info("", flag);
    if (i >= argc)
    {
        ft_print_files(".", flag);
        return (0);
    }
    while (i < argc)
    {
        file = ft_create_file(argv[i]);
        // ft_printf("argv[i] : %s\n", argv[i]);
        insert_data_tree(&root, file, flag);
        i++;
    }
    ft_print_tree_ls(root, flag);
    ft_putchar('\n');
    return (0);
}