#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "fillit.h"

size_t  ft_strlen(const char *str);


size_t   count_tetri(char const *str)
{
    size_t i;
    size_t count;

    i = 0;
    count = 1;
    while (str[i])
    {
        if (str[i + 1] && str[i] == '\n' && str[i + 1] == '\n')
            count++;
        i++;
    }
    return (count);
}

void    offset_vertical(char *tetri)
{
    int i;
    int j;

    i = 0;
    while (i < 4)
    {
        if (tetri[i] != '.')
            break;
        i++;
    }
    if (i == 4)
    {
        j = 4;
        while (j != 4*4)
        {
            tetri[j - 4] = tetri[j];
            j++;
        }
        j = 4*4 - 4;
        while (j < 4*4)
            tetri[j++] = '.';
        offset_vertical(tetri);
    }
    return ;
}


void    offset_horizontal(char *tetri)
{
    int i;
    int j;

    i = 0;
    while (i < 4*4)
    {
        if (i % 4 == 0 && tetri[i] != '.')
            break;
        i++;
    }
    if (i == 4*4)
    {
        j = 0;
        while (j != 4*4)
        {
            tetri[j] = tetri[j + 1];
            tetri[j+1] = tetri[j + 2];
            tetri[j+2] = tetri[j + 3];
            tetri[j+3] = '.';
            j += 4;
        }
        offset_horizontal(tetri);
    }
    return ;
}

t_tetri *create_tetri(char *str)
{
    t_tetri *tetri;
    int i;
    int k;
    char letter;
    t_position *points;

    points = (t_position *)malloc(5 * sizeof(t_position));
    tetri = (t_tetri *)malloc(sizeof(t_tetri));
    i = 0;
    k = 0;
    while (str[i])
    {
        if (str[i] != '.')
        {
            points[k].row = i / 4;
            points[k].col = i % 4;
            letter = str[i];
            k++;
        }
        i++;
    }
    tetri->points = points;
    tetri->letter = letter;
    printf("DEF TETRI  ------\n");
    
    printf("%c\n", tetri->letter);
    printf("%s\n", str);
    printf("col : \t%d\t%d\t%d\t%d\n", tetri->points[0].col, tetri->points[1].col, tetri->points[2].col, tetri->points[3].col);
    printf("row : \t%d\t%d\t%d\t%d\n", tetri->points[0].row, tetri->points[1].row, tetri->points[2].row, tetri->points[3].row);

    return (tetri);
}

t_tetri    **ft_list_tetri(char const *str)
{
    t_tetri **list_tetri;
    t_tetri *tetri;
    char *tmp_str;
    size_t i;
    size_t j;
    size_t k;
    size_t str_len;

    list_tetri = (t_tetri **)malloc((28) * sizeof(t_tetri *));
    i = 0;
    k = 0;
    str_len = ft_strlen(str);
    while (str[i])
    {
        if (str[i + 1] && str[i] != '\n' && str[i + 1] != '\n')
        {
            tmp_str = (char *)malloc((str_len + 1) * sizeof(char));
            if (tmp_str == NULL)
                return (NULL);
            j = 0;
            while (str[i])
            {
                if (str[i] == '\n' && str[i + 1] == '\n')
                    break;
                if (str[i] == '\n')
                    i++;
                tmp_str[j] = str[i] == '#' ? 'A' + k : str[i];
                j++;
                i++;
            }
            tmp_str[j] = '\0';
            offset_vertical(tmp_str);
            offset_horizontal(tmp_str);
            tetri = create_tetri(tmp_str);
            
            list_tetri[k++] = tetri;
        }
        else 
        {
            i++;
        }
    }
    list_tetri[k] = 0;
    return (list_tetri);
}
