#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

char *cut_str(char *str, int end)
{
    int i;
    char *output;

    output = malloc((end + 1) * sizeof(char));
    i = 0;
    while (i++ < end)
    {
        output[i] = str[i];
    }
    output[i] = '\0';
    return (output);
}

int get_next_line(const int fd, char **line)
{
    // int current_index;
    int nb_byte;
    int i;
    int j;
    int nb_line;
    char *buffer;
    buffer = (char *)malloc((1000) * sizeof(char)); 

    // *line = (char *)malloc((BUFF_SIZE) * sizeof(char));
    i = 0;
    nb_line = 0;
    while ((nb_byte = read(fd, (buffer + i), BUFF_SIZE)) > 0)
    {
        // buffer = (char *)malloc(BUFF_SIZE*2 * sizeof(char));
        j = 0;
        while (j < nb_byte)
        {
            if (*(buffer + i + j) == '\n')
                break;
            // if (nb_line > index_line)
                // break;
            j++;
        }
        if (j != nb_byte)
        {
            printf("buffer : %s\n", buffer);
            *line = cut_str(buffer, i + j);
            printf("*line : %s\n", *line);
            printf("return : %d\n", 1);
            return (1);
            break;
        }
        // printf("(*line + i) : %s\n", (*line + i));
        // printf("nb_byte : %d\n", nb_byte);
        i += BUFF_SIZE;
    }
    printf("buffer : %s\n", (buffer));
    printf("return : %d\n", nb_byte);
    return (nb_byte);
}