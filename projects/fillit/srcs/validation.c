#include "fillit.h"
#define ABS(Value) ((Value > 0) ? Value : -Value)

int is_perpendiculaire(t_position point_1, t_position point_2)
{
	// printf("point_1.col : %d, point_1.row : %d\n", point_1.col, point_1.row);
	// printf("point_2.col : %d, point_2.row : %d\n", point_2.col, point_2.row);
	// printf("ABS(point_1.col - point_2.col) %d, ABS(point_1.row - point_2.row) : %d\n", ABS((point_1.col - point_2.col)), ABS((point_1.row - point_2.row)));
	// printf("ABS(point_1.col - point_2.col) %d, ABS(point_1.row - point_2.row) : %d\n", ABS((point_1.col - point_2.col)), ABS((point_1.row - point_2.row)));
	if (ABS((point_1.col - point_2.col)) == 1 && ABS((point_1.row - point_2.row)) == 0)
		return (1);
	if (ABS((point_1.col - point_2.col)) == 0 && ABS((point_1.row - point_2.row)) == 1)
		return (1);
	return (0);
}

int is_valid_points(t_position *points)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			// printf("i : %d, j : %d\n", i, j);
			if (is_perpendiculaire(points[i], points[j]) == 1)
				break;
			j++;
		}
		if (j == 4)
			return (0);
		i++;
	}
	return (1);
}

int is_valid_input(char *buf)
{
	size_t i;
	size_t j;

	i = 0;
	if (buf[i] != '.' && buf[i] != '#')
		return (0);
	while (buf[i])
	{
		j = 0;
		while (j < 20)
		{
			if ((j + 1) % 5 == 0)
			{
				if (buf[j + i] != '\n')
					return (0);
				// printf("n : %lu, c : %c\n", j + i, buf[j + i]);	
			}
			else
			{
				if (buf[j + i] != '.' && buf[j + i] != '#')
					return (0);
				// printf(".: %lu, c : %c\n", j + i, buf[j + i]);	
			}	
			j++;
		}
	 	i += j;
		if (buf[i] == 0)
			return (1);
		if (buf[i] != '\n')
			return (0);
		// printf("0 ou n : %lu, c : c : %d\n", i, buf[i]);
		i++;
	}
	return (0);
}
