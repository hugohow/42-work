#include <stdlib.h>
#include <stdio.h>
#include "fillit.h"

void print_table(char *table, int size);

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

int ft_find(char *table, char c)
{
    int i;

    i = 0;
    while (table[i])
    {
        if (table[i] == c)
            return (1);
        i++;
    }
    return (0);
}

int tetri_includable(char *table, t_tetri *tetri, int position, int size)
{
    int i;
    int row;
    int col;
    i = 3;
    if (position >= size*size)
        return (0);
    if (ft_find(table, tetri->letter) == 1)
    {
        return (0);
    }
    while (i != -1)
    {
        col = position % size + (tetri->points[i]).col;
        row = position / size + (tetri->points[i]).row;
        if (col >= size || row >= size)
        {
            return (0);
        }
        // printf("table: %s \n", table);
        if (is_point_ok(table, col, row, size) == 1)
        {
            i--;
        }
        else
        {
            printf("failed pour la lettre : %c\n", tetri->letter);
            return (0);
        }        
    }
    printf("includable :  %c\n", tetri->letter);
    return (1);
}


int is_over(char *table, t_tetri **list)
{
    int i;
    i = 0;

    while (list[i] != 0)
    {
        if (ft_find(table, list[i]->letter) == 0)
            return (0);
        i++;
    }
    return (1);
}

int place_tetri(char *table, t_tetri **list, int position, int size)
{
    int j;


    if (is_over(table, list) == 1)
    {
        return (1);
    }

    if (position >= size*size)
    {
        printf("no possibilities");
        return (0);
    }

    j = 0;
    while (list[j])
    {
        if (tetri_includable(table, list[j], position, size) == 1)
        {
            include_tetri(table, list[j], position, size);
            if (place_tetri(table, list, position + 1, size) == 1)
            {
                return (1);
            }
            exclude_tetri(table, list[j]);
        }
        j++;
    }
    printf("Aucune list valide pour la position : %d\n", position);
    return (place_tetri(table, list, position + 1, size));
    // mauvais endoint
    // if (list[i] == 0)
    // {
    //     return (0);
    // }
    // if (position >= size*size)
    // {
    //     printf("no possibilities");
    //     return (0);
    // }
    // if (ft_find(table, list[i]->letter) == 1)
    // {
    //     return place_tetri(table, list, i + 1, position, size);
    // }




    // if (place_tetri(table, list, i + 1, position, size))

    // if (tetri_includable(table, list[i], position, size) == 1)
    // {
    //     include_tetri(table, list[i], position, size);
    //     return place_tetri(table, list, i + 1, position + 1, size);
    // }
    // else
    // {
    //     j = i + 1;
    //     while (list[j])
    //     {
    //         if (tetri_includable(table, list[j], position, size) == 1)
    //         {
    //             include_tetri(table, list[j], position, size);
    //             break;
    //         }
    //         j++;
    //     }
    //     return place_tetri(table, list, i, position + 1, size);
    // }
}

int find_res(char *table, t_tetri **list, int size)
{
    int i;
    i = 0;
    while (i < size * size)
    {
        table[i++] = '.';
    }
    table[i] = '\0';
    return place_tetri(table, list, 0, size);
}

char *solve(t_tetri **list, size_t list_len)
{
    char *table;
    int size;

    size = list_len >= 4 ? 4 : 2;
    printf("list_len : %zu", list_len);
    table = (char *)malloc((17 * 28) * sizeof(char));
    if (table == NULL)
        return (NULL);
    while (find_res(table, list, size) == 0 && size < 25)
    {
        printf("Test with %d\n", size);
        printf("-------------------------------------------------\n");
        size++;
    }
    printf("Success, minimum square size is : %d\n\n", size);
    print_table(table, size);
    return (table);
}