NAME=libft.a
CC=gcc
CFLAGS=-Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -c srcs/*.c
	ar rc $(NAME) *.o
	$(CC) test.c -o test libft.a
	./test
clean:
	rm -rf *.o
	rm -rf test

fclean: clean
	rm -rf $(NAME)

re: fclean all