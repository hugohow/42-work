#include <stdlib.h>
#include <stdio.h>
#include "fillit.h"

void print_table(char *empty, int size)
{
    int i;
    i = 0;
    while (i < size * size)
    {
        if (i % size == 0)
            printf("\n");    
        printf("%c", empty[i++]);
    }
    printf("\n");
}


void write_in_table(char *table, char letter, int col, int row, int size)
{
    table[row * size + col] = letter;
}

int is_point_ok(char *table, int col, int row, int size)
{
    if (table[row * size + col] != '.')
    {
        // printf("déjà pris, position : %d, next\n", row * size + col);
        return (0);
    }
    return (1);
}

int include_tetri(char *table, t_tetri *tetri, int position, int size)
{
    int i;
    int row;
    int col;
    i = 3;
    if (position == 4*4)
        return (0);
    while (i != -1)
    {
        col = position % size + (tetri->points[i]).col;
        row = position / size + (tetri->points[i]).row;
        if (col >= size || row >= size)
        {
            // printf("en dehors des bornes; col : %d, row : %d\n", col, row);
            return (0);
        }
        // printf("check col: %d \n", col);
        // printf("check row: %d \n\n", row);
        if (is_point_ok(table, col, row, size) == 1)
        {
            i--;
        }
        else
        {
            // printf("failed");
            return (0);
        }        
    }
    i = 0;
    while (i != 4)
    {
        col = position % size + (tetri->points[i]).col;
        row = position / size + (tetri->points[i]).row;
        write_in_table(table, tetri->letter, col, row, size);
        i++;
    }
    return (1);
}


int check_if_ok(char *table, t_tetri **list, int size)
{
    int i;
    int position;
    i = 0;
    while (i < size * size)
    {
        table[i++] = '.';
    }
    table[i] = '\0';
    // print_table(table, size);
    i = 0;
    position = 0;
    while (list[i])
    {
        if (position == size*size)
        {
            // printf("no possibilities");
            return (0);
        }
        if (include_tetri(table, list[i], position, size) == 1)
        {
            i++;
            // print_table(table, size);
        }
        else
        {
            position++;
        }
    }
    return (1);
}

char *solve(t_tetri **list)
{
    char *result;
    int size;

    size = 1;

    result = (char *)malloc(100 * sizeof(char));
    while (check_if_ok(result, list, size) == 0)
    {
        size++;
    }

    printf("Success, minimum square size is : %d\n\n", size);

    print_table(result, size);
    // alloc le maximum

    // check_if_ok(list, 1);
    // check if a size is okay

    return (result);
}