#include "ft_exit_terminal.h"

void ft_exit_terminal(struct termios *orig_termios)
{
    tcsetattr(0, TCSAFLUSH, orig_termios);
	exit(0);
}