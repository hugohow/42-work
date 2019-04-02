.PHONY: all test clean test
NAME=21sh

all:
	gcc  -lncurses -Wall -Wextra -Werror libft_g/*/*.c srcs/*.c srcs/$(NAME)/*.c -o $(NAME)

clean:
	rm -rf srcs/*.o

fclean: clean
	rm -rf $(NAME)

re: fclean all

test:
	bash ~/42ShellTester/42ShellTester.sh /Users/hugohow-choong/42/minishell_21sh_42sh/$(NAME) --reference "bash" --filter $(NAME) > error | cat
	cat error | less