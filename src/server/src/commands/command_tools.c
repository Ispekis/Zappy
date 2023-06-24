/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** command_tools
*/

#include "server.h"

int get_cmd_pos(char *str, const char **lib)
{
    for (int i = 0; lib[i] != NULL; i++) {
        if (strcmp(str, lib[i]) == 0) {
            return i;
        }
    }
    return -1;
}
