NAME=minishell

all:
	gcc  -lncurses -Wall -Wextra -Werror libft_g/*/*.c srcs/*.c -o $(NAME)

clean:
	rm -rf srcs/*.o

fclean: clean
	rm -rf $(NAME)

re: fclean all

test:
	bash ~/42ShellTester/42ShellTester.sh /Users/hugohow-choong/42/$(NAME)/$(NAME) --reference "bash" --filter $(NAME) > error | cat
	head -n 100 error