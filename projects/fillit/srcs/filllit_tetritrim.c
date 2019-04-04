/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filllit_tetritrim.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 18:04:53 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/04/04 18:04:53 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fillit.h"

void    tetritrim(char *tetri)
{
	trim_vertical(tetri, 0);
	trim_horizontal(tetri, 0);
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