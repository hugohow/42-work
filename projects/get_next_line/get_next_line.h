/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 18:12:01 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/04/10 20:58:36 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#define BUFF_SIZE 1
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

typedef struct      s_list
{
    void            *content;
    size_t          content_size;
    struct s_list   *next;
}                   t_list;

int     get_next_line(const int fd, char **line);
t_list  *ft_lstnew(void const *content, size_t content_size);
char    *ft_strjoin(char const *str1, char const *str2);
size_t  ft_strlen(const char *str);
char    *ft_strchr(const char *str, int c);
t_list	*ft_lstpush(t_list **head, void const *content, size_t content_size);
char	*ft_strdup(const char *s1);
#endif