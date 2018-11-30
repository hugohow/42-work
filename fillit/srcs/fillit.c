#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "fillit.h"

t_tetri    **ft_list_tetri(char const *str);
char    *solve(t_tetri **list);
void    print_table(char *empty, int size);
size_t  ft_strlen(const char *str);

int main(int argc, char **argv)
{
    int fd;
    char *buf;
    char *result;
    t_tetri **list_tetri;

    if (argc != 2)
        return (0);

    fd = open(argv[1], O_RDONLY);
    if (fd != -1)
    {
        buf = malloc((17 * 26) * sizeof(char));
        if (buf == NULL)
            return (0);
        read(fd, buf, 17 * 26);

        // if (is_valid(buf) == 1)
        // {
            list_tetri = ft_list_tetri(buf);
            result = solve(list_tetri);
        //     //continue
        // }
        close(fd);
    }

    return (0);
}