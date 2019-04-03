#include "fillit.h"

size_t ft_strlen(const char *str)
{
    size_t length;

    length = 0;
    while(str[length])
        length++;
    return (length);
}

void    trim_vertical(char *tetri, int iteration)
{
    int i;
    int j;

    i = 0;
    if (iteration == 3)
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
        trim_vertical(tetri, iteration + 1);
    }
    return ;
}


void    trim_horizontal(char *tetri, int iteration)
{
    int i;
    int j;

    i = 0;
    if (iteration == 3)
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
        trim_horizontal(tetri, iteration + 1);
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
    if (k != 4) 
        return (NULL);
    if (is_valid_points(points) == 0)
        return (NULL);
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
    if (c == '.' || c == '#' || c == '\0' || c == '\n')
        return (1);
    return (0);
}

int get_next_tetri(const char *list, char *buf, char c)
{
	int ret;
	size_t j;
	size_t i;

	ret = 0;

	j = 0;
	i = 0;
	// on vérifie si les 16 premiers elements (en enlevant les \n) sont ok
	while (list[i] && j != 16)
	{
		if (char_is_valid(list[i]) == 0)
			break;
		if (list[i] == '\n')
		{
			if (list[i + 1] == '\0')
				break;
			if (list[i + 1] == '\n')
				break;
			i++;
		}
		buf[j] = list[i] == '#' ? c : list[i];
		j++;
		i++;
	}
	if (j != 16)
		return (0);
	// on a les 16 premiers éléments en enlevant les \n
	buf[j] = '\0';
	ret = i;
	return (ret);
}

t_tetri    **tokenize(char const *list)
{
    t_tetri **list_tetri;
    t_tetri *tetri;
    char *tmp_list;
    size_t i;
    size_t k;
    size_t list_len;

	int ret;

    list_tetri = (t_tetri **)malloc((28) * sizeof(t_tetri *));
    i = 0;
    k = 0;
	ret = 0;
    list_len = ft_strlen(list);
    while (list[i])
    {
        if (list[i + 1] && list[i] != '\n' && list[i + 1] != '\n')
        {
            tmp_list = (char *)malloc((list_len + 1) * sizeof(char));
            if (tmp_list == NULL)
                return (NULL);
			ret = get_next_tetri(list + i, tmp_list, 'A' + k);
			i += ret;
			if (ret == 0)
				return (NULL);
            trim_vertical(tmp_list, 0);
            trim_horizontal(tmp_list, 0);
            tetri = create_tetri(tmp_list);
            if (tetri == NULL)
                return (NULL);
            list_tetri[k++] = tetri;
        }
        else 
            i++;
    }
    list_tetri[k] = 0;
    return (list_tetri);
}
