#include "ft_termcaps.h"


enum editorKey 
{
  ARROW_LEFT = 1000,
  ARROW_RIGHT,
  ARROW_UP,
  ARROW_DOWN
};


int     my_outc(int c)
{
    write (1, &c, sizeof(c));
    return (0);
}

int go_to(int index, int original_row, int *curr_index)
{
    char *gotostr; 
    int rows;
    int cols;
    
    
    get_window_size(&rows, &cols);

    if (index < 0)
        return (-1);
    *curr_index = index;
    gotostr = tgetstr("cm", NULL);
    tputs(tgoto(gotostr, *curr_index + 3, original_row), 1, my_outc);
    return (0);
}


int clear_character(void)
{
    char *clearstr;

    clearstr = tgetstr("dc", NULL);
     tputs(clearstr, 1, my_outc);
     return (0);
}

int clear_line(int nb)
{
    char *insertstr;

    insertstr = tgetstr("dl", NULL);
    while (nb-- != 0)
        tputs(insertstr, 1, my_outc);
    // ft_putstr("\r");
    // char *tgoto(const char *cap, int col, int row);
    return (0);
}

void print_cmd(char *cmd)
{
    ft_putstr("\r");
    print_bold_green(1);
    ft_putstr("$> ");
    print_normal(1);
    ft_putstr(cmd);
}

void refresh(char *cmd, int *curr_index, int original_row)
{
    clear_line(1);
    print_cmd(cmd);
    go_to(*curr_index, original_row, curr_index);
}


void add_to_stdout(char **p_cmd, int c, int *curr_index, int original_row)
{
    char str[2];

    str[0] = c;
    str[1] = '\0';
    refresh(*p_cmd, curr_index, original_row);
    
    if (c == ARROW_RIGHT)
    {
        if (*curr_index + 1 > (int)ft_strlen(*p_cmd))
            return ;
        go_to(*curr_index + 1, original_row, curr_index);
    }
    else if (c == ARROW_LEFT)
    {
        go_to(*curr_index - 1, original_row, curr_index);
    }
    else if (c == 127)
    {
        if (*curr_index > 0)
        {
        *p_cmd = ft_strjoin(ft_strsub(*p_cmd, 0, *curr_index - 1), 
            *p_cmd + *curr_index);

            *curr_index = *curr_index - 1;
            refresh(*p_cmd, curr_index, original_row);
        }
    }
    else if (ft_isprint(c))
    {

        *p_cmd = ft_strjoin(
            ft_strjoin(ft_strsub(*p_cmd, 0, *curr_index), str), 
            *p_cmd + *curr_index);



        *curr_index = *curr_index + 1;
        refresh(*p_cmd, curr_index, original_row);
    }
    return ;
    // else if (c == -21)
    // {

    // }
    // //     move_to_the_right();
    // else if (c == -22)
    // {

    // }
    //     // move_to_the_right();
    // else if (ft_isprint(c))
    // {
    //     *p_cmd = ft_strjoin(*p_cmd, str);
    // }
    // else
    // {
    //     // ft_putnbr(c);
    // }
}