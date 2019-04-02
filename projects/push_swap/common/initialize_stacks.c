#include "common.h"

int initialize_stacks(t_stack **stack_a, t_stack **stack_b, int argc, char **argv)
{
    int i;
    long long *list_a;
    long long *list_b;
    long long tmp;

    list_a = malloc(argc * 2 * sizeof(long long));
    list_b = malloc(argc * 2 * sizeof(long long));

    i = 1;
    while (i < argc)
    {
        tmp = (long long)ft_atoi_ll(argv[i]);
        if (tmp == 0 && ft_strlen(argv[i]) > 0)
        {
            ft_putstr("Error\n");
            return (0);
        }
        // faire valider si argv[i] est bien un nombre
        list_a[i - 1] = tmp;
        list_b[i - 1] = 0;
        i++;
    }
    list_a[i - 1] = 0;
    list_b[i - 1] = 0;

    (*stack_a)->list = list_a;
    (*stack_a)->len = i - 1;

    (*stack_b)->list = list_b;
    (*stack_b)->len = 0;
    return (1);
}