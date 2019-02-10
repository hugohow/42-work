#ifndef FT_SELECT_H
#define FT_SELECT_H

#include <stdlib.h>
#include <stdio.h>

#include <curses.h>
#include <term.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

void    ft_putstr(char const *str);
int     ft_printf(const char* format, ...);
int     ft_init_terminal(struct termios *orig_termios, struct termios *new_termios);
int     ft_read_key(void);
void    ft_exit_terminal(struct termios *orig_termios);
#endif