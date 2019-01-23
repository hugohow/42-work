NAME=ft_ls
CC=gcc
CFLAGS=-Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -o $(NAME) srcs/*.c libft/srcs*/*.c ft_printf/srcs/*.c
	# ./$(NAME) -lR
	# ./ft_ls file1 lib

clean:
	rm -rf srcs/*.o

fclean: clean
	rm -rf $(NAME)

re: fclean all