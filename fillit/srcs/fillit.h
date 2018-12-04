#ifndef FILLIT_H
# define FILLIT_H

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

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
char    *solve(t_tetri **list, size_t list_len);
void    print_table(char *empty, int size);
size_t  ft_strlen(const char *str);

#endif