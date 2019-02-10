#include <unistd.h>
#include <sys/wait.h> 
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>

void    ft_putstr(char const *str);
void    ft_putchar(char c);
int delete_line_env(char *key, char ***p_environ);
int     ft_strcmp(const char *s1, const char *s2);
char **copy_environ(char **str);
int ft_printf(const char* format, ...);
void    ft_putstr_fd(char const *str, int fd);
char    *ft_strjoin(char const *str1, char const *str2);
int     prepare_command(char *cmd, char ***copy_env, int prev_res, struct termios *p_orig_termios);
char    **ft_strsplit(char const *str, char c);
void    ft_setenv_args(char *prefix, char *line, char ***p_environ);
char    *ft_strsub(char const *s, unsigned int start, size_t len);
void    ft_putstr_fd(char const *str, int fd);
void    ft_putchar_fd(char c, int fd);