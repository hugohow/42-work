#include <termios.h>
#include <stdlib.h>
#include <unistd.h>

int     get_next_line(const int fd, char **line);
int     ft_get_pos(int *y, int *x);
void    ft_exit_terminal(struct termios *orig_termios);
void    ft_putstr(char const *str);
char    *ft_strjoin(char const *str1, char const *str2);
void add_to_stdout(char **p_cmd, int c, int *index);
void delete_n_lines(int n);
int     ft_read_key();
void print_cmd(char *cmd);
size_t  ft_strlen(const char *str);
int count_nb_line(char *cmd);

enum editorKey 
{
  ARROW_LEFT = 1000,
  ARROW_RIGHT,
  ARROW_UP,
  ARROW_DOWN
};

#define CTRL_J 10
#define CTRL_L ('l' & 0x1f)
#define CTRL_I 9
#define CTRL_K ('k' & 0x1f)