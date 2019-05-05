#include "ft_termcaps.h"


enum editorKey 
{
  ARROW_LEFT = 1000,
  ARROW_RIGHT,
  ARROW_UP,
  ARROW_DOWN
};

#define CTRL_L ('l' & 0x1f)
#define CTRL_K ('k' & 0x1f)
#define CTRL_H ('h' & 0x1f)
#define CTRL_N ('n' & 0x1f)

int     my_outc(int c)
{
    write (1, &c, sizeof(c));
    return (0);
}

int go_to_col(int col)
{
    char *gotocol; 
    int rows;
    int cols;
    
    get_window_size(&rows, &cols);

    gotocol = tgetstr("ch", NULL);
    tputs(tgoto(gotocol, 1, col), 1, my_outc);
    return (0);
}

int get_col(char *cmd, int index)
{
    int col;
    int i;

    i = 0;
    col = 3;
    while (cmd[i] && i != index)
    {
        col++;
        if (cmd[i] == '\n')
            col = 0;
        i++;
    }
    return (col);
}

int clear_character(void)
{
    char *clearstr;

    clearstr = tgetstr("dc", NULL);
     tputs(clearstr, 1, my_outc);
     return (0);
}

void print_cmd(char *cmd)
{
    print_bold_green(1);
    ft_putstr("$> ");
    print_normal(1);
    ft_putstr(cmd);
}

int count_nb_line(char *cmd)
{
    int nb_line;
    nb_line = 0;
    while (*cmd)
    {
        if (*cmd == '\n')
            nb_line++;
        cmd++;
    }
    return (nb_line);
}

void delete_n_lines(int n)
{
    int i;

    i = 0;
    while (i < n)
    {
        tputs(tgetstr("up", NULL), 1, my_outc); 
        tputs(tgetstr("dl", NULL), 1, my_outc);
        i++;
    }
    tputs(tgetstr("dl", NULL), 1, my_outc);
    ft_putstr("\r");
}

void refresh(char *cmd, int *curr_index)
{
    delete_n_lines(count_nb_line(cmd));
    print_cmd(cmd);
    go_to_col(get_col(cmd, *curr_index));
}


void add_to_stdout(char **p_cmd, int c, int *curr_index)
{
    char str[2];

    str[0] = c;
    str[1] = '\0';

    if (c == 10)
    {
        *p_cmd = ft_strjoin(
            ft_strjoin(ft_strsub(*p_cmd, 0, *curr_index), "\n"), 
            *p_cmd + *curr_index);
        *curr_index = *curr_index + 1;
        delete_n_lines(count_nb_line(*p_cmd) - 1);
        print_cmd(*p_cmd);
        go_to_col(get_col(*p_cmd, *curr_index));
    }
    else if (c == CTRL_L)
    {
        go_to_col(0);
    }
    else if (c == CTRL_K)
    {
        go_to_col(0);
    }
    else if (c == CTRL_H)
    {
        go_to_col(0);
    }
    else if (c == CTRL_N)
    {
        go_to_col(0);
    }
    else if (c == ARROW_RIGHT)
    {
        if (*curr_index + 1 > (int)ft_strlen(*p_cmd))
            return ;
        *curr_index = *curr_index + 1;
        go_to_col(get_col(*p_cmd, *curr_index));
    }
    else if (c == ARROW_LEFT)
    {
        if (*curr_index == 0)
            return ;
        if (get_col(*p_cmd, *curr_index) == 0)
            return ;
        *curr_index = *curr_index - 1;
        go_to_col(get_col(*p_cmd, *curr_index));
    }
    else if (c == ARROW_DOWN || c == ARROW_UP)
    {
        if (count_nb_line(*p_cmd) > 0)
            print_cmd(*p_cmd);
        refresh(*p_cmd, curr_index);
    }
    else if (c == 127)
    {
        if (*curr_index == 0)
            return ;
        if (get_col(*p_cmd, *curr_index) == 0)
            return ;
        refresh(*p_cmd, curr_index);
        if (*curr_index > 0)
        {
        *p_cmd = ft_strjoin(ft_strsub(*p_cmd, 0, *curr_index - 1), 
            *p_cmd + *curr_index);

            *curr_index = *curr_index - 1;
            refresh(*p_cmd, curr_index);
        }
    }
    else if (ft_isprint(c))
    {
        *p_cmd = ft_strjoin(
            ft_strjoin(ft_strsub(*p_cmd, 0, *curr_index), str), 
            *p_cmd + *curr_index);
        *curr_index = *curr_index + 1;
        refresh(*p_cmd, curr_index);
    }
    return ;
}