/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 18:54:09 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/04/03 20:54:35 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#define LIMIT_TETRIS 26

typedef struct s_position
{
    int row; 
    int col;
}               t_position;

typedef struct s_tetri
{
    t_position *points;
    char       letter;
}               t_tetri;

t_tetri    **tokenize(char const *str);
char    *solve(t_tetri **list);
void    print_table(char *empty, int size);
size_t  ft_strlen(const char *str);
void    trim_horizontal(char *tetri, int iteration);
void    trim_vertical(char *tetri, int iteration);
void exclude_tetri(char *table, t_tetri *tetri);
void include_tetri(char *table, t_tetri *tetri, int position, int size);
int is_valid_input(char *buf);
int is_valid_points(t_position *points);
#endif