/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 16:04:52 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/05/09 18:29:10 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMINAL_H
# define TERMINAL_H
# include "libft.h"
#include <curses.h>
#include <term.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <sys/ioctl.h>

enum editorKey 
{
  ARROW_LEFT = 1000,
  ARROW_RIGHT,
  ARROW_UP,
  ARROW_DOWN
};


typedef struct termios t_config;

typedef struct	s_choice
{
	char *str;
	int selected;
}				t_choice;


typedef struct	s_cmd
{
	char *cmd_str;
	int  cursor_index;
	int  last_key;
	t_choice **choices;
}				t_cmd;

int		ft_terminal_init(t_config *old_config, t_config *new_config);
void	ft_terminal_exit(t_config *old_config);
int		ft_terminal_prompt(int fd, const char *str);
t_cmd	*ft_terminal_cmd_init(const char *str);
int		ft_terminal_ask(int fd, t_cmd **p_cmd, t_cmd **cmd_historic);

int		ft_get_window_size(int *rows, int *cols);
int		ft_read_key(void);
#endif