/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 16:34:02 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/05/09 16:34:31 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

int ft_read_key(void)
{
  int nread;
  char c;
  char seq[3];

  while ((nread = read(STDIN_FILENO, &c, 1)) != 1)
  {
    if (nread == -1)
		return (0);
  }
  if (c == '\x1b') 
  {
    if (read(STDIN_FILENO, &seq[0], 1) != 1) return ('\x1b');
    if (read(STDIN_FILENO, &seq[1], 1) != 1) return ('\x1b');
    if (seq[0] == '[') {
      switch (seq[1]) {
        case 'A': return ARROW_UP;
        case 'B': return ARROW_DOWN;
        case 'C': return ARROW_RIGHT;
        case 'D': return ARROW_LEFT;
      }
    }
    return ('\x1b');
  }
  else 
  {
    return (c);
  }
}