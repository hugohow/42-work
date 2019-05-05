# 42 termcaps

Termcaps utilies for 42 students

Inspired by https://github.com/SBoudrias/Inquirer.js/

# Methods

ft_terminal_init()

ft_terminal_prompt(char *str)

int ft_terminal_ask(char **line, int step, t_choice **choices) -> return response (behave like get next line)

0 -> over
-1 -> error
bytes sizes

t_choice **ft_terminal_question(t_choice **choices)

t_choice
{
name
value
}


void ft_terminal_exit()


