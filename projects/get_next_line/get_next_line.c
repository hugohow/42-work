/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 18:11:57 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/04/09 17:47:57 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "get_next_line.h"
#define offsetof(TYPE, MEMBER) ((size_t)&((TYPE *)0)->MEMBER)
#define typeof __typeof__
#define containerof(ptr, type, member) ({                   \
    const typeof( ((type *)0)->member) *__mptr == (ptr);    \
    (type *)( (char *)__mptr - offsetof(type, member)); })
#define SEPARATOR '\n'
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *get_line(t_list **head_node, char **p_rest)
{
    t_list *node;
    int i;
    unsigned int size;
    char *line;

    node = *head_node;
    size = 0;
    while (node)
    {
        size += node->content_size + 1;
        node = node->next;
    }
    line = (char *)ft_memalloc((size + 1) * sizeof(char));
    if (line == NULL)
        return (NULL);

    node = *head_node;
    //printf("Test ");
    while (node && node->content)
    {
        ((char *)(node->content))[node->content_size] = '\0';
        // printf("node->content_size : %d\n", node->content_size);
        // printf("(char *)(node->content) : %s\n", (char *)(node->content));
        line = ft_strncat(line, (char *)(node->content), size);
        node = node->next;
    }
    i = 0;
    while (line[i])
    {
        if (line[i] == '\n')
            break;
        i++;
    }
    line[i] = '\0';
     //printf("Test line : %s\n", line);
    *p_rest = line + i + 1;
    return (line);
}

t_list *init_list(char **rest)
{
    t_list *head_node;
    int i;

    i = 0;
    head_node = ft_lstnew(*rest, ft_strlen(*rest));
    while ((*rest)[i])
    {
        if ((*rest)[i] == '\n')
            break;
        i++;
    }
    if ((*rest)[i] == 0)
        ft_memset(*rest, 0, BUFF_SIZE);
    else
        ft_memmove(*rest, *rest + i + 1, BUFF_SIZE);

    return (head_node);
}

int    fill_list(t_list *head_node, int fd)
{
    t_list *node;
    int ret;
    char *buffer;

    buffer = (char *)ft_memalloc((BUFF_SIZE + 1) * sizeof(char)); 
    if (buffer == NULL)
        return (-1);
    node = head_node;

    ret = read(fd, buffer, BUFF_SIZE);
    if (ret < -1)
        return (-1);
    buffer[ret] = '\0';
    //printf("buffer : %s\n", buffer);
    //printf("ret : %d\n", ret);
    node = ft_lstpush(head_node, buffer, ret + 1);
    free(buffer);
    buffer = NULL;
    if (node == NULL)
        return (-1);
    return (ret);
}

int has_back_n(char *str)
{
    while (*str)
    {
        if (*str == '\n')
            return (1);
        str++;
    }
    return (0);
}

int has_a_line(t_list *head_node)
{
    t_list *node;

    node = head_node;
    while (node)
    {
        if (has_back_n((char *)node->content) == 1)
            return (1);
        node = node->next;
    }
    return (0);
}


int get_next_line(const int fd, char **line)
{
    t_list *head_node;
    static char *rest;
    int line_size;
    int ret;
    if (!rest)
    {
        rest = (char *)ft_memalloc((BUFF_SIZE + 1) * sizeof(char)); 
        if (rest == NULL)
            return (-1);
    }

    line_size = 0;
    head_node = init_list(&rest);
    ret = 1;
    while (has_a_line(head_node) == 0 && ret > 0)
    {
        ret = fill_list(head_node, fd);
    }
    if (ret == -1)
        return (-1);
    *line = get_line(&head_node, &rest);
    if (*line == NULL)
        return (-1);
    // ft_lstfree(head_node);
    head_node = NULL;
    line_size = ft_strlen(*line);
    if (line_size == 0 && ft_strlen(rest) == 0)
        return (0);
    return (1);
}