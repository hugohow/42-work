/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 18:11:57 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/04/23 16:23:08 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define BUFF_SIZE 10

static t_list	*init(t_list **head, int fd)
{
	t_list *node;

	node = *head;
	while (node)
	{
		if (fd == (int)node->content_size)
			return (node);
		node = node->next;
	}
	node = ft_lstpush(head, "", fd);
	return (node);
}

static t_list	*fill(t_list *node, int fd, int *p_ret)
{
	char	buf[BUFF_SIZE + 1];
	int		nb_bytes;
	char	*to_free;

	while (ft_strchr(node->content, '\n') == 0)
	{
		nb_bytes = read(fd, buf, BUFF_SIZE);
		if (nb_bytes == 0)
			break ;
		to_free = node->content;
		buf[nb_bytes] = 0;
		node->content = ft_strjoin(node->content, buf);
		free(to_free);
	}
	*p_ret = nb_bytes;
	return (node);
}

int				get_line(t_list *node, char **line)
{
	size_t	line_len;
	char	*tmp;
	size_t	i;

	line_len = 0;
	while (((char *)node->content)[line_len] &&
		((char *)node->content)[line_len] != '\n')
		line_len++;
	tmp = (char *)malloc(sizeof(char) * (line_len + 1));
	if (tmp == NULL)
		return (-1);
	i = -1;
	while (((char *)(node->content))[++i] && i < line_len)
		tmp[i] = ((char *)(node->content))[i];
	tmp[i] = '\0';
	*line = tmp;
	if (((char *)node->content)[line_len] == '\n')
		line_len++;
	return (line_len);
}

void			free_node(t_list **head, int fd)
{
	t_list *node;
	size_t position;

	node = *head;
	position = 0;
	while (node && (int)node->content_size != fd)
	{
		node = node->next;
		position++;
	}
	ft_lstdelnode(head, position);
}

int				get_next_line(int const fd, char **line)
{
	int				ret;
	static t_list	*node;
	t_list			*head;
	char			*to_free;
	char			buf[1];

	if (fd < 0 || line == NULL || read(fd, buf, 0) < 0)
		return (-1);
	head = node;
	node = init(&head, fd);
	if (node == NULL)
		return (-1);
	ret = 0;
	node = fill(node, fd, &ret);
	buf[0] = ret == 0 ? 'F' : 'C';
	ret = get_line(node, line);
	if (ret == -1)
		return (-1);
	to_free = node->content;
	node->content = ft_strdup(node->content + ret);
	free(to_free);
	if (ret == 0 && buf[0] == 'F')
		free_node(&head, fd);
	node = head;
	return (ret ? 1 : 0);
}
