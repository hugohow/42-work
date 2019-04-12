/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:11:26 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/04/12 17:08:03 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// typedef struct	s_flag
// {
//  char type[2];
// 	char conv;
// 	int length;
// 	int precision;
// 	int width;
// 	int zero;
// 	int plus;
// 	int minus;
// 	int space;
// 	int hash;
// }				t_flag;


t_flag *ft_create_flag(char *str)
{
	t_flag *flag;

	flag = (t_flag *)malloc(sizeof(t_flag));
	if (flag == NULL)
		return (NULL);
	flag->conv = str[ft_strlen(str) - 1];
	flag->length = ft_flag_get_length(str);
	flag->precision = ft_flag_get_precision(str);
	flag->width = ft_flag_get_width(str);
	flag->zero = ft_flag_get_zero(str);
	flag->plus = ft_flag_get_plus(str);
	flag->minus = ft_flag_get_minus(str);
	flag->space = ft_flag_get_space(str);
	flag->hash = ft_flag_get_hash(str);
	return (flag);		
}