NAME=libftprintf.a
CC=gcc
CFLAGS=-Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -Iincludes -g -c srcs/*.c libft/*.c srcs/flag/*.c
	ar rc $(NAME) *.o
	ranlib $(NAME)
	rm -rf *.o
	gcc -g $(NAME) main.c -o main
	./main

test: re
	cp -f $(NAME) ./tests
	cd tests && $(MAKE)
	./tests/ft_printf_tests

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all
