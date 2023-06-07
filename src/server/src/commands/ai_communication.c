/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** ai_communication
*/

#include "server.h"
#include "macro.h"
#include "game_macro.h"

int do_ai_communication(char *buffer, int index, data_t *data, info_t info)
{
    if (!data->clients[index].is_conn)
        if (do_ai_first_connect(buffer, index, data, info) == SUCCESS)
            return SUCCESS;
    printf("From team\n");
    return FAILURE;
}
