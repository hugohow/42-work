/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 13:31:39 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/05/09 14:16:44 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include "libft.h"

t_list	**ft_stack_init(void);
void	ft_stack_pop(t_list **stack_top);
void	ft_stack_push(t_list **stack_top, void const *content, size_t content_size);
void	ft_stack_display(t_list **stack_top, void (*ft_print)(t_list *node));
#endif