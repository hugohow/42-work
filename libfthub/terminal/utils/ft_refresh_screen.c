/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_refresh_screen.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 09:15:38 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/05/15 17:52:08 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

static int     my_outc(int c)
{
    // if (ft_isprint(c) == 1)
    return (write (STDOUT_FILENO, &c, 1));
}


static int go_to_col(int col)
{
    char *gotocol; 
    int rows;
    int cols;

    ft_get_window_size(&rows, &cols);
    gotocol = tgoto(tgetstr("ch", NULL), 1, col);
    tputs(gotocol, 1, my_outc);
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

int ft_get_row(t_cmd **p_cmd)
{
    int row;
    int i;

    i = 0;
    row = 0;
    while (((*p_cmd)->cmd_str)[i] && i != (*p_cmd)->cursor_index)
    {
        if (((*p_cmd)->cmd_str)[i] == '\n')
            row++;
        i++;
    }
    return (row);
}

static int count_nb_line(char *cmd)
{
    int nb_line;
	int i;
	int rows;
	int cols;

    nb_line = 0;
	i = 0;
	ft_get_window_size(&rows, &cols);
    while (*cmd)
    {
		if (i != 0 && i % cols == 0)
		{
			nb_line++;
			i = 0;			
		}
        if (*cmd == '\n')
		{
			nb_line++;
			i = 0;
		}
        cmd++;
		i++;
    }
    return (nb_line);
}

static void delete_n_lines(int n)
{
    int i;

    i = 0;
	tputs(tgetstr("cd", NULL), 1, my_outc);
    while (i < n)
    {
        tputs(tgetstr("up", NULL), 1, my_outc); 
        tputs(tgetstr("cd", NULL), 1, my_outc);
        i++;
    }
    ft_putstr("\r");
}

void ft_refresh_screen(t_cmd **p_cmd)
{
    delete_n_lines(count_nb_line((*p_cmd)->cmd_str));
	if ((*p_cmd)->brackets_closed == 0)
		ft_putstr_fd("\033[32;1m", 1);
	else
		ft_putstr_fd("\033[0m", 1);
    ft_putstr_fd((*p_cmd)->cmd_str, 1);
    go_to_col(ft_get_col(p_cmd));
}