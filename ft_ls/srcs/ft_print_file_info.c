#include "ft_ls.h"

void ft_print_file_info(char *file, t_flag *flag)
{
    struct stat fileStat;
    struct passwd *pwd;
    struct group *grp;

    if (stat(file, &fileStat) < 0)
    {
        ft_printf("ft_ls: %s: No such file or directory\n", file);
        return ;
    }
    if (flag->has_l == 1)
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
        ft_printf("%.16s", ctime(&fileStat.st_mtime));
        ft_printf("\t");
        ft_printf("%s", get_file_name(file));
        ft_printf("\n");
    }
    else
    {
        ft_printf("%s", get_file_name(file));
        ft_printf("\t");
    }
}