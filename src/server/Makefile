##
## EPITECH PROJECT, 2023
## B-YEP-400-PAR-4-1-zappy-vincent.shao
## File description:
## Makefile
##

PATH_TO_ROOT	=	../..

MV	=	mv

SRC	=	src/tools.c									\
		src/server.c								\
		src/shutdown.c								\
		src/client_management.c						\
		src/linked_list_utils/client_linked_list.c	\
		src/read_client.c							\
		src/option/get_options.c					\
		src/option/set_options.c					\
		src/init/init_server.c						\
		src/init/init_game.c						\
		src/init/init.c								\
		src/init/init_commands.c					\
		src/memory_handling/global_free.c			\
		src/memory_handling/free_server.c			\
		src/memory_handling/free_game.c				\
		src/commands/ai_first_connect.c				\
		src/commands/ai_communication.c				\
		src/commands/graphic_first_connect.c		\
		src/commands/graphic_communication.c		\
		src/commands/map_recv.c						\
		src/commands/player_recv.c					\
		src/commands/time_recv.c					\
		src/commands/command_tools.c				\

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
