#include "main.h"

void execute_s(char **stack)
{
    //  intervertit les 2 premiers éléments au sommet de la pile a. Ne fait
// rien s’il n’y en a qu’un ou aucun.
    int i;
    char *tmp;

    i = 0;
    if (stack[0] != 0 && stack[1] != 0)
    {
        tmp = stack[0];
        stack[0] = stack[1];
        stack[1] = tmp;
        // ft_putstr("invert\n");
    }
    else
    {
        // ft_putstr("nothing to invert\n");
    }
}

void analyse_command(char *command, char **stack_a, char **stack_b)
{
    command = ft_strtrim(command);
    printf("command : %s\n", command);
    if (ft_strcmp(command, "sa") == 0)
    {
        // ft_putstr("sa\n");
        execute_s(stack_a);
    }
    else if (ft_strcmp(command, "sb") == 0)
    {
        // ft_putstr("sb\n");
        execute_s(stack_b);
    }
    else if (ft_strcmp(command, "ss") == 0)
    {
        // ft_putstr("ss\n");
    }
    else if (ft_strcmp(command, "pa") == 0)
    {
        // ft_putstr("pa\n");
    }
    else if (ft_strcmp(command, "pb") == 0)
    {
        // ft_putstr("pb\n");
    }
    else if (ft_strcmp(command, "ra") == 0)
    {
        // ft_putstr("ra\n");
    }
    else if (ft_strcmp(command, "rb") == 0)
    {
        // ft_putstr("rb\n");
    }
    else if (ft_strcmp(command, "rr") == 0)
    {
        // ft_putstr("rr\n");
    }
    else if (ft_strcmp(command, "rra") == 0)
    {
        // ft_putstr("rra\n");
    }
    else if (ft_strcmp(command, "rrb") == 0)
    {
        // ft_putstr("rrb\n");
    }
    else if (ft_strcmp(command, "rrr") == 0)
    {
        // ft_putstr("rrr\n");
    }
    else
    {
        // ft_putstr("unknown command\n");
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

    while(get_next_line(1, &command) > 0)
    {
        printf("command : %s\n", command);
        // analyse_command(command, stack_a, stack_b);
    }

    ft_putstr("---------Stack A---------");
    print_stack(stack_a);
    ft_putstr("---------Stack B---------");
    print_stack(stack_b);
    return (0);
}
