#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int get_next_line(const int fd, char **line);

int main(void)
{
    int fd;
    char **line;

    line = (char **)malloc(sizeof(char*));

    printf("debut\n");
    fd = open("testfile", O_RDONLY);
    get_next_line(fd, line);
    get_next_line(fd, line);
    get_next_line(fd, line);
    get_next_line(fd, line);
    get_next_line(fd, line);
    get_next_line(fd, line);
    get_next_line(fd, line);
    get_next_line(fd, line);
    get_next_line(fd, line);
    get_next_line(fd, line);
    get_next_line(fd, line);
    return 0;
}