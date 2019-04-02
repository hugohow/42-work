/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 10:22:16 by hhow-cho          #+#    #+#             */
/*   Updated: 2018/11/11 11:31:39 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval_expr.h"

int		sum_table(long long tab[], int len)
{
	long long	sum;
	int			i;

	sum = 0;
	i = 0;
	while (i < len)
	{
		sum += tab[i];
		i++;
	}
	if (sum > 2147483647)
		return (0);
	return ((int)sum);
}

void	do_operation(char *p_operator, long long tab[], int *index, int *sign)
{
	if (*p_operator == '/' && *index != 0)
	{
		tab[*index - 1] = tab[*index - 1] / tab[*index];
		tab[*index] = 0;
	}
	if (*p_operator == '*' && *index != 0)
	{
		tab[*index - 1] = tab[*index - 1] * tab[*index];
		tab[*index] = 0;
	}
	if (*p_operator == '%' && *index != 0)
	{
		tab[*index - 1] = tab[*index - 1] % tab[*index];
		tab[*index] = 0;
	}
	if (*p_operator != ' ')
		(*index)--;
	*p_operator = ' ';
	(*index)++;
	*sign = 1;
}

void	define_operator(char operator, char *p_operator, int *sign, int *i)
{
	if (operator == '-')
	{
		*sign = -1;
	}
	else
	{
		*p_operator = operator;
		*sign = 1;
	}
	(*i)++;
}

void	eval_tab(long long tab[], char *str, int *len)
{
	int		*i;
	int		*sign;
	char	*p_operator;

	if (initialize_values(&i, &sign, &p_operator) == 1)
		while (str[*i])
		{
			if (is_skippable(str[*i]) == 1)
				(*i)++;
			if (str[*i] >= '0' && str[*i] <= '9')
			{
				tab[*len] = *sign * ft_atoi(str + *i);
				*i = *i + take_integer_len(str + *i);
				do_operation(p_operator, tab, len, sign);
			}
			if (str[*i] == '(')
			{
				*i = *i + 1;
				tab[*len] = *sign * eval_expr(cut(str + *i, len_cut(str + *i)));
				*i = *i + ft_strlen(cut(str + *i, len_cut(str + *i)));
				do_operation(p_operator, tab, len, sign);
			}
			if (is_operator(str[*i]) == 1)
				define_operator(str[*i], p_operator, sign, i);
		}
}

int		eval_expr(char *str)
{
	long long	*tab;
	int			*len;
	int		sum;
	
	tab = malloc(LENGTH_TAB_MAX * sizeof(long long));
	if (initialize_tab(tab, &len) == 0)
		return (0);
	eval_tab(tab, str, len);
	sum = sum_table(tab, *len);
	free(tab);
	return (sum);
}
