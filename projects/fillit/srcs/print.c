#include "fillit.h"

void print_table(char *table, int size)
{
    int i;
    i = 0;
    while (i < size * size)
    {
        if (i % size == 0 && i != 0)
            printf("\n");    
        printf("%c", table[i++]);
    }
    printf("\n");
}