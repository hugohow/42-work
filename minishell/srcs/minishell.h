#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>

int     get_next_line(const int fd, char **line);
int     ft_printf(const char* format, ...);
int     ft_strcmp(const char *s1, const char *s2);
char    **ft_strsplit(char const *str, char c);
char    *ft_strjoin(char const *str1, char const *str2);
int     ft_echo(int argc, char **argv);
int     ft_cd(int argc, char **argv);
int     ft_setenv(int argc, char **argv);
int ft_unsetenv(int argc, char **argv);
size_t  ft_strlen(const char *str);
char *get_line_env(char *str);

extern char **environ;