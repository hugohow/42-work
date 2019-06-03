/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avlt_apply_postorder.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 14:42:57 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/03 12:41:34 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "avltree.h"

void	ft_avlt_apply_postorder(t_node_avlt *root, void (*f)(t_node_avlt *))
{
	if (root == NULL)
		return ;
	ft_avlt_apply_postorder(root->left, f);
	ft_avlt_apply_postorder(root->right, f);
	f(root);
}
