
all:
	gcc -Wall -Wextra -Werror libft/*.a checker_srcs/*.c common/*.c -o checker
	gcc -Wall -Wextra -Werror libft/*.a push_swap_srcs/*.c common/*.c -o push_swap
	./checker 1 2 3 4

clean:
	rm -rf srcs/*.o

fclean: clean
	rm -rf checker push_swap

re: fclean all