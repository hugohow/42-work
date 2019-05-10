/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_refresh_screen.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 09:15:38 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/05/10 09:46:22 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

static int     my_outc(int c)
{
    write (1, &c, sizeof(c));
    return (0);
}


static int go_to_col(int col)
{
    char *gotocol; 
    int rows;
    int cols;
    
    ft_get_window_size(&rows, &cols);

    gotocol = tgetstr("ch", NULL);
    tputs(tgoto(gotocol, 1, col), 1, my_outc);
    return (0);
}

int ft_get_col(t_cmd **p_cmd)
{
    int col;
    int i;

    i = 0;
    col = 0;
    while (((*p_cmd)->cmd_str)[i] && i != (*p_cmd)->cursor_index)
    {
        col++;
        if (((*p_cmd)->cmd_str)[i] == '\n')
            col = 0;
        i++;
    }
    return (col);
}

static int count_nb_line(char *cmd)
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

static void delete_n_lines(int n)
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

void ft_refresh_screen(t_cmd **p_cmd)
{
    delete_n_lines(count_nb_line((*p_cmd)->cmd_str));
    ft_putstr_fd((*p_cmd)->cmd_str, 1);
    go_to_col(ft_get_col(p_cmd));
}