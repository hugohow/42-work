#include "fillit.h"


int is_point_ok(char *table, int col, int row, int size)
{
    if (table[row * size + col] != '.')
        return (0);
    return (1);
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
        return (0);
    while (i != -1)
    {
        col = position % size + (tetri->points[i]).col;
        row = position / size + (tetri->points[i]).row;
        if (col >= size || row >= size)
            return (0);
        if (is_point_ok(table, col, row, size) == 1)
            i--;
        else
            return (0);
    }
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
        return (1);
    if (position >= size*size)
        return (0);
    j = 0;
    while (list[j])
    {
        if (tetri_includable(table, list[j], position, size) == 1)
        {
            include_tetri(table, list[j], position, size);
            if (place_tetri(table, list, position + 1, size) == 1)
                return (1);
            exclude_tetri(table, list[j]);
        }
        j++;
    }
    return (place_tetri(table, list, position + 1, size));
}

int find_solution(char *table, t_tetri **list, int size)
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

size_t ft_strlist(t_tetri **list_tetri)
{
    size_t list_len;

    list_len = 0;
    while (list_tetri[list_len] != 0)
    {
        list_len++;
    }
    return (list_len);
}

char *solve(t_tetri **list)
{
    char *table;
    int size;

    size = ft_strlist(list) >= 4 ? 4 : 2;
    // printf("list_len : %zu", list_len);
    table = (char *)malloc((17 * 28) * sizeof(char));
    if (table == NULL)
        return (NULL);
    while (find_solution(table, list, size) == 0 && size < 25)
    {
        // printf("Test with %d\n", size);
        // printf("-------------------------------------------------\n");
        size++;
    }
    // printf("Success, minimum square size is : %d\n\n", size);
    print_table(table, size);
    return (table);
}