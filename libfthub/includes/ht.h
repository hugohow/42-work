/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ht.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 16:05:12 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/04/17 17:40:43 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HT_H
# define HT_H
# include <strings.h>
# include <stdlib.h>

typedef struct	s_node_ht
{
	const char			*key;
	void				*datum;
	struct s_node_ht	*next;
}				t_node_ht;

typedef struct	s_ht
{
	size_t		size;
	t_node_ht	**table;
}				t_ht;

t_ht			*ft_ht_create(size_t size);
t_node_ht		*ft_ht_add(t_ht *hash_table, const char *key, void *datum);
t_node_ht		*ft_ht_get(t_ht *hash_table, const char *key);
void			ft_ht_free(t_ht **p_hash_table);
int				ft_strcmp(const char *s1, const char *s2);
void			ft_memdel(void **ap);
#endif
