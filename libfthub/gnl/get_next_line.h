/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 18:12:01 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/04/13 13:41:39 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

int					get_next_line(const int fd, char **line);
char				*ft_strjoin(char const *str1, char const *str2);
char				*ft_strchr(const char *str, int c);
t_list				*ft_lstpush(t_list **head, void const *d, size_t d_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelnode(t_list **head, size_t pos);
char				*ft_strdup(const char *s1);
#endif
