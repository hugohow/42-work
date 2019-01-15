#include "main.h"

void analyse_command(char *command)
{
    command = ft_strtrim(command);
    if (ft_strcmp(command, "sa") == 0)
    {
        ft_putstr("sa\n");
    }
    else if (ft_strcmp(command, "sb") == 0)
    {
        ft_putstr("sb\n");
    }
    else if (ft_strcmp(command, "ss") == 0)
    {
        ft_putstr("ss\n");
    }
    else if (ft_strcmp(command, "pa") == 0)
    {
        ft_putstr("pa\n");
    }
    else if (ft_strcmp(command, "pb") == 0)
    {
        ft_putstr("pb\n");
    }
    else if (ft_strcmp(command, "ra") == 0)
    {
        ft_putstr("ra\n");
    }
    else if (ft_strcmp(command, "rb") == 0)
    {
        ft_putstr("rb\n");
    }
    else if (ft_strcmp(command, "rr") == 0)
    {
        ft_putstr("rr\n");
    }
    else if (ft_strcmp(command, "rra") == 0)
    {
        ft_putstr("rra\n");
    }
    else if (ft_strcmp(command, "rrb") == 0)
    {
        ft_putstr("rrb\n");
    }
    else if (ft_strcmp(command, "rrr") == 0)
    {
        ft_putstr("rrr\n");
    }
    else
    {
        ft_putstr("unknown command\n");
    }
}

int main(int argc, char **argv)
{
    int i;
    char **stack_a;
    char **stack_b;
    char *command;

    stack_a = malloc(argc * sizeof(char *));
    stack_b = malloc(argc * sizeof(char *));

    i = 1;
    while (i < argc)
    {
        stack_a[i - 1] = argv[i];
        stack_b[i - 1] = 0;
        i++;
    }
    stack_a[i - 1] = 0;
    stack_b[i - 1] = 0;

    while(get_next_line(1, &command) != 0)
    {
        analyse_command(command);
    }

    ft_putstr("---------Stack A---------");
    print_stack(stack_a);
    ft_putstr("---------Stack B---------");
    print_stack(stack_b);
    return (0);
}
