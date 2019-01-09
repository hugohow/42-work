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

void print_list(char **list, t_flag *flag)
{
    int i;

    i = 0;
    while (list[i])
    {
        // print les fichiers à l'intérieurs du dossier, une fois que tous les fichiers sont printés
        ft_print_file_info(list[i], flag);
        i++;
    }
}

void ft_print_files(char *path, t_flag *flag)
{
    char *new_path;
    char **t_file_info_list;
    char **t_sub_file_info_list;
    struct dirent *pDirent;
    DIR *pDir;
    int k;
    int j;

    pDir = opendir(path);
    t_sub_file_info_list = malloc((999) * sizeof(char *));
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
    j = 0;
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
            t_file_info_list[j] = new_path;
            j++;
        }

        // -R
        if (flag->has_cap_r == 1)
        {
            if (pDirent->d_type == 4 && ft_strcmp(pDirent->d_name, ".") != 0 
            && ft_strcmp(pDirent->d_name, "..") != 0)
            {
                t_sub_file_info_list[k] = new_path;
                k++;
            }
        }
    }
    t_sub_file_info_list[k] = 0;
    t_file_info_list[j] = 0;
    sort(t_file_info_list);
    print_list(t_file_info_list, flag);
    sort(t_sub_file_info_list);
    int i;

    i = 0;
    while (i < k)
    {
        // print les fichiers à l'intérieurs du dossier, une fois que tous les fichiers sont printés
        ft_print_files(t_sub_file_info_list[i], flag);
        i++;
    }

    closedir (pDir);
}