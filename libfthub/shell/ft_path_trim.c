/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_trim.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 16:37:59 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/25 14:01:26 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static void ft_list_free(char **list)
{
	size_t i;

	i = 0;
	while (list && list[i])
	{
		ft_memdel((void **)(&(list[i])));
		i++;
	}
	ft_memdel((void **)(list));
}

static char **shift_left(char **list, int i, int nb)
{
	int j;

	j = i + 1;
	if (j - nb >= 0)
	{
		while (list[j])
		{
			list[j - nb] = list[j];
			j++;
		}
		list[j - nb] = 0;
	}
	return (list);
}

static char **clean_list(char **list)
{
	int i;

	i = 0;
	while (list && list[i])
	{
		if (ft_strcmp(list[i], ".") == 0)
		{
			list = shift_left(list, i , 1);
			return (clean_list(list));
		}
		else if (ft_strcmp(list[i], "..") == 0)
		{
			if (i > 0)
				list = shift_left(list, i , 2);
			else
				list = shift_left(list, i , 1);
			return (clean_list(list));
		}
		else
			i++;
	}
	return (list);
}

static char *get_new_path(char *new_path, char **list)
{
	int i;

	i = 0;
	while (list && list[i])
	{
		ft_strcat(new_path, list[i]);
		if (list[i + 1] != 0 && new_path[ft_strlen(new_path) - 1] != '/')
			ft_strcat(new_path, "/");
		i++;
	}
	if (new_path[ft_strlen(new_path) - 1] == '/' && ft_strlen(new_path) != 1)
		new_path[ft_strlen(new_path) - 1] = 0;
	return (new_path);
}


char *ft_path_trim(char *abs_path)
{
	char **list;
	char *new_path;

	list = ft_str_separate(abs_path, '/');
	if (list == NULL)
		return (abs_path);
	if (!(new_path = ft_memalloc(sizeof(char) * (ft_strlen(abs_path) + 1))))
		return (NULL);
	if (ft_strcmp(list[0], "") == 0)
		ft_strcat(new_path, "/");
	list = clean_list(list);
	new_path = get_new_path(new_path, list);
	ft_list_free(list);
	return (new_path);
}