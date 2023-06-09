/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** command_tools
*/

#include "server.h"

int get_cmd_pos(char *str)
{
    for (int i = 0; GUI_CMD_LIB[i] != NULL; i++) {
        if (strcmp(str, GUI_CMD_LIB[i]) == 0) {
            return i;
        }
    }
    return -1;
}
