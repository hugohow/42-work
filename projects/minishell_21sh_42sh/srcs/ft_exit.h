#include <termios.h>
#include <stdlib.h>

void    ft_exit_terminal(struct termios *orig_termios);
void    ft_putstr_fd(char const *str, int fd);
void    ft_putstr(char const *str);
int     ft_atoi(const char *str);
int     ft_isdigit(int c);
char    **ft_strsplit(char const *str, char c);
int     ft_strcmp(const char *s1, const char *s2);