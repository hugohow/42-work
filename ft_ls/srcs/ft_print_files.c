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


void ft_print_files(char *path, t_flag *flag)
{
    char *new_path;
    struct dirent *pDirent;
    DIR *pDir;

    pDir = opendir(path);
    if (pDir == NULL) {
        ft_print_file_info(path, flag);
        return ;
    }
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
                ft_print_files(new_path, flag);
        }
    }
    closedir (pDir);
}