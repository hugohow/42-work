#include "libft.h"
#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int get_next_line(const int fd, char **line)
{
    int j;
    char *buffer;
    char *text;
    int nb_byte;
    static char *rest;
    static int end;

    text = (char *)malloc(1000 * sizeof(char));
    buffer = (char *)malloc((BUFF_SIZE + 1) * sizeof(char)); 
    if (!rest)
        rest = (char *)malloc((BUFF_SIZE + 1) * sizeof(char)); 
    if (!end)
        end = 0;
    j = 0;
    // if (rest[0] == '\n')
    //     rest++;
    // printf("--------------\n");
    // printf("initial text :\t\t %s\n", text);
    while (rest[j] && rest[j] != '\n')
    {
        text[j] = rest[j];
        j++;
    }
    text[j] = '\0';
    // printf("end :\t\t %d\n", end);    
    // printf("text :\t\t %s\n", text);
    // printf("--------------\n");
    // printf("Transform rest :\t %s\n", rest);
    memmove(rest, rest + j + 1, ft_strlen(rest + j + 1));
    // printf("en rest :\t\t %s\n", rest);
    // printf("--------------\n");

    while (end == 0 && (nb_byte = read(fd, buffer, BUFF_SIZE)) > 0)
    {
        j = 0;
        while (j < nb_byte && buffer[j] != '\n')
            j++;
        if (j != nb_byte)
        {
            ft_strncat(text, buffer, j);
            ft_strcat(rest, buffer + j + 1);
            break;
        }
        ft_strcat(text, buffer);
    }
    *line = text;
    printf("result : %s\n\n", *line);
    if (nb_byte == 0)
        end = 1;
    return (nb_byte);
}