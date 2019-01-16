NAME=libft.a
CC=gcc
CFLAGS=-Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -c srcs/*.c srcs2/*.c srcs3/*.c
	ar rc $(NAME) *.o
	
clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all