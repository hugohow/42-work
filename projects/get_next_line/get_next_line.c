/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 18:11:57 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/04/07 19:53:24 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "get_next_line.h"
#define offsetof(TYPE, MEMBER) ((size_t)&((TYPE *)0)->MEMBER)
#define typeof __typeof__
#define containerof(ptr, type, member) ({                   \
    const typeof( ((type *)0)->member) *__mptr == (ptr);    \
    (type *)( (char *)__mptr - offsetof(type, member)); })
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *get_line(t_list **head_node)
{
    t_list *element;
    unsigned int size;
    char *line;

    element = *head_node;
    size = 0;
    while (element)
    {
        size += element->content_size;
        element = element->next;
    }
    line = (char *)malloc((size + 1) * sizeof(char));
    if (line == NULL)
        return (NULL);
    line[0] = '\0';
    element = *head_node;
    while (element)
    {
        line = ft_strcat(line, (char *)(element->content));
        element = element->next;
    }
    return (line);
}

t_list *init_list(char **rest)
{
    t_list *head_node;
    char *total;
    int j;
    total = (char *)malloc((BUFF_SIZE + 1) * sizeof(char));
    j = 0;
    if ((*rest)[0] && (*rest)[0] == '\n')
        (*rest)++;
    while ((*rest)[j] && (*rest)[j] != '\n')
    {
        total[j] = (*rest)[j];
        j++;
    }
    total[j] = '\0';
    ft_memmove(*rest, *rest + j, BUFF_SIZE);
    head_node = ft_lstnew(total, j);
    if (total)
        free(total);
    total = NULL;
    return (head_node);
}

int get_next_line(const int fd, char **line)
{
    int j;
    char *buffer;
    t_list *node;
    t_list *head_node;
    int nb_byte;
    static char *rest;
    char *tmp_content;
    int line_size;
 
    tmp_content = NULL;
    buffer = (char *)malloc((BUFF_SIZE + 1) * sizeof(char)); 
    if (buffer == NULL)
        return (-1);
    if (!rest)
    {
        rest = (char *)malloc((BUFF_SIZE + 1) * sizeof(char)); 
        if (rest == NULL)
            return (-1);
        ft_memset(rest, 0, BUFF_SIZE + 1);
    }
    line_size = 0;
    head_node = init_list(&rest);
    node = head_node;
    while ((nb_byte = read(fd, buffer, BUFF_SIZE)) > 0)
    {
        j = 0;
        while (j < nb_byte && buffer[j] != '\n')
            j++;
        tmp_content = ft_strsub(buffer, 0, j);
        node->next = ft_lstnew(tmp_content, BUFF_SIZE);
        if (tmp_content)
            free(tmp_content);
        tmp_content = NULL;
        node = node->next;
        if (j < nb_byte)
        {
            ft_strncat(rest, buffer + j + 1, BUFF_SIZE);
            break;
        }
    }
    if (nb_byte < 0)
        return (-1);
    *line = get_line(&head_node);
    if (*line == NULL)
        return (-1);
    if (buffer)
        free(buffer);
    buffer = NULL;
    ft_lstfree(head_node);
    head_node = NULL;
    line_size = ft_strlen(*line);
    if (line_size == 0 && nb_byte == 0 && ft_strlen(rest) == 0)
        return (0);
    return (1);
}