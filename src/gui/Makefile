##
## EPITECH PROJECT, 2023
## B-YEP-400-PAR-4-1-zappy-vincent.shao
## File description:
## Makefile
##

PATH_TO_ROOT	=	../..

MV	=	mv

SRC	=	src/Parser.cpp	\
		src/Error.cpp	\
		src/Gui.cpp

MAIN_SRC	=	src/main.cpp

MAIN_OBJ	=	$(MAIN_SRC:.cpp=.o)

OBJ	=	$(SRC:.cpp=.o)

NAME	=	zappy_gui

TEST_NAME	=	unit_tests

TEST_FILE	=	tests/test_gui.cpp

CPPFLAGS	=	-I./include

CFLAGS	=	-Wall -Wextra

LDFLAGS	=	

all: $(NAME)

$(NAME): $(OBJ) $(MAIN_OBJ)
	$(CXX) $(OBJ) $(MAIN_OBJ) $(CFLAGS) $(LDFLAGS) -o $(PATH_TO_ROOT)/$(NAME)

tests_run: LDFLAGS += -lcriterion --coverage
tests_run:
	$(CXX) $(SRC) $(TEST_FILE) $(CFLAGS) $(LDFLAGS) -o $(TEST_NAME)
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
