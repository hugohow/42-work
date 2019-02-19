#include <termcap.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

void    ft_putnbr(int nb);
void    ft_putchar(char c);
void    ft_putstr_fd(char* str, int fd);
int     ft_isalnum(int c);
char    *ft_strjoin(char const *str1, char const *str2);
int     ft_isascii(int c);
int     ft_isprint(int c);
size_t  ft_strlen(const char *str);
int     ft_get_pos(int *y, int *x);
int     get_window_size(int *rows, int *cols);
char    *ft_strsub(char const *s, unsigned int start, size_t len);

void    print_bold_green(int fd);
void    print_normal(int fd);
void    ft_putstr(char const *str);
void    ft_putnbr(int nb);