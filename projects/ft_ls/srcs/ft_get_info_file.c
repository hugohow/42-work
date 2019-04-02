#include "ft_ls.h"

char *get_file_name(char *path)
{
    char *file_name;
    file_name = ft_strrchr(path, '/');
    if (file_name == NULL)
        return (path);
    return (file_name + 1);
}