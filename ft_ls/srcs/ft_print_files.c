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

char **sort(char **list)
{
    return (list);
}

void ft_print_files(char *path, t_flag *flag)
{
    char *new_path;
    char **t_file_info_list;
    struct dirent *pDirent;
    DIR *pDir;
    int k;

    pDir = opendir(path);
    t_file_info_list = malloc((999) * sizeof(char *));
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
    while ((pDirent = readdir(pDir)) != NULL) 
    {
        if (path[ft_strlen(path) - 1] != '/')
            new_path = ft_strjoin(path, "/");
        new_path = ft_strjoin(new_path, pDirent->d_name);
        // ft_printf("Path: %s, get_level(path): %d\n", new_path, get_level(path));
        if (flag->has_a == 0 && (ft_strcmp(pDirent->d_name, ".") == 0 
            || ft_strcmp(pDirent->d_name, "..") == 0))
        {
        }
        else
        {
            ft_print_file_info(new_path, flag);
        }

        // -R
        if (flag->has_cap_r == 1)
        {
            if (pDirent->d_type == 4 && ft_strcmp(pDirent->d_name, ".") != 0 
            && ft_strcmp(pDirent->d_name, "..") != 0)
            {
                t_file_info_list[k] = new_path;
                k++;
            }
        }
    }
    t_file_info_list[k] = 0;

    sort(t_file_info_list);
    int i;

    i = 0;
    while (i < k)
    {
        ft_print_files(t_file_info_list[i], flag);
        i++;
    }

    closedir (pDir);
}