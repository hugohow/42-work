/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 16:04:52 by hhow-cho          #+#    #+#             */
/*   Updated: 2019/05/13 22:37:08 by hhow-cho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMINAL_H
# define TERMINAL_H
# include "libft.h"
# include "stack.h"
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
	int	brackets_closed;
	int	search_mode;
	int search_index;
	t_choice **choices;
}				t_cmd;

int		ft_terminal_init(t_config *old_config, t_config *new_config);
void	ft_terminal_exit(t_config *old_config);
int		ft_terminal_prompt(int fd, const char *str);
t_cmd	*ft_terminal_cmd_init(const char *str);
int		ft_terminal_ask(t_cmd **p_cmd, t_list **p_stack);
int		ft_terminal_ask_historic(t_cmd **p_cmd, t_list **p_stack);
void	ft_refresh_screen(t_cmd **p_cmd);
int		ft_get_col(t_cmd **p_cmd);
int		ft_get_row(t_cmd **p_cmd);
int		ft_get_window_size(int *rows, int *cols);
int		ft_read_key(void);


int	ft_press_printable_char(t_cmd **p_cmd, t_list **p_stack);
int	ft_press_enter(t_cmd **p_cmd, t_list **p_stack);
int	ft_press_back(t_cmd **p_cmd, t_list **p_stack);
int	ft_press_tab(t_cmd **p_cmd, t_list **p_stack);
int 	ft_press_arrow_left(t_cmd **p_cmd, t_list **p_stack);
int 	ft_press_arrow_right(t_cmd **p_cmd, t_list **p_stack);
int 	ft_press_arrow_up(t_cmd **p_cmd, t_list **p_stack);
int 	ft_press_arrow_down(t_cmd **p_cmd, t_list **p_stack);
typedef int			(t_ft_press)(t_cmd **, t_list **);

typedef struct	s_ft_press_key
{
	int			key;
	t_ft_press 	*ft;
}				t_ft_press_key;

#endif