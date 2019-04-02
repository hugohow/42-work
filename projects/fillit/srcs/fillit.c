#include "fillit.h"

#define LIMIT_TETRIS 26

int main(int argc, char **argv)
{
    int fd;
    char *buf;
    char *result;
    t_tetri **list_tetri;

    if (argc != 2)
    {
        printf("usage");
        return (0);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd != -1)
    {
        buf = malloc((LIMIT_TETRIS * 28) * sizeof(char));
        if (buf == NULL)
            return (0);
        read(fd, buf, LIMIT_TETRIS * 28);
		list_tetri = ft_list_tetri(buf);
		if (list_tetri == NULL)
		{
			printf("error\n");
			return (0);
		}
		
		result = solve(list_tetri);
		free(buf);
        close(fd);
    }

    return (0);
}