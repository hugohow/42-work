#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read_element(t_list *elem)
{
    ft_putstr((char *)(elem->content));
}

char *get_line(t_list **begin_text)
{
    t_list *element;
    char *line;
    unsigned int size;

    element = *begin_text;
    size = 0;
    while (element)
    {
        size += element->content_size;
        element = element->next;
    }
    line = malloc(size + 1);
    element = *begin_text;
    while (element)
    {
        line = ft_strjoin(line, (char *)(element->content));
        element = element->next;
    }
    return (line);
}

int get_next_line(const int fd, char **line)
{
    int j;
    char *buffer;
    t_list *text_list;
    t_list **begin_text;
    char *text;
    int nb_byte;
    static char *rest;

    text = (char *)malloc((BUFF_SIZE + 1) * sizeof(char));
    buffer = (char *)malloc((BUFF_SIZE + 1) * sizeof(char)); 
    if (!rest)
        rest = (char *)malloc((BUFF_SIZE + 1) * sizeof(char)); 
    j = 0;
    if (rest[0] == '\n')
        rest++;
    while (rest[j] && rest[j] != '\n')
    {
        text[j] = rest[j];
        j++;
    }
    text[j] = '\0';
    text_list = ft_lstnew(text, j);
    begin_text = (t_list **)malloc(sizeof(t_list *));
    *begin_text = text_list;
    text_list->next = NULL;
    // printf("end :\t\t %d\n", end);    
    // printf("text :\t\t %s\n", text);
    // printf("--------------\n");
    // printf("Transform rest :\t %s\n", rest);
    // printf("rest avant : %s\n\n", rest);
    rest = rest + j;
    // printf("rest après : %s\n\n", rest);
    // printf("j : \t %d\n", j);
    // printf("ft_strlen(rest + j + 1) : \t %zu\n", ft_strlen(rest + j + 1));    
    // memmove(rest, rest + j + 1, ft_strlen(rest + j + 1));
    // printf("en rest :\t\t %s\n", rest);
    // printf("--------------\n");

    while ((nb_byte = read(fd, buffer, BUFF_SIZE)) > 0)
    {
        j = 0;
        while (j < nb_byte && buffer[j] != '\n')
            j++;
        if (j != nb_byte)
        {
            text_list->next = ft_lstnew(ft_strsub(buffer, 0, j), j);
            // printf("text_list->next : %s\n", ft_strsub(buffer, 0, j));
            // printf("nb_byte : %d\n", nb_byte);
            text_list = text_list->next;
            // ft_strncat(text, buffer, j);
            ft_strcat(rest, buffer + j + 1);
            break;
        }
        text_list->next = ft_lstnew(ft_strsub(buffer, 0, nb_byte), BUFF_SIZE);
        // printf("text_list->next : %s\n", ft_strsub(buffer, 0, nb_byte));
        // printf("nb_byte : %d\n", nb_byte);
        text_list = text_list->next;
    }
    *line = get_line(begin_text);
    if (nb_byte < 0)
        return (-1);
    if (ft_strlen(*line) > 0)
        return (1);
    return (0);
}