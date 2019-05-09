#include "terminal.h"


int main()
{
	t_config old_config;
	t_config new_config;
	t_cmd	 *cmd;
	t_cmd	 **cmd_list;

	ft_terminal_init(&old_config, &new_config);
	ft_terminal_prompt(1, "OK\n");
	ft_terminal_prompt(1, "OK\n");
	ft_terminal_prompt(1, "OK\n");
	ft_terminal_prompt(1, "OK\n");
	ft_terminal_prompt(1, "OK\n");

	cmd_list = (t_cmd **)malloc(2 * sizeof(t_cmd *));
	cmd_list[0] = NULL;
	cmd_list[1] = 0;
	cmd = ft_terminal_cmd_init("Hello");
	while (42)
	{
		ft_terminal_ask(1, &cmd, cmd_list);
		ft_putstr_fd("\n", fd);
	}
	ft_terminal_exit(&old_config);
	return (0);
}