#include "fillit.h"


size_t ft_strlist(t_tetri **list_tetri)
{
    size_t list_len;

    list_len = 0;
    while (list_tetri[list_len] != 0)
    {
        list_len++;
    }
    return (list_len);
}

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
        buf = malloc((25 * 28) * sizeof(char));
        if (buf == NULL)
            return (0);
        read(fd, buf, 25 * 28);
        list_tetri = ft_list_tetri(buf);
        if (list_tetri == NULL)
            printf("error\n"); 
        else
            result = solve(list_tetri, ft_strlist(list_tetri));
        close(fd);
    }

    return (0);
}