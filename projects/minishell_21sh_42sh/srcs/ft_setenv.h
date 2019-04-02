#include <stdlib.h>
#include <stdio.h>

char *get_line_env(char *str, char ***p_environ);
int change_line_env(char *key, char *line, char ***p_environ);
char    *ft_strjoin(char const *str1, char const *str2);
int ft_list_size(char **list);
void    ft_putstr(char const *str);
void ft_print_env(char **str);
char    *ft_strsub(char const *s, unsigned int start, size_t len);
void    ft_putstr_fd(char const *str, int fd);
int     ft_isdigit(int c);