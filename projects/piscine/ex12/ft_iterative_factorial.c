/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 17:26:53 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/04/01 17:31:24 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	unsigned long long result;

	if (nb <= 0)
		return (0);
	result = 1;
	while (nb != 0)
	{
		result = result * nb;
		nb--;
	}
	return (int)result;
}
