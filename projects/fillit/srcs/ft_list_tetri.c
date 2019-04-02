#include "fillit.h"

size_t  ft_strlen(const char *str);


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

t_tetri    **ft_list_tetri(char const *list)
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
            trim_vertical(tmp_list);
            trim_horizontal(tmp_list);
            tetri = create_tetri(tmp_list);
            if (tetri == NULL)
                return (NULL);
            list_tetri[k++] = tetri;
        }
        else 
            i++;
    }
    if (i > 2 && list[i - 2] == '\n')
        return (NULL);
    list_tetri[k] = 0;
    return (list_tetri);
}
