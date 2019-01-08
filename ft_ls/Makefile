NAME=ft_ls
CC=gcc
CFLAGS=-Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -o $(NAME) srcs/*.c lib/*.a
	./$(NAME) -lR

clean:
	rm -rf srcs/*.o

fclean: clean
	rm -rf $(NAME)

re: fclean all