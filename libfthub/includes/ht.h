/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 16:05:12 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/08 22:52:50 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HT_H
# define HT_H
# include <strings.h>
# include <stdlib.h>
# include "libft.h"
# define CLUSTER_SIZE 53

typedef struct	s_node_ht
{
	const char			*key;
	void				*datum;
	struct s_node_ht	*next;
}				t_node_ht;

typedef struct	s_ht
{
	size_t		size;
	size_t		count;
	t_node_ht	**list;
}				t_ht;

t_ht			*ft_ht_create(void);
t_node_ht		*ft_ht_add(t_ht *hash_table, const char *key, void *datum);
t_node_ht		*ft_ht_get(t_ht *hash_table, const char *key);
void			ft_ht_free(t_ht **p_hash_table);
int				ft_strcmp(const char *s1, const char *s2);
void			ft_memdel(void **ap);
int				ft_ht_get_hash(const char *str, size_t size);
#endif
