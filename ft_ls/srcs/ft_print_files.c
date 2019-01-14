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

int cmp_date(void *content1, void *content2)
{
    t_file *file1;
    t_file *file2;

    file1 = ((t_file *)content1);
    file2 = ((t_file *)content2);

    // printf("date 1 : %ld\n", get_file_modified_time(file1->path));
    // printf("date 2 : %ld\n", get_file_modified_time(file2->path));
    return (get_file_modified_time(file2->path) - get_file_modified_time(file1->path));
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

void ft_print_tree(t_btree *root, t_flag *flag, t_btree **sub_root)
{
    t_file *file;

    file = NULL;
    if (root == NULL)
        return ;
    if (root->left)
        ft_print_tree(root->left, flag, sub_root);
    if (root->content)
    {
        file = ((t_file *)(root->content));
        // ft_printf("file: %s\n", ((t_file *)(root->content))->path);
        ft_print_and_get_file_info(&file, flag);
        if (flag->has_cap_r == 1)
        {
            if (file->d_type == 4 && 
            ft_strcmp(file->d_name, ".") != 0 
            && ft_strcmp(file->d_name, "..") != 0)
            {
                if (flag->has_t)
                    btree_insert_data(sub_root, file, cmp_date);
                else
                    btree_insert_data(sub_root, file, cmp_path);
                // ft_print_files(file->path, flag);
            }
        }
        file = NULL;
    }
    if (root->right)
        ft_print_tree(root->right, flag, sub_root);
}

void ft_print_sub_tree(t_btree *sub_root, t_flag *flag)
{
    if (sub_root == NULL)
        return ;
    if (sub_root->left)
        ft_print_sub_tree(sub_root->left, flag);
    if (sub_root->content && ((t_file *)(sub_root->content))->path)
    {
        ft_print_files(((t_file *)(sub_root->content))->path, flag);
    }
    if (sub_root->right)
        ft_print_sub_tree(sub_root->right, flag);
}


void ft_print_files(char *path, t_flag *flag)
{
    char *new_path;
    t_file *new_file;
    t_btree *root;
    t_btree *sub_root;
    struct dirent *pDirent;
    DIR *pDir;
    int k;

    if (path == NULL)
    {
        return ;
    }
    root = NULL;
    sub_root = NULL;
    if ((pDir = opendir (path)) == NULL) {
        new_file = malloc(sizeof(t_file));
        new_file->path = path;
        ft_print_and_get_file_info(&new_file, flag);
        // ft_printf("file: %s\n", new_file->path);
        return ;
    }
    if (flag->has_cap_r == 1 || flag->has_l == 1)
    {
        ft_printf("\n%s:\n", path);
    }
    if (flag->has_l == 1)
    {
        ft_printf("total xxxxx\n");
    }
    k = 0;
    while ((pDirent = readdir(pDir)) != NULL) 
    {
        new_file = malloc(sizeof(t_file));
        if (ft_strlen(path) > 0 && path[ft_strlen(path) - 1] != '/')
            new_path = ft_strjoin(path, "/");
        new_path = ft_strjoin(new_path, pDirent->d_name);
        new_file->path = new_path;
        new_file->d_type = pDirent->d_type;
        new_file->d_name = pDirent->d_name;
        // ft_printf("Path: %s, get_level(path): %d\n", new_path, get_level(path));
        if (flag->has_a == 0 && (ft_strcmp(pDirent->d_name, ".") == 0 
            || ft_strcmp(pDirent->d_name, "..") == 0))
        {
        }
        else
        {
            if (flag->has_t)
                btree_insert_data(&root, new_file, cmp_date);
            else
                btree_insert_data(&root, new_file, cmp_path);
        }
    }
    closedir (pDir);

    ft_print_tree(root, flag, &sub_root);
    free(root);
    if (flag->has_cap_r == 1)
    {
        ft_print_sub_tree(sub_root, flag);
    }
    free(sub_root);


}
