/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:42:12 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/04/12 16:39:57 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_print_flag(t_flag *flag)
{
	ft_printf("\n------------------\n");
	ft_putchar(flag->conv);
	ft_putstr("\n");
	// ft_putstr("length : ");
	// ft_putnbr(flag->length);
	// ft_putstr("\n");
	// ft_putstr("precision : ");
	// ft_putnbr(flag->precision);
	// ft_putstr("\n");
	// ft_putstr("width : ");
	// ft_putnbr(flag->width);
	// ft_putstr("\n");
	// ft_putstr("zero : ");
	// ft_putnbr(flag->zero);
	// ft_putstr("\n");
	// ft_putstr("plus : ");
	// ft_putnbr(flag->plus);
	// ft_putstr("\n");
	// ft_putstr("minus : ");
	// ft_putnbr(flag->minus);
	// ft_putstr("\n");
	// ft_putstr("space : ");
	// ft_putnbr(flag->space);
	// ft_putstr("\n");
	// ft_putstr("hash : ");
	// ft_putnbr(flag->hash);
	ft_putstr("\n------------------\n");
}