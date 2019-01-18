#include "main.h"



int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;
    int i;
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

    i = 0;
    while (post_analyse_stacks(&stack_a, &stack_b) != 1)
    {
        i++;
        if (i == 10)
            break;
    }
    return (0);
}
