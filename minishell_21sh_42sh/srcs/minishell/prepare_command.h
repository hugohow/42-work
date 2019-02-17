#include <stdlib.h>
#include <termios.h>

typedef struct s_token
{
    char* type;
    char* value;
}              t_token;

char **get_paths(char **copy_env);
int execute_command(char *cmd, char **paths, char ***p_environ, struct termios *p_orig_termios,  int fd0, int fd1, int fd2);
size_t  ft_strlen(const char *str);
char    *ft_strsub(char const *s, unsigned int start, size_t len);
int     ft_printf(const char* format, ...);
int is_separator(char *str);
int is_exit(char *cmd);
int     ft_strcmp(const char *s1, const char *s2);
void ft_exit(char *cmd, int success, struct termios *p_orig_termios);