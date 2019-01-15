#include "libft.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int get_next_line(const int fd, char **line);

int main(void)
{
    int fd;
    char **line;

    line = (char **)malloc(sizeof(char*));
    fd = open("testfile", O_RDONLY);
    get_next_line(fd, line);
    ft_putstr(*line);
    ft_putchar('\n');
    get_next_line(fd, line);
    ft_putstr(*line);
    ft_putchar('\n');
    get_next_line(fd, line);
    ft_putstr(*line);
    ft_putchar('\n');
    get_next_line(fd, line);
    ft_putstr(*line);
    ft_putchar('\n');
    get_next_line(fd, line);
    ft_putstr(*line);
    ft_putchar('\n');
    get_next_line(fd, line);
    ft_putstr(*line);
    ft_putchar('\n');
    get_next_line(fd, line);
    ft_putstr(*line);
    ft_putchar('\n');
    get_next_line(fd, line);
    ft_putstr(*line);
    ft_putchar('\n');
    get_next_line(fd, line);
    ft_putstr(*line);
    ft_putchar('\n');
    get_next_line(fd, line);
    ft_putstr(*line);
    ft_putchar('\n');
    return 0;
}