#include "fillit.h"

void write_in_table(char *table, char letter, int col, int row, int size)
{
    table[row * size + col] = letter;
}

void include_tetri(char *table, t_tetri *tetri, int position, int size)
{
    int i;
    int row;
    int col;

    i = 0;
    while (i != 4)
    {
        col = position % size + (tetri->points[i]).col;
        row = position / size + (tetri->points[i]).row;
        write_in_table(table, tetri->letter, col, row, size);
        i++;
    }
}

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