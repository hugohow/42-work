#include <stdlib.h>
#include <stdio.h>

void print_table(char *empty)
{
    printf("\nPrint table\n");
    printf("%s", empty);
    printf("\n\n");
}

void include_list(char *table, char *list, int position)
{
    position++;
    if (list)
    {
        table[position] = 'a';
    }
}

int check_if_ok(char **list, int size)
{
    char *empty;
    int i;

    empty = (char *)malloc(100 * sizeof(char));
    i = 0;
    while (i < (size + 1) * (size + 1))
    {
        if (i % (size + 1) == 0)
            empty[i++] = '\n';
        else
            empty[i++] = '.';
    }
    empty[i] = '\0';
    print_table(empty);
    i = 0;
    while (list[i])
    {
        include_list(empty, list[i], 4);
        print_table(empty);
        // printf("\nTest : inclure \n%s\n", list[i]);
        i++;
    }
    return (1);
}

char *solve(char **list)
{
    char *result;

    result = (char *)malloc(100 * sizeof(char));
    check_if_ok(list, 4);
    // alloc le maximum

    // check_if_ok(list, 1);
    // check if a size is okay

    return (result);
}