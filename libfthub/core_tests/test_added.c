/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_added.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 16:08:11 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/04/23 16:23:45 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" /* compile with -I./ */

#include <assert.h>

int main(void)
{
	printf("-------------Test ft_strcat_r-------------\n");
	char dst[99]= "test";

  	printf("\033[32mCheck basic \033[00m\n");
	assert(ft_strcmp(ft_strcat_r("Hello World", dst), "Hello Worldtest") == 0);

  	printf("\033[32mCheck basic \033[00m\n");
	assert(ft_strcmp(ft_strcat_r("\n", dst), "\nHello Worldtest") == 0);

  	printf("\033[32m0 value \033[00m\n");
	assert(ft_strcmp(ft_strcat_r("", dst), "\nHello Worldtest") == 0);

	return (0);
}
