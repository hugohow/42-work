#include "terminal.h"


int main()
{
	t_config old_config;
	t_config new_config;
	t_cmd	 *cmd;
	t_cmd	 **cmd_historic;

	ft_terminal_init(&old_config, &new_config);
	ft_terminal_prompt(1, "OK\n");
	cmd_historic = (t_cmd **)malloc(2 * sizeof(t_cmd *));
	cmd_historic[0] = NULL;
	cmd_historic[1] = 0;
	cmd = ft_terminal_cmd_init("Hello");
	ft_putstr("\n----------🍄---------------\n");
	while (ft_terminal_ask(&cmd, cmd_historic) > 0)
		;
	ft_putstr("\n----------🍄---------------\n");
	cmd = ft_terminal_cmd_init("");
	while (ft_terminal_ask(&cmd, cmd_historic) > 0)
		;
	ft_putstr("\n----------🍄---------------\n");
	cmd = ft_terminal_cmd_init("");
	while (ft_terminal_ask(&cmd, cmd_historic) > 0)
		;
	ft_terminal_exit(&old_config);
	return (0);
}