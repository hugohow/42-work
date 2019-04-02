/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 11:13:05 by hhow-cho          #+#    #+#             */
/*   Updated: 2018/11/11 11:26:42 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval_expr.h"

int	initialize_values(int **i, int **sign, char **p_operator)
{
	*i = malloc(sizeof(int*));
	if (*i == NULL)
		return (0);
	**i = 0;
	*sign = malloc(sizeof(int));
	if (*sign == NULL)
		return (0);
	**sign = 1;
	*p_operator = malloc(sizeof(char));
	if (*p_operator == NULL)
		return (0);
	**p_operator = ' ';
	return (1);
}

int	initialize_tab(long long tab[], int **len)
{
	int i;

	i = 0;
	while (i < LENGTH_TAB_MAX)
	{
		tab[i] = 0;
		i++;
	}
	*len = malloc(sizeof(int*));
	if (*len == NULL)
		return (0);
	**len = 0;
	return (1);
}
