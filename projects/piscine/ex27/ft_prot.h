/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prot.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 15:43:54 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/04/02 15:43:56 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PROT_H
# define FT_PROT_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>

int	ft_check_param_num(int argc);
void	ft_read_file(char *name);
void	ft_putchar(char c);
void	ft_putstr(char *str);
#endif
