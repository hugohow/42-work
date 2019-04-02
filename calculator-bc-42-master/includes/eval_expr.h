/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 10:21:34 by hhow-cho          #+#    #+#             */
/*   Updated: 2018/11/11 11:24:13 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVAL_EXPR_H
# define EVAL_EXPR_H

# define LENGTH_TAB_MAX 99999
# include <stdio.h>
# include <stdlib.h>

int			eval_expr(char *str);
void		eval_tab(long long tab[], char *str, int *len);
long long	ft_atoi(char *str);
void		ft_putnbr(int nbr);
int			is_skippable(char c);
int			is_operator(char c);
int			initialize_values(int **i, int**sign, char **p_operator);
int			initialize_tab(long long tab[], int **len);
int			ft_strlen(char *str);
int			take_integer_len(char *str);
char		*cut(char *str, int len);
int			len_cut(char *str);
#endif
