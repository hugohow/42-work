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

t_tetri    **ft_list_tetri(char const *str);
char    *solve(t_tetri **list);
void    print_table(char *empty, int size);
size_t  ft_strlen(const char *str);
void    trim_horizontal(char *tetri);
void    trim_vertical(char *tetri);
void exclude_tetri(char *table, t_tetri *tetri);
void include_tetri(char *table, t_tetri *tetri, int position, int size);

#endif