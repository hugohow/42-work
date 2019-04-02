#include <termios.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>

char    **ft_strsplit(char const *str, char c);
char    *ft_strtrim(char const *str);
int ft_execute_path(char *path, char **argv, char ***p_environ, int fd0, int fd1, int fd2);
char    **ft_strsplit(char const *str, char c);
char    *ft_strjoin(char const *str1, char const *str2);
int     ft_echo(int argc, char **argv, char ***p_environ, int fd0, int fd1, int fd2);
int     ft_cd(int argc, char **argv, char ***p_environ);
int     ft_setenv(int argc, char **argv, char ***p_environ);
int ft_env(int argc, char **argv, char ***p_environ, struct termios *p_orig_termios);
int ft_unsetenv(int argc, char **argv, char ***p_environ);
int ft_list_size(char **list);
void    ft_putstr_fd(char const *str, int fd);
int     ft_strcmp(const char *s1, const char *s2);