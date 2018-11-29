#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

char    **ft_strsplit(char const *str);
char    *solve(char **list);

int is_valid(char *buf)
{
    int i;
    int j;

    i = 0;
    j = 1;
    while (buf[i])
    {
        // if (buf[i] == '\n' && buf[i+1] && buf[i+1] == '\n')
        // {
        //     printf("l");
        // }
        // printf("%c", buf[i]);
        i++;
    }
    return (1);
}

void    read_list(char **list)
{
    int i;
    i = 0;
    while (list[i])
    {
        printf("%s\n\n", list[i]);
        i++;
    }
    printf("----------------------\n\n");
}

int main(int argc, char **argv)
{
    int fd;
    char *buf;
    char **list;
    char *result;

    if (argc != 2)
        return (0);

    fd = open(argv[1], O_RDONLY);
    if (fd != -1)
    {
        buf = malloc((17 * 26) * sizeof(char));
        if (buf == NULL)
            return (0);
        read(fd, buf, 17 * 26);
        if (is_valid(buf) == 1)
        {
            list = ft_strsplit(buf);
            read_list(list);
            result = solve(list);
            //continue
        }
        close(fd);
    }

    return (0);
}