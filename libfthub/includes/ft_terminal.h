/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_terminal.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 12:05:01 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/04/12 12:05:02 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TERMINAL_H
# define FT_TERMINAL_H

enum editorKey 
{
  ARROW_LEFT = 1000,
  ARROW_RIGHT,
  ARROW_UP,
  ARROW_DOWN
};

#include <sys/ioctl.h>
#include <signal.h>
#include <curses.h>
#include <term.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include <termios.h>

int ft_init_terminal(struct termios *orig_termios, struct termios *new_termios);
int ft_read_key();
void ft_exit_terminal(struct termios *orig_termios);

#endif