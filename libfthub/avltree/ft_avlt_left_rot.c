/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avlt_left_rot.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 15:54:00 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/05/07 17:41:59 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "avltree.h"

static int max(int a, int b)
{
	return (a > b ? a : b);
}

static int get_height(t_node_avlt *node)
{
	if (node == NULL)
		return (0);
	return (node->height);
}

//   x
//        y
//     z

//      y
// x
//     z

t_node_avlt	*ft_avlt_left_rot(t_node_avlt *x)
{
	t_node_avlt *y;
	t_node_avlt *z;

	if (x == NULL)
		return (NULL);
	y = x->right;
	z = y->left;

	y->left = x;
	x->right = z;

	x->height = 1 + max(get_height(x->left), get_height(x->right));
	y->height = 1 + max(get_height(y->left), get_height(y->right));

	return (y);
}
