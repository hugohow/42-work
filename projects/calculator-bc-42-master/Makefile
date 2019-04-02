NAME = eval_expr
SRC_DIR = srcs
INPUTS = $(SRC_DIR)/eval_expr.c  $(SRC_DIR)/ft_init.c  $(SRC_DIR)/ft_putnbr.c  $(SRC_DIR)/ft_strcut.c \
$(SRC_DIR)/main.c $(SRC_DIR)/ft_atoi.c  $(SRC_DIR)/ft_putchar.c  $(SRC_DIR)/ft_putstr.c  $(SRC_DIR)/ft_validation.c
OUTPUTS = eval_expr.o ft_init.o  ft_putnbr.o  ft_strcut.o  \
main.o ft_atoi.o  ft_putchar.o  ft_putstr.o  ft_validation.o
CC=gcc
CFLAGS=-Wall -Wextra -Werror -Iincludes

all:  $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -c $(INPUTS)
	$(CC) -o $(NAME) $(CFLAGS) $(OUTPUTS)

clean:
	/bin/rm -f $(OUTPUTS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all