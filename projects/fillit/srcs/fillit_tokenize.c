/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_tokenize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 18:04:59 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/04/04 18:05:01 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fillit.h"

size_t ft_strlen(const char *str)
{
    size_t length;

    length = 0;
    while(str[length])
        length++;
    return (length);
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
    return (tetri);
}


int get_next_tetri(const char *list, char *buf, char c)
{
	size_t j;
	size_t i;
	j = 0;
	i = 0;
	// on vérifie si les 16 premiers elements (en enlevant les \n) sont ok
	while (list[i] && j != 16)
	{
		if (list[i] == '\n')
			i++;
		buf[j] = list[i] == '#' ? c : list[i];
		j++;
		i++;
	}
	buf[j] = '\0';
	return (i);
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
            tetritrim(tmp_list);
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
