/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_terminal_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 16:03:47 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/05/09 16:19:18 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

int ft_terminal_init(t_config *old_config, t_config *new_config)
{
    char *term_name;
    int ret;

    if ((term_name = getenv("TERM")) == NULL)
        return (-1);

	ret = tgetent(NULL, term_name);
    if (ret == -1)
    {
        ft_putstr_fd("Could not access to the termcap database..\n", STDERR_FILENO);
        return (-1);
    }
    else if (ret == 0)
    {
        ft_putstr_fd("Terminal type '%s' is not defined in termcap database (or have too few informations).\n", STDERR_FILENO);
		ft_putstr_fd(term_name, STDERR_FILENO);
        return (-1);
    }
	tcgetattr(STDIN_FILENO, old_config);
	*new_config = *old_config;
	// new_config->c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
	// new_config->c_oflag &= ~(OPOST);
	// new_config->c_cflag |= (CS8);
	// new_config->c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
    new_config->c_lflag &= ~(ICANON | ECHO);
	new_config->c_lflag |= ISIG;
    new_config->c_cc[VMIN] = 1;
	new_config->c_cc[VTIME] = 1;
  	tcsetattr(0, TCSAFLUSH, new_config);
    return (0);
}