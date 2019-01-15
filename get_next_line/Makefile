
all:
	gcc -Wall -Wextra -Werror -Isrcs -c get_next_line.c
	ar rc get_next_line.a *.o
	ranlib get_next_line.a
	gcc get_next_line.a libft.a main.c -o main
	./main

clean: 


fclean: 

re: fclean all