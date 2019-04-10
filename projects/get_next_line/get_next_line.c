/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 18:11:57 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/04/10 19:33:05 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "get_next_line.h"




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


int get_line(t_list	*node, char **line)
{
	size_t	line_len;
	char *tmp;
	size_t		i;

	line_len = 0;
	while (((char *)node->content)[line_len] && ((char *)node->content)[line_len] != '\n')
		line_len++;


	i = 0;
	tmp = (char *)malloc(sizeof(char) * line_len + 1);
	if (tmp == NULL)
		return (-1);
	while (((char *)(node->content))[i] && i < line_len)
	{
		tmp[i] = ((char *)(node->content))[i];
		i++;
	}
	tmp[i] = '\0';
	*line = tmp;
	if (((char *)node->content)[line_len] == '\n')
		line_len++;
	return (line_len);
}

int				get_next_line(int const fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	int				nb_bytes;
	int				line_len;
	static t_list	*node;
	t_list			*head;
	char			*to_free;

	if (fd < 0 || line == NULL || read(fd, buf, 0) < 0)
		return (-1);
	head = node;
	node = init(&head, fd);
	if (node == NULL)
		return (-1);
	while (ft_strchr(node->content, '\n') == 0)
	{
		nb_bytes = read(fd, buf, BUFF_SIZE);
		if (nb_bytes == 0)
			break;

		to_free = node->content;
		buf[nb_bytes] = 0;
		node->content = ft_strjoin(node->content, buf);
		free(to_free);
	}

	line_len = get_line(node, line);
	if (line_len == -1)
		return (-1);
	to_free = node->content;
	node->content = ft_strdup(node->content + line_len);
	free(to_free);

	node = head;
	return (line_len ? 1 : 0);
}