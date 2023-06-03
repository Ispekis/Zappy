##
## EPITECH PROJECT, 2023
## B-YEP-400-PAR-4-1-zappy-vincent.shao
## File description:
## Makefile
##

PATH_TO_ROOT	=	../..

MV	=	mv

SRC	=	src/get_options.c		\
		src/tools.c				\
		src/init.c				\
		src/server.c			\
		src/shutdown.c			\
		src/client_management.c	\
		src/linked_list_utils/team_linked_list.c	\

MAIN_SRC	=	src/main.c

MAIN_OBJ	=	$(MAIN_SRC:.c=.o)

OBJ	=	$(SRC:.c=.o)

NAME	=	zappy_server

TEST_NAME	=	unit_tests

TEST_FILE	=	tests/test_server.c

CPPFLAGS	=	-I./include

CFLAGS	=	-Wall -Wextra

LDFLAGS	=	-luuid

all: $(NAME)

# Add main to obj for real compilation
$(NAME): $(OBJ) $(MAIN_OBJ)
	$(CC) $(OBJ) $(MAIN_OBJ) -o $(PATH_TO_ROOT)/$(NAME) $(LDFLAGS)

tests_run: LDFLAGS += -lcriterion --coverage
tests_run:
	$(CC) $(SRC) $(TEST_FILE) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $(TEST_NAME)
	./${TEST_NAME}
	gcovr --exclude tests/
	gcovr --exclude tests/ --branches

clean:
	$(RM) -f $(MAIN_OBJ)
	$(RM) -f $(OBJ)
	$(RM) *.gcda
	$(RM) *.gcno

fclean: clean
	$(RM) $(PATH_TO_ROOT)/$(NAME)
	$(RM) $(TEST_NAME)

re: fclean all

debug: CPPFLAGS += -g3
debug: re

.PHONY: all tests_run clean fclean re debug
