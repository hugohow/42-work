#include <unistd.h>
#include <stdlib.h>
#define BUF_SIZE 20

void    ft_putstr(char const *str);
char    *ft_strjoin(char const *str1, char const *str2);
void    ft_putchar(char c);
int     ft_printf(const char* format, ...);
char    *get_line_env(char *str, char **environ);