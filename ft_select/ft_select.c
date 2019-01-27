#include "ft_select.h"
#define BAUDRATE B38400
#define MODEMDEVICE "/dev/ttyS1"
#define _POSIX_SOURCE 1 /* code source conforme à POSIX */
#define FALSE 0
#define TRUE 1
#define CTRL_KEY(k) ((k) & 0x1f)

void print_example()
{
	char buf[1024];
	char buf2[30];
	char *ap = buf2;
	char *clearstr, *gotostr, *standstr, *stendstr;

	tgetent(buf, getenv("TERM"));

	clearstr = tgetstr("cl", &ap);
	gotostr = tgetstr("cm", &ap);
	standstr = tgetstr("so", &ap);
	stendstr = tgetstr("se", &ap);

	fputs(clearstr, stdout);
	fputs(tgoto(gotostr, 20, 10), stdout);
	printf("Hello, ");
	fputs(standstr, stdout);
	printf("world");
	fputs(stendstr, stdout);
	putchar('!');
}

void editorDrawRows() {
  int y;
  for (y = 0; y < 24; y++) {
    write(STDOUT_FILENO, "~\r\n", 3);
  }
}


int main(int argc, char **argv)
{
	int i;
	char buf[1];
	char *term_name;
	int ret;
	int res;
	char c;
	struct termios *termios_p;
	struct termios *new_termios_p;
	int stop;

	i = 1;
	if (argc < 2)
		return (0);


    if ((term_name = getenv("TERM")) == NULL)
        return (-1);

	ret = tgetent(NULL, term_name);

    if (ret == -1)
    {
        printf("Could not access to the termcap database..\n");
        return -1;
    }
    else if (ret == 0)
    {
        printf("Terminal type '%s' is not defined in termcap database (or have too few informations).\n", term_name);
        return -1;
    }

	termios_p = malloc(sizeof(struct termios));
	new_termios_p = malloc(sizeof(struct termios));
  tcgetattr(0, termios_p);
	*new_termios_p = *termios_p;
	new_termios_p->c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
	new_termios_p->c_oflag &= ~(OPOST);
	new_termios_p->c_cflag |= (CS8);
	new_termios_p->c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
	new_termios_p->c_cc[VMIN] = 1;
	new_termios_p->c_cc[VTIME] = 1;
  tcsetattr(0, TCSAFLUSH, new_termios_p);


	// new_termios_p = malloc(sizeof(struct termios));
	// // new_termios_p->c_cflag = BAUDRATE | CRTSCTS | CS8 | CLOCAL | CREAD;
	// // new_termios_p->c_iflag = IGNPAR;
	// // new_termios_p->c_oflag = 0;
	// // new_termios_p->c_lflag = 0;
	// // new_termios_p->c_cc[VTIME]    = 0;
	// // new_termios_p->c_cc[VMIN]     = 0;
	// *new_termios_p = *termios_p;
	// new_termios_p->c_lflag &= ~(ECHO);

	// tcsetattr(0, TCSANOW, new_termios_p);


	while (argv[i])
	{
		// ft_putstr(argv[i]);
		i++;
	}

	stop = 0;

	c = 0;
	write(STDOUT_FILENO, "\x1b[2J", 4);
 	 while (1) {
		char c = '\0';
		editorDrawRows();
		write(STDOUT_FILENO, "\x1b[H", 3);
		read(STDIN_FILENO, &c, 1);
		if (iscntrl(c)) {
			printf("%d\r\n", c);
		} else {
			printf("%d ('%c')\r\n", c, c);
		}
		if (c == CTRL_KEY('q')) break;
  	}

	tcsetattr(0, TCSAFLUSH, termios_p);
	return (0);
}
