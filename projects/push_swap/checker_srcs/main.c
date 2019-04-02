#include "main.h"



int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;
    char *command;

    stack_a = malloc(sizeof(t_stack));
    stack_b = malloc(sizeof(t_stack));

    if (initialize_stacks(&stack_a, &stack_b, argc, argv) == 0)
    {
        ft_putstr("Error\n");
        return (0);
    }
    if (pre_analyse_stacks(&stack_a, &stack_b) == 0)
    {
        ft_putstr("Error\n");
        return (0);
    }
    while(get_next_line(1, &command) > 0)
        analyse_command(command, &stack_a, &stack_b);
    post_analyse_stacks(&stack_a, &stack_b);
    return (0);
}
