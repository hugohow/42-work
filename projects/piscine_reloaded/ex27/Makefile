# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hhow-cho <hhow-cho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/02 22:56:55 by hhow-cho          #+#    #+#              #
#    Updated: 2019/04/02 22:56:56 by hhow-cho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file

SRC = ft_display_file.c ft_check_param_num.c ft_read_file.c ft_putchar.c ft_putstr.c

FLAGS = -Wall -Werror -Wextra

all:
	gcc -c $(SRC) $(FLAGS)
	gcc -o $(NAME) $(NAME).o ft_check_param_num.o ft_read_file.o ft_putchar.o ft_putstr.o

clean:
	rm -rf $(NAME).o ft_check_param_num.o ft_read_file.o ft_putchar.o ft_putstr.o

fclean: clean
	rm -rf $(NAME)

re: fclean all