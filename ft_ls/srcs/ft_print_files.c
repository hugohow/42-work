#include "ft_ls.h"

int get_level(char *path)
{
    int level;
    int i;

    level = 0;
    i = 0;
    while (path[i])
    {
        if (path[i] == '/')
            level++;
        i++;
    }
    return (level);
}

int cmp_path(void *content1, void *content2)
{
    // char *path1;
    // char *path2;

    // path1 = ((t_file *)(content1->content))->path;
    // path2 = ((t_file *)(node2->content))->path;
    // // usual case for name
    if (content1 && content2)
    {
        // printf("ft_strcmp(((t_file *)(content1))->path, ((t_file *)(content2))->path)  : %d \n", ft_strcmp(((t_file *)(content1))->path, ((t_file *)(content2))->path));
        return (ft_strcmp(((t_file *)(content1))->path, ((t_file *)(content2))->path));
    //     printf("node 2 : %s\n", ((t_file *)(node2->content))->path);
    // //     // insert le node
    }
    return (0);
}


void print_list(t_file **list, t_flag *flag)
{
    int i;

    i = 0;
    // traverser le binary tree par ordre
    while (list[i])
    {
        // print la première list
        ft_print_file_info(list[i]->path, flag);
        if (flag->has_cap_r == 1)
        {
            //     if (pDirent->d_type == 4 && ft_strcmp(pDirent->d_name, ".") != 0 
            //     && ft_strcmp(pDirent->d_name, "..") != 0)
            //     {
            //         t_sub_file_info_list[k] = new_file;
            //         k++;
            //     }
            // ft_print_files(list[i]->path, flag)
            ft_printf("\nici la sub list\n");
        }
        i++;
    }
}



void print_tree(t_btree *node)
{
    if (node && node->content)
   {
    //    printf("%s\n",((t_file *)(node->content))->path);
        ft_print_file_info(((t_file *)(node->content))->path, NULL);
    }
}

void ft_print_files(char *path, t_flag *flag)
{
    char *new_path;
    t_file *new_file;
    t_btree *root;
    // t_btree *node;
    t_file **t_file_info_list;
    // t_file **t_sub_file_info_list;
    struct dirent *pDirent;
    DIR *pDir;
    int k;
    int j;

    pDir = opendir(path);
    // t_sub_file_info_list = malloc((999) * sizeof(t_file *));
    t_file_info_list = malloc((999) * sizeof(t_file *));
    root = malloc(sizeof(t_btree));
    if (pDir == NULL) {
        ft_print_file_info(path, flag);
        return ;
    }
    if (flag->has_cap_r == 1)
    {
        ft_printf("\n%s:\n", path);
    }
    if (flag->has_l == 1)
    {
        ft_printf("total xxxxx\n");
    }
    k = 0;
    j = 0;
    // ft_create_node
    while ((pDirent = readdir(pDir)) != NULL) 
    {
        new_file = malloc(sizeof(t_file));
        if (path[ft_strlen(path) - 1] != '/')
            new_path = ft_strjoin(path, "/");
        new_path = ft_strjoin(new_path, pDirent->d_name);
        new_file->path = new_path;
        // ft_printf("Path: %s, get_level(path): %d\n", new_path, get_level(path));
        if (flag->has_a == 0 && (ft_strcmp(pDirent->d_name, ".") == 0 
            || ft_strcmp(pDirent->d_name, "..") == 0))
        {
        }
        else
        {
            // if (root)
            // {
                // node = btree_create_node(new_file);

                btree_insert_data(&root, new_file, cmp_path);
                // ft_insert_node
            // }
            // else
            // {
            //     root = btree_create_node(new_file);
            // }
            t_file_info_list[j] = new_file;
            j++;
        }
    }

    t_file_info_list[j] = 0;



    ft_traverse_tree(root, print_tree);


    // print_list(t_file_info_list, flag);
    closedir (pDir);
}