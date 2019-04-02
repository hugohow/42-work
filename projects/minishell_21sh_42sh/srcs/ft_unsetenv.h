#include <stdlib.h>

char *get_line_env(char *str, char ***p_environ);
int change_line_env(char *key, char *line, char ***p_environ);
char    *ft_strjoin(char const *str1, char const *str2);
int ft_list_size(char **list);
void    ft_putstr(char const *str);
int delete_line_env(char *key, char ***p_environ);
