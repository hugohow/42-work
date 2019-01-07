#include "ft_ls.h"

#include <dirent.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <time.h> 

void print_info(char *file)
{
    struct stat fileStat;
    struct passwd *pwd;
    struct group *grp;

    if (stat(file, &fileStat) < 0)    
        return ;
    ft_printf("\n....................\n\n");
    ft_printf("Information for %s\n\n", file);
    ft_printf("File Permissions: \t\t");
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
    ft_printf("\n");
    ft_printf("Number of Links: \t\t%d\n",fileStat.st_nlink);
    ft_printf("Username : \t\t\t");
    if ((pwd = getpwuid(fileStat.st_uid)) != NULL)
        ft_printf("%s", pwd->pw_name);
    else
        ft_printf("%d", fileStat.st_uid);
    ft_printf("\n");
    ft_printf("Group : \t\t\t");
    if ((grp = getgrgid(fileStat.st_gid)) != NULL)
        ft_printf("%s", grp->gr_name);
    else
        ft_printf("%d", fileStat.st_gid);
    ft_printf("\n");
    ft_printf("File Size: \t\t\t%lld bytes\n",fileStat.st_size);
    ft_printf("Time of last access: \t\t%d\t%s\n", fileStat.st_atime, ctime(&fileStat.st_atime));
    ft_printf("Time of last modification: \t%d\t%s\n", fileStat.st_mtime, ctime(&fileStat.st_mtime));
    ft_printf("Time of last status change: \t%d\t%s\n", fileStat.st_ctime, ctime(&fileStat.st_ctime));
    ft_printf("File inode: \t\t\t%llu\n",fileStat.st_ino);
    ft_printf("\n\n");
 
    ft_printf("The file %s a symbolic link\n", (S_ISLNK(fileStat.st_mode)) ? "is" : "is not");
}

void print_files(char *dir_name)
{
    struct dirent *pDirent;
    DIR *pDir;

    pDir = opendir(dir_name);
    if (pDir == NULL) {
        ft_printf ("Cannot open directory\n");
        return ;
    }
    while ((pDirent = readdir(pDir)) != NULL) 
    {
        print_info(pDirent->d_name);
    }
    closedir (pDir);
}

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        ft_printf("Test opendir\n");
        ft_printf("---------------------------------\n");
        print_files(".");
        ft_printf("---------------------------------\n");
        return (0);
    }
    if (argv[1])
    {

    }
    return (0);
}