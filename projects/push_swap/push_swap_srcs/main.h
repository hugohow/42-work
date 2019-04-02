#include <stdlib.h>
#include <stdio.h>

typedef struct s_stack
{
    long long *list;
    size_t     len;
}             t_stack;

void    ft_putstr(char const *str);
void    ft_putchar(char const c);
int     get_next_line(const int fd, char **line);
void    print_stack(char *stack);
void    analyse_command(char *command, t_stack **stack_a, t_stack **stack_b);
int     post_analyse_stacks(t_stack **stack_a, t_stack **stack_b);
int     pre_analyse_stacks(t_stack **stack_a, t_stack **stack_b);
int initialize_stacks(t_stack **stack_a, t_stack **stack_b, int argc, char **argv);