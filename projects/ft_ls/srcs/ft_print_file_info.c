#include "ft_ls.h"

time_t get_file_modified_time(const char *path)
{
    struct stat attr;
    if (stat(path, &attr) == 0)
    {
        // printf("%s: last modified time: %s", path, ctime(&attr.st_mtime));
        return (attr.st_mtime);
    }
    return 0;
}

// pas ultra performant....
unsigned long get_file_st_blocks(const char *path)
{
    struct stat attr;
    if (stat(path, &attr) == 0)
    {
        return (attr.st_blocks);
    }
    return 0;
}

int file_is_dir(char *path)
{
    struct stat attr;
    if (stat(path, &attr) == 0)
    {
        return (S_ISDIR(attr.st_mode));
    }
    return 0;
}


void ft_print_file_info(t_file **file, t_flag *flag)
{
    struct stat fileStat;
    struct passwd *pwd;
    struct group *grp;
    char *path;

    path = (*file)->path;
    if (path == NULL)
    {
        return ;
    }
    if (stat(path, &fileStat) < 0)
    {
        ft_printf("ft_ls: %s: No such file or directory\n", path);
        return ;
    }
    if (flag && flag->has_l == 1)
    {
        ft_printf( (S_ISDIR(fileStat.st_mode)) ? "d" : "-");
        ft_printf( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
        ft_printf( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
        ft_printf( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
        ft_printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
        ft_printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
        ft_printf( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
        ft_printf( (fileStat.st_mode & S_IROTH) ? "r" : "-");
        ft_printf( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
        ft_printf( (fileStat.st_mode & S_IXOTH) ? "x" : "-");
        ft_printf("  ");
        ft_printf("%d",fileStat.st_nlink);
        ft_printf(" ");
        if ((pwd = getpwuid(fileStat.st_uid)) != NULL)
            ft_printf("%-16s", pwd->pw_name);
        else
            ft_printf("%-16d", fileStat.st_uid);
        ft_printf(" ");
        if ((grp = getgrgid(fileStat.st_gid)) != NULL)
            ft_printf("%-6s", grp->gr_name);
        else
            ft_printf("%-6d", fileStat.st_gid);
        ft_printf("%5lld",fileStat.st_size);
        ft_printf("\t");
        ft_printf("%.12s", ctime(&fileStat.st_mtime) + 4);
        ft_printf("\t");
        ft_printf("%s", get_file_name(path));
        ft_printf("\n");
    }
    else
    {
        ft_printf("%s", get_file_name(path));
        ft_printf("    ");
    }
}