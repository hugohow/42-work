
all:
	gcc -Wall -Wextra -Werror libft_g/srcs/*.c libft_g/srcs2/*.c libft_g/srcs3/*.c libft_g/srcs_get_next_line/*.c libft_g/srcs_printf/*.c srcs/*.c -o minishell

clean:
	rm -rf srcs/*.o

fclean: clean
	rm -rf minishell

re: fclean all

test:
	bash ~/42ShellTester/42ShellTester.sh /Users/hugohow-choong/42/minishell/minishell --reference "bash" --filter "minishell.*env" > error | cat
	head -n 100 error