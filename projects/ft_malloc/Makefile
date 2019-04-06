ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

all:
	gcc -c -Wall -Werror -fpic ft_malloc.c
	gcc -shared -o libft_malloc_$(HOSTTYPE).so ft_malloc.o
	ln -s -f libft_malloc_$(HOSTTYPE).so libft_malloc.so
	gcc -L$(PWD) -Wall -g -o main main.c -lft_malloc
	./main

debug:
	gcc -o main -Wall -Werror -g ft_malloc.c main.c
	./main