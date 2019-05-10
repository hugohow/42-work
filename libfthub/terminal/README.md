```C

int main()
{
	t_config old_config;
	t_config new_config;
	t_cmd	 *cmd;
	t_cmd	 *cmd_historic[1];

	// init the terminal
	ft_terminal_init(&old_config, &new_config);

	// init the command, it can be empty string
	cmd = ft_terminal_cmd_init("Hello");


	ft_terminal_prompt(1, "\n----------🍄---------------\n");
	while (ft_terminal_ask(&cmd, cmd_historic) > 0)
	{
		// see the evolution of cmd, until the user press enter
	}
	// do what you want to do with the cmd
	// execute the command with your shell for example
	ft_terminal_prompt(1, "\n----------🍄---------------\n");
	cmd = ft_terminal_cmd_init("");
	while (ft_terminal_ask(&cmd, cmd_historic) > 0)
		;
	ft_terminal_prompt(1, "\n----------🍄---------------\n");
	cmd = ft_terminal_cmd_init("");
	while (ft_terminal_ask(&cmd, cmd_historic) > 0)
		;

	// exit the terminal
	ft_terminal_exit(&old_config);
	return (0);
}
```
