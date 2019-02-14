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

void print_cmd(char *cmd)
{
    // ft_putstr("----------🍄---------------\n");
    print_bold_green(1);
    ft_putstr("$> ");
    print_normal(1);
    ft_putstr(cmd);
}

void refresh(char *cmd, int *curr_index, int original_row, int nb_line)
{

    // if (nb_line > 1)
    // {
    //     tputs(tgetstr("do", NULL), 1, my_outc);   
    //     clear_line(nb_line);
    //     tputs(tgetstr("up", NULL), 1, my_outc);   
    //     clear_line(nb_line);
    // }
    // else
    // {

        
    // }
    if (cmd && original_row && curr_index && nb_line)
    {

    }
    if (nb_line == 0)
    {
        ft_putstr("\r");
        tputs(tgetstr("ce", NULL), 1, my_outc);   
        print_cmd(cmd);
        go_to(*curr_index, original_row, curr_index);
    }
    else
    {
        // 0 -> il faut supprimer 1 


        // 1 -> il faut monter et supprimer

        // 2 -> il faut monter 1 fois, supprimer, puis monter une fois et supprimer

        // 3 -> 

        int i = 0;

        while (i < nb_line)
        {
            tputs(tgetstr("up", NULL), 1, my_outc); 
            tputs(tgetstr("dl", NULL), 1, my_outc);
            i++;
        }




        // tputs(tgetstr("dl", NULL), 1, my_outc);
        // int i = 0;
        // while ( i < nb_line - 1)
        // {
        //     tputs(tgetstr("up", NULL), 1, my_outc); 
        //     tputs(tgetstr("dl", NULL), 1, my_outc);
        //     i++;
        // }
        
        ft_putstr("\r");
        print_cmd(cmd);
        // int i = 1;
        // while ( i < nb_line )
        // {
        //     tputs(tgetstr("sr", NULL), 1, my_outc); 
        //     tputs(tgetstr("dl", NULL), 1, my_outc);
        //     i++;
        // }
        // print_cmd(cmd);
        // ft_putstr("\r");
        // // mais il faut aussi effacer
        // tputs(tgetstr("dl", NULL), 1, my_outc);  
        // tputs(tgetstr("up", NULL), 1, my_outc);  
        // ft_putstr("\r");
        // // mais il faut aussi effacer
        // tputs(tgetstr("dl", NULL), 1, my_outc);  

        // tputs(tgoto(tgetstr("cm", NULL), 0, original_row), 1, my_outc);


        // ft_putstr("\r");
        // print_cmd(cmd);
        // go_to(*curr_index, original_row, curr_index);
        // go_to(*curr_index, original_row, curr_index);
    }
    // up the the line
    // tputs(tgoto( tgetstr("cm", NULL), *curr_index + 3, original_row - 1), 1, my_outc);
    // then print
}


void add_to_stdout(char **p_cmd, int c, int *curr_index, int original_row, int nb_line)
{
    char str[2];

    str[0] = c;
    str[1] = '\0';

    if (c == 10)
    {
        *p_cmd = ft_strjoin(
            ft_strjoin(ft_strsub(*p_cmd, 0, *curr_index), "\n"), 
            *p_cmd + *curr_index);
        // important sinon il y aura un décallage bizarre
        *curr_index = *curr_index + 1;
        // char *sf;
        // sf = tgetstr("sf", NULL);
        tputs(tgetstr("dl", NULL), 1, my_outc);
        // tputs(tgetstr("sf", NULL), 1, my_outc); 
        int i = 1;
        while ( i < nb_line)
        {
            tputs(tgetstr("up", NULL), 1, my_outc); 
            tputs(tgetstr("dl", NULL), 1, my_outc);
            i++;
        }
        ft_putstr("\r");
        print_cmd(*p_cmd);
        return ;
        // go_to(*curr_index + 1, original_row + 1, curr_index);
    }
    else if (c == ARROW_RIGHT)
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
        refresh(*p_cmd, curr_index, original_row, nb_line);
        if (*curr_index > 0)
        {
        *p_cmd = ft_strjoin(ft_strsub(*p_cmd, 0, *curr_index - 1), 
            *p_cmd + *curr_index);

            *curr_index = *curr_index - 1;
            refresh(*p_cmd, curr_index, original_row, nb_line);
        }
    }
    else if (ft_isprint(c))
    {
        
        *p_cmd = ft_strjoin(
            ft_strjoin(ft_strsub(*p_cmd, 0, *curr_index), str), 
            *p_cmd + *curr_index);



        *curr_index = *curr_index + 1;
        refresh(*p_cmd, curr_index, original_row, nb_line);
    }
    return ;
}