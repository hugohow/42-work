#include "ft_init_terminal.h"

int ft_init_terminal(struct termios *orig_termios, struct termios *new_termios)
{
    char *term_name;
    int ret;

    if ((term_name = getenv("TERM")) == NULL)
        return (-1);

	ret = tgetent(NULL, term_name);
    if (ret == -1)
    {
        printf("Could not access to the termcap database..\n");
        return (-1);
    }
    else if (ret == 0)
    {
        printf("Terminal type '%s' is not defined in termcap database (or have too few informations).\n", term_name);
        return (-1);
    }
	tcgetattr(STDIN_FILENO, orig_termios);
	*new_termios = *orig_termios;
	// new_termios->c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
	// new_termios->c_oflag &= ~(OPOST);
	// new_termios->c_cflag |= (CS8);
	// new_termios->c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
	
    new_termios->c_lflag &= ~(ICANON | ECHO);
	new_termios->c_lflag |= ISIG;
    
    new_termios->c_cc[VMIN] = 1;
	new_termios->c_cc[VTIME] = 1;
  	tcsetattr(0, TCSAFLUSH, new_termios);
    return (0);
}