
all:
	gcc -Wall -Wextra -Werror libft/*.a srcs/*.c -o minishell
	./minishell

clean:
	rm -rf srcs/*.o

fclean: clean
	rm -rf minishell

re: fclean all