#include "fillit.h"
#define ABS(Value) ((Value > 0) ? Value : -Value)

int is_perpendiculaire(t_position point_1, t_position point_2)
{
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
	int count;

	i = 0;
	count = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			// printf("i : %d, j : %d\n", i, j);
			if (is_perpendiculaire(points[i], points[j]) == 1)
			{
				count++;
				if (count >= 6)
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
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
