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


typedef struct s_arg {
	char *arg;
	int selected;
}				t_arg;


struct editorConfig {
  int cx;
  int cy;
  int index;
  int nb_row;
  int nb_col;
  t_arg **argv;
  int argc;
  int 	screenrows;
  int 	screencols;
  struct termios orig_termios;
  int line;
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

void initEditor(int argc, char **argv) {
	t_arg **list_t_arg;
	t_arg *arg;
	int i;
	int k;

	i = 0;
	k = 0;
	list_t_arg = malloc(argc * sizeof(t_arg *));
	while (argv[i])
	{
		arg = malloc(sizeof(t_arg));
		arg->arg = argv[i];
		arg->selected = 0;
		list_t_arg[k] = arg;
		k++;
		i++;
	}
	E.cx = 0;
	E.cy = 0;
	E.index = 0;
	E.argv = list_t_arg;
	E.argc = argc;
	E.line = 0;
	if (getWindowSize(&E.screenrows, &E.screencols) == -1)
	{
		return ;
	}
}

void print_arg(t_arg *arg)
{
	fputs(tgetstr("us", NULL), stdout);
	printf("%-20s", arg->arg);
	fputs(tgetstr("me", NULL), stdout);
}

void print_argv(int argc, t_arg **list_t_arg)
{
	int i;

	if (argc > E.screencols/20)
		E.nb_col = E.screencols/40;
	else
		E.nb_col = E.screencols/20;
	E.nb_row = (argc - 1)/E.nb_col;
	E.cy = E.index / E.nb_col;
	E.cx = E.index % E.nb_col;
	
	
	i = 0;
	while (i < argc - 2)
	{
		if (i % E.nb_col == 0)
		{
			printf("\r\n");
			E.line++;
		}
		if (list_t_arg[i]->selected == 1)
		{
			fputs(tgetstr("mr", NULL), stdout);
		}
		if (i == E.index)
		{
			fputs(tgetstr("us", NULL), stdout);
		}
		printf("%-20s", list_t_arg[i]->arg);
		fputs(tgetstr("me", NULL), stdout);
		i++;
	}
	printf("\r\n");
}

void clean(void)
{
	int i;

	i = 0;
	while (i < E.line + 1)
	{
		printf("\033[K");
		printf("\033[A");
		i++;
	}
}

void editorRefreshScreen(int argc, t_arg **list_t_arg) {
	
	
	clean();


	E.line = 0;
	print_argv(argc, list_t_arg);
}

void exit_select()
{
	printf("\033[u");
	ft_exit_terminal(&E.orig_termios);
}


void editor_move_cursor(int key) {
	int index;

	if (key == ARROW_LEFT)
	{
		index = E.cy * E.nb_col + (E.cx - 1);
		if (index >= 0)
		{
			E.cx--;
			E.index = E.cy * E.nb_col + E.cx;
		}
	}
	if (key == ARROW_RIGHT)
	{
		index = E.cy * E.nb_col + (E.cx + 1);
		if (index < E.argc - 2)
		{
			E.cx++;
			E.index = E.cy * E.nb_col + E.cx;
		}
	}
	if (key == ARROW_UP)
	{
		index = (E.cy - 1) * E.nb_col + E.cx;
		if (index >= 0)
		{
			E.cy--;
			E.index = E.cy * E.nb_col + E.cx;
		}
	}
	if (key == ARROW_DOWN)
	{
		index = (E.cy + 1) * E.nb_col + E.cx;
		if (index < E.argc - 2)
		{
			E.cy++;
			E.index = E.cy * E.nb_col + E.cx;
		}
	}

}

void delete_element_list()
{
	int i;

	i = E.index;
	while (E.argv[i + 1])
	{
		E.argv[i] = E.argv[i + 1];
		i++;
	}
	E.argc--;
	editor_move_cursor(ARROW_LEFT);
	// editorRefreshScreen(E.argc, E.argv);
}

void select_element_list()
{
	E.argv[E.index]->selected = E.argv[E.index]->selected ? 0 : 1;
	editor_move_cursor(ARROW_RIGHT);
}

void editorProcessKeypress() {
	char *ap;
	char *standstr;
  int c = ft_read_key();
  switch (c) {
	case 27:
	case 10:
    case CTRL_KEY('z'):
      exit_select();
      break;

    case ARROW_UP:
    case ARROW_DOWN:
    case ARROW_LEFT:
    case ARROW_RIGHT:
		editor_move_cursor(c);
		break;
    case 8:
    case 127:
		delete_element_list();
		break;
    case 32:
		select_element_list();
		break;
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
		if (getWindowSize(&E.screenrows, &E.screencols) == -1)
			return ;
		editorRefreshScreen(E.argc, E.argv);
	}
}


int getWindowSize(int *rows, int *cols) {
  struct winsize ws;
  if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == -1 || ws.ws_col == 0) 
	return -1;
  else 
  {
    *cols = ws.ws_col;
    *rows = ws.ws_row;
    return 0;
  }
}


int main(int argc, char **argv)
{
	int i;
	char buf[1];
	
	struct termios orig_termios;
	struct termios new_termios;

	i = 1;
	if (argc < 2)
		return (0);
    if (signal(SIGWINCH, sig_handler) == SIG_ERR)
        printf("\ncan't catch SIGWINCH\n");

	ft_init_terminal(&E.orig_termios, &new_termios);

	argc++;
	argv++;
	initEditor(argc, argv);
	while (1)
	{
		editorRefreshScreen(E.argc, E.argv);
		editorProcessKeypress();
	}
	return (0);
}
