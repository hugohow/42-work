#include <stdlib.h>

char *get_line_env(char *str);
int change_line_env(char *key, char *line);
char    *ft_strjoin(char const *str1, char const *str2);
int list_size(char **list);
void    ft_putstr(char const *str);
int delete_line_env(char *key);
extern char **environ;
