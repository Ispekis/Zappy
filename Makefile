##
## EPITECH PROJECT, 2023
## B-YEP-400-PAR-4-1-zappy-vincent.shao
## File description:
## Makefile
##

SERVER_PATH	=	src/server

GUI_PATH	=	src/gui

IA_PATH		=	src/ai

all: server gui ia

server:
	$(MAKE) -C $(SERVER_PATH)

gui:
	$(MAKE) -C $(GUI_PATH)

ia:
	$(MAKE) -C $(IA_PATH)

tests_run:
	$(MAKE) tests_run -C $(SERVER_PATH)
	$(MAKE) tests_run -C $(GUI_PATH)
	$(MAKE) tests_run -C $(IA_PATH)

clean:
	$(MAKE) clean -C $(SERVER_PATH)
	$(MAKE) clean -C $(GUI_PATH)
	$(MAKE) clean -C $(IA_PATH)

fclean:
	$(MAKE) fclean -C $(SERVER_PATH)
	$(MAKE) fclean -C $(GUI_PATH)
	$(MAKE) fclean -C $(IA_PATH)

re:
	$(MAKE) re -C $(SERVER_PATH)
	$(MAKE) re -C $(GUI_PATH)
	$(MAKE) re -C $(IA_PATH)

debug:
	$(MAKE) debug -C $(SERVER_PATH)
	$(MAKE) debug -C $(GUI_PATH)
	$(MAKE) debug -C $(IA_PATH)

.PHONY: all tests_run clean fclean re debug
