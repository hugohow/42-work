/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 22:15:01 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/05/15 23:49:53 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

static int     my_outc(int c)
{
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

// static int go_to_row_from_bottom(int nb_row)
// {
//     int rows;
//     int cols;

//     ft_get_window_size(&rows, &cols);
// 	while (nb_row > 0)
// 	{
// 		tputs(tgetstr("up", NULL), 1, my_outc); 
// 		nb_row--;
// 	}

//     return (0);
// }

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

int ft_get_row_from_bottom(t_cmd **p_cmd)
{
    int row_total;
	int row;
    int i;

    i = 0;
    row_total = 0;
    while (((*p_cmd)->cmd_str)[i])
    {
        if (((*p_cmd)->cmd_str)[i] == '\n')
            row_total++;
        i++;
    }
	i = 0;
	row = 0;
    while (((*p_cmd)->cmd_str)[i] && i != (*p_cmd)->cursor_index)
    {
        if (((*p_cmd)->cmd_str)[i] == '\n')
            row++;
        i++;
    }
    return (row_total - row);
}


void ft_print_cmd(t_cmd **p_cmd)
{
	if ((*p_cmd)->brackets_closed == 0)
		ft_putstr_fd("\033[32;1m", 1);
	else
		ft_putstr_fd("\033[0m", 1);
    ft_putstr_fd((*p_cmd)->cmd_str, 1);
    go_to_col(ft_get_col(p_cmd));
	// go_to_row_from_bottom(ft_get_row_from_bottom(p_cmd));
}
