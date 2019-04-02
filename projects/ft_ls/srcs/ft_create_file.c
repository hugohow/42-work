#include "ft_ls.h"

t_file *ft_create_file(char *path)
{
    t_file *file;

    file = malloc(sizeof(t_file));
    file->path = path;
    file->d_name = get_file_name(path);
    file->d_type = file_is_dir(path) ? 4 : 0;

    return (file);
}