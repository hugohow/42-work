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

void    offset_vertical(char *tetri, int nb)
{
    int i;
    int j;

    i = 0;
    if (nb == 4)
        return ;
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
        offset_vertical(tetri, nb + 1);
    }
    return ;
}


void    offset_horizontal(char *tetri, int nb)
{
    int i;
    int j;

    i = 0;
    if (nb == 4)
        return ;
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
        offset_horizontal(tetri, nb + 1);
    }
    return ;
}

int check_around(char *str, int i)
{
    int row;
    int col;
    int count;

    row = i / 4;
    col = i % 4;
    count = 0;
    // check à droite
    if (col + 1 < 4 && str[row * 4 + (col + 1)] != '.')
        return (1);
    // check en bas
    if (row + 1 < 4 && str[(row + 1) * 4 + col] != '.')
        return (1);
    // check à gauche
    if (col - 1 >= 0 && str[row * 4 + (col - 1)] != '.')
        return (1);
    // check en haut
    if (row - 1 >= 0 && str[(row - 1) * 4 + col] != '.')
        return (1);
    // check en diagonal
    // if (row - 1 >= 0 && col - 1 >= 0 && str[(row - 1) * 4 + (col - 1)] != '.')
    //     count++;

    // if (row - 1 >= 0 && col + 1 < 4 && str[(row - 1) * 4 + (col + 1)] != '.')
    //     count++;

    // if (row + 1 < 4 && col - 1 >= 0 && str[(row + 1) * 4 + (col - 1)] != '.')
    //     count++;

    // if (row + 1 < 4 && col + 1 < 4 && str[(row + 1) * 4 + (col + 1)] != '.')
    //     count++;

    // if (count >= 2)
    //     return (1);
    return (0);
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
            if (check_around(str, i) == 0)
                return (NULL);
            points[k].row = i / 4;
            points[k].col = i % 4;
            letter = str[i];
            k++;
        }
        i++;
    }
    if (k != 4)
    {
        // printf("k != 4 : %d \n", k);    
        return (NULL);
    }
    tetri->points = points;
    tetri->letter = letter;
    // printf("DEF TETRI  ------\n");
    
    // printf("%c\n", tetri->letter);
    // printf("%s\n", str);
    // printf("col : \t%d\t%d\t%d\t%d\n", tetri->points[0].col, tetri->points[1].col, tetri->points[2].col, tetri->points[3].col);
    // printf("row : \t%d\t%d\t%d\t%d\n", tetri->points[0].row, tetri->points[1].row, tetri->points[2].row, tetri->points[3].row);

    return (tetri);
}

int char_is_valid(char c)
{
    if (c == '.' || c == '#' || c == '\n')
        return (1);
    return (0);
}

int end_tetri(char const *str, int i)
{
    // on suppose que str[i] n'est pas null
    if (str[i] == '\0')
        return (1);
    if (str[i + 1] == '\0')
        return (1);
    if (str[i] == '\n' && str[i + 1] == '\n')
        return (1);
    return (0);
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
        if (end_tetri(str, i) == 0)
        {
            tmp_str = (char *)malloc((str_len + 1) * sizeof(char));
            if (tmp_str == NULL)
                return (NULL);
            j = 0;
            while (str[i] != '\0' && char_is_valid(str[i]) == 1)
            {
                if (end_tetri(str, i) == 1)
                    break;
                if (str[i] == '\n' && j % 4 == 0)
                    i++;
                else
                {
                    tmp_str[j] = str[i] == '#' ? 'A' + k : str[i];
                    j++;
                    i++;
                    if (j % 4 == 0 && str[i] != '\n')
                        break;
                }
            }
            if ((str[i + 1] && str[i + 2]) && (str[i + 2] != '.' && str[i + 2] != '#'))
                return (NULL);
            if (j != 16)
                return (NULL);
            tmp_str[j] = '\0';
            offset_vertical(tmp_str, 0);
            offset_horizontal(tmp_str, 0);
            
            tetri = create_tetri(tmp_str);
            if (tetri == NULL)
                return (NULL);
            list_tetri[k++] = tetri;
        }
        else 
            i++;
    }
    if ((i > 2 && str[i - 2] && str[i - 2] == '\n') || i < 4)
        return (NULL);
    list_tetri[k] = 0;
    return (list_tetri);
}
