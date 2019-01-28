#include "ft_select.h"
#define BAUDRATE B38400
#define MODEMDEVICE "/dev/ttyS1"
#define _POSIX_SOURCE 1 /* code source conforme à POSIX */
#define FALSE 0
#define TRUE 1
#define CTRL_KEY(k) ((k) & 0x1f)
#include <sys/ioctl.h>

int 	getWindowSize(int *rows, int *cols);
int 	iscntrl(int c);

struct editorConfig {
  int 	screenrows;
  int 	screencols;
  struct termios orig_termios;
};
struct editorConfig E;


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
  for (y = 0; y < E.screenrows; y++) {
    write(STDOUT_FILENO, "~\r\n", 3);
  }
}

void initEditor() {
  if (getWindowSize(&E.screenrows, &E.screencols) == -1)
  {
	  return ;
  }
}

char editorReadKey() {
  int nread;
  char c;
  while ((nread = read(STDIN_FILENO, &c, 1)) != 1) {
    if (nread == -1){
		return 0;
	};
  }
  return c;
}

void editorRefreshScreen() {
  write(STDOUT_FILENO, "\x1b[2J", 4);
  write(STDOUT_FILENO, "\x1b[H", 3);

  editorDrawRows();
  write(STDOUT_FILENO, "\x1b[H", 3);
}


/*** input ***/
void editorProcessKeypress() {
	char buf[1024];
	char *ap;
	char *standstr;
  char c = editorReadKey();
  switch (c) {
    case CTRL_KEY('q'):
      write(STDOUT_FILENO, "\x1b[2J", 4);
      write(STDOUT_FILENO, "\x1b[H", 3);
      exit(0);
      break;
  }
  if (c == 'j')
  {
	  editorRefreshScreen();
  }
	tgetent(buf, getenv("TERM"));
	if (iscntrl(c)) {
		standstr = tgetstr("so", &ap);
		fputs(standstr, stdout);
		printf("%d\r\n", c);
	} else {
		standstr = tgetstr("se", &ap);
		fputs(standstr, stdout);
		printf("%d ('%c')\r\n", c, c);
	}
}


int getWindowSize(int *rows, int *cols) {
  struct winsize ws;
  if (1 || ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == -1 || ws.ws_col == 0) {
	return -1;
  } else {
    *cols = ws.ws_col;
    *rows = ws.ws_row;
    return 0;
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
	initEditor();
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
	tcgetattr(STDIN_FILENO, &E.orig_termios);

	struct termios raw = E.orig_termios;
//   tcgetattr(0, termios_p);
	raw.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
	raw.c_oflag &= ~(OPOST);
	raw.c_cflag |= (CS8);
	raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
	raw.c_cc[VMIN] = 1;
	raw.c_cc[VTIME] = 1;
	
  tcsetattr(0, TCSAFLUSH, &raw);


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

	while (1) {
		// editorRefreshScreen();
		editorProcessKeypress();
	}


 	//  while (1) {
	// 	char c = '\0';
	// 	read(STDIN_FILENO, &c, 1);
	// 	if (iscntrl(c)) {
	// 		printf("%d\r\n", c);
	// 	} else {
	// 		printf("%d ('%c')\r\n", c, c);
	// 	}
	// 	if (c == 'j')
	// 	{
	// 		// clear
	// 		write(STDOUT_FILENO, "\x1b[2J", 4);
	// 		// positioning to the center
  	// 		write(STDOUT_FILENO, "\x1b[H", 3);

  	// 		editorDrawRows();
  	// 		write(STDOUT_FILENO, "\x1b[H", 3);
	// 	}
	// 	if (c == 'a')
	// 	{
	// 		// mettre le curseur en bas à droite
	// 		write(STDOUT_FILENO, "\x1b[999C\x1b[999B", 12);
	// 	}
	// 	if (c == CTRL_KEY('q')) break;
  	// }

	tcsetattr(0, TCSAFLUSH, &E.orig_termios);
	return (0);
}
