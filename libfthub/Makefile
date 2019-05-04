
NAME    := libft.a
TEST_BIN	:= test

INC_DIR := includes
SRC_DIR := core
OBJ_DIR := objs

CORE_TEST_DIR	:= core_tests
HT_DIR	:= hash_table
HT_TEST_DIR	:= hash_table_tests
BIGINT_DIR	:= bigint
BIGINT_TEST_DIR	:= bigint_tests

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

test: re
	@$(CC) $(CFLAGS) -g $(LFLAGS)/$(INCLS) -o $(TEST_BIN) $(BIGINT_TEST_DIR)/*.c $(BIGINT_DIR)/*.c $(OBJS)
	@echo "Compile" $(OK)
	@echo "Launch tests" $(BIGINT_DIR)
	@./$(TEST_BIN)
	@$(CC) $(CFLAGS) -g $(LFLAGS)/$(INCLS) -o $(TEST_BIN) $(CORE_TEST_DIR)/test.c $(OBJS)
	@echo "Compile" $(OK)
	@echo "Launch tests test.c"
	@./$(TEST_BIN)
	@$(CC) $(CFLAGS) -g $(LFLAGS)/$(INCLS) -o $(TEST_BIN) $(CORE_TEST_DIR)/test_added.c $(OBJS)
	@echo "Compile" $(OK)
	@echo "Launch tests test_added.c"
	@./$(TEST_BIN)
	@$(CC) $(CFLAGS) -g $(LFLAGS)/$(INCLS) -o $(TEST_BIN) $(HT_TEST_DIR)/*.c $(HT_DIR)/*.c $(OBJS)
	@echo "Compile" $(OK)
	@echo "Launch tests" $(HT_DIR)
	@./$(TEST_BIN)
	make fclean

clean:
	@rm -rf $(OBJS) $(OBJ_DIR) $(TEST_BIN)
	@echo "Cleaning" [ $(NAME) ] "..." $(OK)

fclean: clean
	@rm -rf $(NAME) $(LIB_DIR) test.dSYM
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re test