
NAME    := libft.a

INC_DIR := includes
SRC_DIR := srcs
OBJ_DIR := objs

INCLS   := $(INC_DIR)
SRCS    := $(wildcard $(SRC_DIR)/*.c)
OBJS    := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CC      := gcc
CFLAGS  += -Wall -Werror -Wextra -g
LFLAGS  += -I.
AR      := ar rcs
RLIB    := ranlib

C_NO	=	"\033[00m"
C_OK	=	"\033[35m"
C_GOOD	=	"\033[32m"
C_ERROR	=	"\033[31m"
C_WARN	=	"\033[33m"

SUCCESS	=	$(C_GOOD)SUCCESS$(C_NO)
OK		=	$(C_OK)OK$(C_NO)

all:	obj
		@$(MAKE) -j $(NAME)


obj:
		@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJS)
	@ar rc $@ $^
	@ranlib $@
	@echo "Compiling & indexing" [ $(NAME) ] $(SUCCESS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		@$(CC) $(CFLAGS) -c $< -o $@ $(LFLAGS)/$(INCLS)
		@echo "Linking" [ $< ] $(OK)

test:
	@$(CC) $(CFLAGS) -g $(LFLAGS)/$(INCLS) -o test hash_table_tests/test.c hash_table/*.c srcs/*.c
	@echo "Compile" $(OK)
	./test

clean:
	@rm -rf $(OBJS) $(OBJ_DIR)
	@echo "Cleaning" [ $(NAME) ] "..." $(OK)

fclean: clean
	@rm -rf $(NAME) $(LIB_DIR)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re test