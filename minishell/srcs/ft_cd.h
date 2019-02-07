#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#define BUF_SIZE 20

void    ft_putstr(char const *str);
char    *ft_strjoin(char const *str1, char const *str2);
void    ft_putchar(char c);
int     ft_printf(const char* format, ...);
char    *get_line_env(char *str, char ***p_environ);
int     change_line_env(char *key, char *line, char ***p_environ);
void    ft_putstr_fd(char const *str, int fd);
char    *ft_strjoin(char const *str1, char const *str2);
int     ft_strcmp(const char *s1, const char *s2);