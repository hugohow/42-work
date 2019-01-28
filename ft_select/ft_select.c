#include "ft_select.h"
#define BAUDRATE B38400
#define MODEMDEVICE "/dev/ttyS1"
#define _POSIX_SOURCE 1 /* code source conforme à POSIX */
#define FALSE 0
#define TRUE 1
#define CTRL_KEY(k) ((k) & 0x1f)
#include <sys/ioctl.h>
#include <signal.h>

int 	getWindowSize(int *rows, int *cols);
int 	iscntrl(int c);

struct editorConfig {
  int cx;
  int cy;
  int 	screenrows;
  int 	screencols;
  struct termios orig_termios;
};
struct editorConfig E;



enum editorKey {
  ARROW_LEFT = 1000,
  ARROW_RIGHT,
  ARROW_UP,
  ARROW_DOWN
};


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

void initEditor() {
  E.cx = 0;
  E.cy = 0;
  if (getWindowSize(&E.screenrows, &E.screencols) == -1)
  {
	  return ;
  }
}

int editorReadKey() {
  int nread;
  char c;
  while ((nread = read(STDIN_FILENO, &c, 1)) != 1) {
    if (nread == -1){
		return 0;
	};
  }
  if (c == '\x1b') {
    char seq[3];
    if (read(STDIN_FILENO, &seq[0], 1) != 1) return '\x1b';
    if (read(STDIN_FILENO, &seq[1], 1) != 1) return '\x1b';
    if (seq[0] == '[') {
      switch (seq[1]) {
        case 'A': return ARROW_UP;
        case 'B': return ARROW_DOWN;
        case 'C': return ARROW_RIGHT;
        case 'D': return ARROW_LEFT;
      }
    }
    return '\x1b';
  } else {
    return c;
  }
}

void print_selected(char *str)
{
	ft_putstr("selected : ");
	ft_putstr(str);
}

void print_over(char *str)
{
	fputs(tgetstr("us", NULL), stdout);
	printf("%-20s", str);
	fputs(tgetstr("me", NULL), stdout);
}

void print_argv(char **argv)
{
	int i;

	i = 1;
	while (argv[i])
	{
		if (i == E.cx)
			print_over(argv[i]);
		else
			printf("%-20s", argv[i]);
		
		i++;
	}
	printf("\r\nE.cx : %d\r\n", E.cx);
	printf("\r\nE.cy : %d\r\n", E.cy);
	printf("\r\nE.screenrows : %d\r\n", E.screenrows);
	printf("\r\nE.screencols : %d\r\n", E.screencols);
}

void editorRefreshScreen(char **argv) {
//   write(STDOUT_FILENO, "\x1b[2J", 4);
//   write(STDOUT_FILENO, "\x1b[H", 3);
//   write(STDOUT_FILENO, "\x1b[H", 3);
	print_argv(argv);
}

void exit_select()
{
	write(STDOUT_FILENO, "\x1b[2J", 4);
	write(STDOUT_FILENO, "\x1b[H", 3);
	tcsetattr(0, TCSAFLUSH, &E.orig_termios);
	exit(0);
}

void editorMoveCursor(int key) {
  switch (key) {
    case ARROW_LEFT:
      E.cx--;
      break;
    case ARROW_RIGHT:
      E.cx++;
      break;
    case ARROW_UP:
      E.cy--;
      break;
    case ARROW_DOWN:
      E.cy++;
      break;
  }
}


/*** input ***/
void editorProcessKeypress() {
	char *ap;
	char *standstr;
  int c = editorReadKey();
  switch (c) {
    case CTRL_KEY('z'):
      exit_select();
      break;

    case ARROW_UP:
    case ARROW_DOWN:
    case ARROW_LEFT:
    case ARROW_RIGHT:
		editorMoveCursor(c);
		break;
	// case 'j':
	// 	editorRefreshScreen();
	// default:
	// {
	// 	if (iscntrl(c)) {
	// 		standstr = tgetstr("so", &ap);
	// 		fputs(standstr, stdout);
	// 		printf("%d\r\n", c);
	// 	} else {
	// 		standstr = tgetstr("se", &ap);
	// 		fputs(standstr, stdout);
	// 		printf("%d ('%c')\r\n", c, c);
	// 	}
	// 	}
	}
}


void sig_handler(int signo)
{
    if (signo == SIGWINCH)
	{
		printf("received SIGWINCH\n");
		if (getWindowSize(&E.screenrows, &E.screencols) == -1)
		{
			return ;
		}
	}
}


int getWindowSize(int *rows, int *cols) {
  struct winsize ws;
  if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == -1 || ws.ws_col == 0) {
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
    if (signal(SIGWINCH, sig_handler) == SIG_ERR)
        printf("\ncan't catch SIGWINCH\n");

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


	stop = 0;

	c = 0;

	while (1) {
		editorRefreshScreen(argv);
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

	return (0);
}
