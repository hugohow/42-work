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