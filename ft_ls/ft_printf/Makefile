NAME=libftprintf.a
CC=gcc
CFLAGS=-Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -Isrcs -c srcs/*.c
	ar -x libft.a 
	ar rc $(NAME) *.o
	ranlib $(NAME)
	gcc $(NAME) main.c -o main
	./main

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all
