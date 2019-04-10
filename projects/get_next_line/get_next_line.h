/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 18:12:01 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/04/10 19:33:50 by hhow-cho         ###   ########.fr       */
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
void    ft_putstr(char const *str);
char	*ft_strncat(char *s1, const char *s2, size_t n);
char    *ft_strcat(char *s1, const char *s2);
char    *ft_strjoin(char const *str1, char const *str2);
size_t  ft_strlen(const char *str);
char    *ft_strsub(char const *s, unsigned int start, size_t len);
void	ft_lstfree(t_list *head);
char	*ft_strcpy(char *dst, const char *src);
void    *ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memalloc(size_t size);
char    *ft_strchr(const char *str, int c);


t_list	*ft_lstpop(t_list **p_head, void (*del)(void *, size_t));
t_list	*ft_lstpush(t_list **head, void const *content, size_t content_size);

void	ft_lstadd(t_list **alst, t_list *new_el);
char	*ft_strnew(size_t size);
void	ft_strclr(char *s);
char	*ft_strdup(const char *s1);
#endif