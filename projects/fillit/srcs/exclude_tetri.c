#include "fillit.h"

void exclude_tetri(char *table, t_tetri *tetri)
{
    int i;

    i = 0;
    while (table[i])
    {
        if (table[i] == tetri->letter)
            table[i] = '.';
        i++;
    }
}