NAME=libft.a
CC=gcc
CFLAGS=-Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -c srcs/*.c srcs2/*.c
	ar rc $(NAME) *.o
	$(CC) test_part2.c -o test_part2 libft.a
	./test_part2
	rm -rf *.o
clean:
	rm -rf *.o
	rm -rf test_part2

fclean: clean
	rm -rf $(NAME)

re: fclean all