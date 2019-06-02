/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 22:15:01 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/06/02 21:58:02 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

static int     my_outc(int c)
{
    return (write (STDIN_FILENO, &c, 1));
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
	tputs(tgetstr("dl", NULL), 1, my_outc);
    while (i < n)
    {
        tputs(tgetstr("up", NULL), 1, my_outc); 
        tputs(tgetstr("dl", NULL), 1, my_outc);
        i++;
    }
    ft_putstr("\r");
}

void ft_clear_cmd(t_cmd **p_cmd)
{
	delete_n_lines(count_nb_line((*p_cmd)->cmd_str));
}
