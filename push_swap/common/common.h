#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_stack
{
    long long *list;
    size_t     len;
}             t_stack;

void    ft_putstr(char const *str);
void    ft_putchar(char const c);
char    *ft_strtrim(char const *str);
int     ft_strcmp(const char *s1, const char *s2);
void    print_stack(t_stack *stack);
size_t  ft_stacklen(t_stack **stack);
int ft_printf(const char* format, ...);
size_t  ft_strlen(const char *str);
long long ft_atoi_ll(const char *str);