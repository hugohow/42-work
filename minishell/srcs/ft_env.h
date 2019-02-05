#include <unistd.h>
#include <sys/wait.h> 
#include <stdio.h>
#include <stdlib.h>
void    ft_putstr(char const *str);
void    ft_putchar(char c);
int delete_line_env(char *key, char ***p_environ);
int     ft_strcmp(const char *s1, const char *s2);
char **copy_environ(char **str);
int ft_printf(const char* format, ...);